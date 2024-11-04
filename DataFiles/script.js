// Create Socket
const socket = new WebSocket("ws://127.0.0.1:12345");

// On Connect
socket.onopen = function () {
  console.log("Connected to the server");
};

// On disconnect
socket.onclose = function () {
  console.log("Disconnected from the server");
};

// Tv
const breakingNewsTV = document.querySelector(".breaking-news-tv");

// Parses message into JSON and handles appropriate API endpoint
socket.onmessage = function (event) {
  console.log(JSON.parse(event.data));
  let request = JSON.parse(event.data);
  let apiRoute = request["type"];
  let apiData = request["data"];

  // ValueUpdate Endpoint
  if (apiRoute === "valueUpdate") {
    updateValue(apiData["id"], apiData["value"]);
  }

  // News Endpoint
  if (apiRoute === "news") {
    updateBreakingNews(apiData);
  }

  // City Visuals Endpoint
  if (apiRoute === "cityVisuals") {
    displayCityStructure(apiData);
  }
};

function updateBreakingNews(message) {
  const newsItem = document.createElement("p");
  newsItem.textContent = message;
  breakingNewsTV.appendChild(newsItem);
}

// Function to update values and trigger bubble effect
// Function to update values and trigger bubble effect
function updateValue(id, newValue) {
  // Get elements by id
  const element = document.getElementById(id.toLowerCase());
  const imageElement = document.getElementById(`${id.toLowerCase()}Img`);

  // Parse new value (increment, decrement, or set)
  const currentValue = getCurrentValue(id.toLowerCase());

  if (newValue.includes("++")) {
    newValue = currentValue + parseInt(newValue.replace("++", ""), 10);
  } else if (newValue.includes("--")) {
    newValue = currentValue - parseInt(newValue.replace("--", ""), 10);
  } else {
    newValue = parseInt(newValue, 10);
  }

  // Update element text based on id
  switch (id.toLowerCase()) {
    case "money":
    case "citizens":
      element.innerText = `${newValue}`;
      break;

    case "satisfaction":
          element.innerText = `${newValue}%`;
          break;

    case "powerplant":
    case "waterplant":
    case "wastesite":
    case "sewagesystem":
      newValue = parseFloat(newValue);
      element.innerText = `${capitalize(id.toLowerCase())}: ${newValue}%`;
      break;

    case "progress-public":
    case "progress-car":
    case "progress-train":
    case "progress-plane":
      console.log("New value progress bar: " + newValue);
      updateProgressBar(id.toLowerCase(), newValue);
      break;

    default:
      element.innerText = `${capitalize(id.toLowerCase())}: ${newValue}`;
  }

  // Add and remove bubble effect
  triggerBubbleEffect(imageElement);
}

// Helper function to capitalize the first letter
function capitalize(str) {
  return str.charAt(0).toUpperCase() + str.slice(1);
}

// Helper function to trigger bubble effect
function triggerBubbleEffect(imageElement) {
  imageElement.classList.add("bubble-effect");
  setTimeout(() => {
    imageElement.classList.remove("bubble-effect");
  }, 500);
}

// Returns value currently stored in element of HTML id
function getCurrentValue(id) {
  if (
    id === "progress-public" ||
    id === "progress-car" ||
    id === "progress-train" ||
    id === "progress-plane"
  ) {
    id += "-value";
  }

  let elementText = document.getElementById(id).innerHTML.toString();
  let elementValue = elementText.substring(elementText.indexOf(":") + 1);
  return parseInt(elementValue);
}

// Updates the value and graphic of the progress bar
function updateProgressBar(id, newValue) {
  const bar = document.getElementById(id);
  const barText = document.getElementsByClassName(id)[0];
  barText.innerHTML = `${newValue}%`;
  bar.setAttribute("data-progress", newValue);
  bar.style.width = newValue + "%";

  // Update color based on new value
  bar.classList.remove("progress-low", "progress-medium", "progress-high");
  if (newValue <= 40) {
    bar.classList.add("progress-low"); // Green
  } else if (newValue > 40 && newValue <= 70) {
    bar.classList.add("progress-medium"); // Orange
  } else {
    bar.classList.add("progress-high"); // Red
  }
}

function simulateMessage(msgJSON) {
  const event = {
    data: msgJSON,
  };

  // Call the WebSocket message handler with the simulated event
  socket.onmessage(event);
}

//var snd3 = new Audio("evil.mp3");
document.getElementById("pauseImg").addEventListener("click", function () {
  //snd3.play();
  if (socket.readyState === WebSocket.OPEN) {
    if (document.getElementById("pauseImg").alt === "start") {
      const message = "start";
      socket.send(message); // Send message to the server
      document.getElementById("pauseImg").src = "img/stop.png";
      document.getElementById("pauseImg").alt = "stop";
    } else {
      const message = "stop";
      socket.send(message); // Send message to the server
    }
  } else {
    console.error("WebSocket is not open.");
  }
  // snd3.currentTime = 0;
});

//FUNCTION TO SEND MESSAGE TO CPP(EDUCATION POLICY)
var snd1 = new Audio("evil.mp3");
document.getElementById("education").addEventListener("click", function () {
  snd1.play();
  if (socket.readyState === WebSocket.OPEN) {
    const message = "education";
    socket.send(message); // Send message to the server
  } else {
    console.error("WebSocket is not open.");
  }
  snd1.currentTime = 0;
});

//FUNCTION TO SEND MESSAGE TO CPP(SHORT WORK WEEK POLICY)
var snd2 = new Audio("yay.mp3");
document.getElementById("short-work").addEventListener("click", function () {
  snd2.play();
  if (socket.readyState === WebSocket.OPEN) {
    const message = "shortwork";
    socket.send(message); // Send message to the server
  } else {
    console.error("WebSocket is not open.");
  }
  snd2.currentTime = 0;
});

//FUNCTION TO DISPLAY CITY STRUCTURE (REMEMBER TO INCLUDE <script src="https://d3js.org/d3.v7.min.js"></script>)
function displayCityStructure(data) {
  // Set dimensions and create color scale
  const width = 1000; // Width of the SVG
  const height = 400; // Height of the SVG
  const color = d3.scaleOrdinal(d3.schemeTableau10);

  const svg = d3.select("#treemap").html("");

  const root = d3.treemap().size([width, height]).padding(1).round(true)(
    d3
      .hierarchy(data)
      .sum((d) => d.value)
      .sort((a, b) => b.value - a.value)
  );

  svg
    .attr("viewBox", [0, 0, width, height])
    .attr("style", "max-width: 100%; height: auto;");

  const tooltip = d3.select("#tooltip");

  const leaf = svg
    .selectAll("g")
    .data(root.leaves())
    .join("g")
    .attr("transform", (d) => `translate(${d.x0},${d.y0})`)
    .on("mouseover", (event, d) => {
      tooltip
        .html(`Name: ${d.data.name}<br>Value: ${d.value}`)
        .style("left", `${event.pageX + 5}px`)
        .style("top", `${event.pageY - 28}px`)
        .style("opacity", 0.9);
    })
    .on("mouseout", () => {
      tooltip.style("opacity", 0);
    });

    leaf
    .append("rect")
    .attr("fill", (d) => color(d.data.name))
    .attr("fill-opacity", 0.6)
    .attr("width", (d) => d.x1 - d.x0)
    .attr("height", (d) => d.y1 - d.y0);
  
  leaf
    .append("text")
    .attr("x", (d) => (d.x1 - d.x0) / 2)
    .attr("y", (d) => (d.y1 - d.y0) / 2)
    .attr("text-anchor", "middle")
    .attr("fill", "black")
    .attr("font-size", "10px")
    .text((d) => d.data.name);
}

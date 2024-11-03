# COS 214 Project - City Simulator

<a href="https://drive.google.com/uc?export=view&id=1OobIHf2l4Sx1AT8Zpl6-IFVqgv5Tjgp9"><img src="https://drive.google.com/uc?export=view&id=1OobIHf2l4Sx1AT8Zpl6-IFVqgv5Tjgp9" style="width: 650px; max-width: 100%; height: auto" title="Click to enlarge picture" />

# Contents

- [Description](#description)
- [Documentation](#documentation)
- [Setup](#setup)
- [Team](#team)

# Description

The City Builder Simulation is a C++ project where users manage and develop various aspects of an evolving city. The simulation balances resources, infrastructure, and the needs of citizens while demonstrating principles of software design, such as scalability, flexibility, and maintainability.

# Documentation

[Report]()

[API Documentation]()

[Doxygen Documentation]()

# Setup
### Prerequisites

```
Boostbeast: sudo apt-get install libboost-all-dev
Nlohmann JSON: sudo apt-get install nlohmann-json3-dev
Doctest: sudo apt install doctest-dev (Assuming WSL)
```
### Cloning
```
git clone https://github.com/COS214-Project-2024/Doofenshmirtz-Evil-Incorporated.git
```

### Building
This project can be built using Makefile:
```
Compilation: make all (Ensure you are currently in the SystemFiles directory)
Demo Main: make run_demo
Testing Main (Unit Tests): make run_tests
```

### Demo Running
When make run_demo is called:
1. Go to Project/DataFiles/
2. Launch the web interface(index.html)
3. Console should say client connected(if not refresh html page)
4. Click play button to run the Simulation.
5. Click stop button to stop Simulation.
6. Refresh html to terminate program.

# Team 

<table>
    <tr><th>Member</th><th>Roles</th><th>Description</th></tr>
    <tr>
      <td align="center">
	  	John-Peter Krause<br>u23533529<br>
		<img src="https://i.redd.it/ur34et8qmft91.jpg" alt="johna profile" width="200" height="200">
	  </td>
	  <td align="center">
	  	Observer<br>Singleton<br>
		<a href="https://github.com/johnpeterprogramming">
			<img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
		</a>
	  </td>
	  <td>
	  	Rizz 100<br>Ohio Gyat<br>Sneak 100<br>The Rizzler<br>Skibidi<br>
	  </td>
	</tr>
    <tr>
      <td align="center">
	  	Philipp du Plessis<br> u23526204 <br>
		<img src="https://64.media.tumblr.com/e45427d8581bdf7afa9c649d9a711ad7/b73c26f96996b26c-85/s1280x1920/733cd4b5ac71712eb3927ba6d3105e869683005c.png" alt="philip profile" width="200" height="200">
	  </td>
	  <td align="center">
	  	Citizen <br> State <br> Server <br> Facade <br>  <br><br>
		<a href="https://github.com/phillDup">
			<img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
		</a>
	  </td>
	  <td>
	  	Designing them patterns 🧑‍🎨️<br>
		500 cigarettes 🚬🚬🚬 <br>
		🗣🗣🗣 Ask me about my Scooby-Doo impression (rhu rho) 🗣🗣🗣 
	  </td>
	</tr>
    <tr>
      <td align="center">
	  	Tiaan Bosman<br> u22704958 <br>
		<img src="https://avatarfiles.alphacoders.com/176/176387.jpg" alt="your pfp" width="200" height="200">
	  </td>
	  <td align="center">
	  	Singleton <br> Facade <br> UI <br> Server<br><br>
		<a href="https://github.com/TiaanBosman101">
			<img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
		</a>
	  </td>
	  <td>
	  	🥃 Fueled by coffee and bad decisions—what could go wrong?<br>🔍 Debugging my mental state one stack trace at a time
	  </td>
	</tr>
	<tr>
      <td align="center">
	  	Nicolaas Hermanus Pretorius<br> u23525381 <br>
		<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSA4oVF9Z91LUDIJJlroakAORBD7zbyKtkRiQ" alt="your pfp" width="200" height="200">
	  </td>
	  <td align="center">
	  	Strategy <br> Command<br> Group dance for demo <br>
		<a href="https://github.com/NicohaasHerhaasus">
			<img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
		</a>
	  </td>
	  <td>
		I the nite
		👉👈🥺
	  </td>
	</tr>
	<tr>
      <td align="center">
	  	Jack Bawden<br> u23529068 <br>
		<img src="https://s3-alpha.figma.com/hub/file/2944732189/b47472b8-4e17-477e-a0a8-d5fcbed6a374-cover.png" alt="your pfp" width="200" height="200">
	  </td>
	  <td align="center">
	  	Composite <br> Iterator <br> skillz <br> etc<br><br>
		<a href="https://github.com/Jack-jack1">
			<img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
		</a>
	  </td>
	  <td>
	  	i saw batman in cat womans costume
	  </td>
	</tr>
	<tr>
      <td align="center">
	  	Muller Dannhauser<br> 23542765 <br>
		<img src="https://i.redd.it/oiltpr1u61xd1.jpeg" alt="your pfp" width="200" height="200">
	  </td>
	  <td align="center">
	  	CityUnit <br> Composite <br> Stupid Mistikes <br> Horrific code <br><br>
		<a href="https://github.com/MullerPietPompies">
			<img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
		</a>
	  </td>
	  <td>
	  	The descriptoin is indeed very cool
	  </td>
	</tr>
	<tr>
      <td align="center">
	  	Dewald Colesky<br> 23536030 <br>
		<img src="https://platform.polygon.com/wp-content/uploads/sites/2/chorus/uploads/chorus_asset/file/13752494/Screen_Shot_2018_10_31_at_8.14.46_PM.0.jpg?quality=90&strip=all&crop=0.027173913043484,0,99.945652173913,100" alt="your pfp" width="200" height="200">
	  </td>
	  <td align="center">
	  	Factory <br> Moral support <br> Good ideas <br> Overall carry<br><br>
		<a href="">
			<img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white">
		</a>
	  </td>
	  <td>
	  	I am a mediator.
	  </td>
	</tr>
</table>

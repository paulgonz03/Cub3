*This project has been created as part of the 42 curriculum by jonamart, paulgonz*

# cub3D

## Description

cub3D is a 3D graphical project inspired by the classic Wolfenstein 3D engine.  
Its goal is to introduce students to raycasting, graphics programming, and game‑loop architecture using the MiniLibX graphical library.

The program renders a first‑person view inside a 2D map by projecting walls, textures, and player movement into a pseudo‑3D environment.  
It focuses on algorithmic precision, clean architecture, and real‑time rendering constraints.

### Core Objectives
- Implement a raycasting engine from scratch  
- Parse and validate a custom .cub configuration file  
- Render walls with correct projection and texture mapping  
- Implement player movement, rotation, and collision detection  
- Maintain strict norminette compliance and modular code design  

---

## Instructions

### Compilation
To compile the project, run:

```bash
make
```
To clean object files:
```bash
make clean
```
To remove all binaries:
```bash
make fclean
```
To recompile from scratch:
```bash
make fclean
```
### Execution

Run the program with a valid .cub map file:
```bash
./cub3D maps/example.cub
```
The .cub file must include:

Texture paths for NO, SO, WE, EA
Floor and ceiling RGB colors
A closed map using 1, 0, and a player start position (N, S, E, W)

Example:

	NO ./textures/north.xpm
	SO ./textures/south.xpm
	WE ./textures/west.xpm
	EA ./textures/east.xpm

	F 220,100,0
	C 225,30,0

	111111
	100001
	10N001
	100001
	111111
### Controls

Key	Action
W / A / S / D	Move forward, left, backward, right
← / →	Rotate camera
ESC	Exit program

### Features

* Real‑time raycasting engine

* Correct wall projection and distance correction

* Texture mapping with MiniLibX

* Smooth player movement and rotation

* Robust map parsing and error handling

* Fully norminette‑compliant modular architecture

## Resources
Raycasting & Graphics

   * Lode’s Computer Graphics Tutorial — Raycasting

   * MiniLibX documentation

   * Wolfenstein 3D engine references

   * Articles on DDA (Digital Differential Analyzer) algorithms

   * Tutorials on 2D to pseudo‑3D projection

Artificial Intelligence tools were used only for:

   * Clarifying raycasting concepts (DDA, projection math, texture mapping)

   * Debugging assistance through conceptual explanations

All final code, algorithms, and implementations were written, verified, and tested manually by the project authors.

## Technical Notes

Known Limitations

    MiniLibX performance varies by OS

    Only .xpm textures are supported

    No sprites or doors unless implemented as bonus
License

	This project is part of the 42 School curriculum and follows its academic integrity guidelines.
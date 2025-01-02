# Cub3D Game

![ezgif com-gif-maker (1)](ezgif.com-video-to-gif-converter.gif)

*A project to build a simple 3D game engine using raycasting.*  

---

## Overview  

**Cub3d** is a project from the 1337 School curriculum that introduces students to the basics of 3D graphics rendering and game development. Inspired by games like **Wolfenstein 3D**, this project involves creating a 3D maze-like game using raycasting techniques to simulate a three-dimensional perspective within a two-dimensional map.  

---

## Key Objectives  

- Understand and implement a **raycasting engine**.  
- Learn about 2D and 3D graphics rendering techniques.  
- Handle user input to enable movement and interaction within the game world.  
- Develop clean, modular, and efficient C code.  

---

## Features  

- **Raycasting Engine**:  
  - Renders walls, floors, and ceilings in a 3D perspective.  
  - Calculates the distance between the player and walls for accurate rendering.  

- **User Interaction**:  
  - Movement: Forward, backward, and sideways (strafe).  
  - Rotation: Left and right, enabling a full 360-degree view.  

- **Map Parsing**:  
  - Reads and validates maps from `.cub` files.  
  - Ensures proper formatting and error handling.  

- **Custom Textures**:  
  - Supports textures for walls, floors, and ceilings.  
  - Allows sprite integration for objects like doors or enemies.  

- **Minimap**:  
  - Displays a top-down view of the map for easier navigation.  

---

## Project Structure  

| File                | Description                                      |  
|---------------------|--------------------------------------------------|  
| `cub3d.c`           | Main program file and game loop logic.           |  
| `raycasting.c`      | Implementation of the raycasting engine.         |  
| `input.c`           | Handles user input for movement and rotation.    |  
| `map_parser.c`      | Reads and validates the `.cub` map files.        |  
| `textures.c`        | Loads and renders textures for walls and objects.|  
| `cub3d.h`           | Header file with function prototypes and macros. |  
| `Makefile`          | Script to compile the project.                   |  

---

## Usage  

### 1. Compile the program  

```bash  
make  
```  

### 2. Run the program with a map file  

```bash  
./cub3d [map_file.cub]  
```  

### 3. Example  

```bash  
./cub3d maps/example.cub  
```  

---

## Map File Format  

The map files (`.cub`) define the structure of the game world.  

### Example:  

```plaintext  
NO ./textures/wall_north.xpm  
SO ./textures/wall_south.xpm  
WE ./textures/wall_west.xpm  
EA ./textures/wall_east.xpm  
F 220,100,0  
C 225,30,0  

111111111  
100000001  
100200001  
100000001  
111111111  
```  

- **Texture paths**: Specify textures for north, south, west, and east walls.  
- **Colors**: Define floor (F) and ceiling (C) colors in RGB format.  
- **Map**: A grid where:  
  - `1` = Wall  
  - `0` = Walkable space  
  - `2` = Sprite (e.g., enemy or object)  

---

## Controls  

| Key                  | Action                          |  
|----------------------|---------------------------------|  
| `W` / `Arrow Up`     | Move forward                   |  
| `S` / `Arrow Down`   | Move backward                  |  
| `A`                  | Strafe left                    |  
| `D`                  | Strafe right                   |  
| `←` / `→`            | Rotate left/right              |  
| `ESC`                | Quit the game                  |  

---

## Challenges  

- **Raycasting**:  
  Implementing the raycasting algorithm to render a 3D perspective from a 2D map.  
- **Texture Mapping**:  
  Ensuring textures are properly scaled and mapped to walls.  
- **Map Validation**:  
  Detecting errors in `.cub` files, such as invalid characters or improperly enclosed maps.  

---

## Testing  

### 1. Run with provided maps  

```bash  
./cub3d maps/example.cub  
```  

### 2. Create custom maps  

Design your own `.cub` files to test edge cases and explore different layouts.  

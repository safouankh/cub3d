# cub3d

A C-based raycasting project inspired by classic 3D maze games like Wolfenstein 3D. This project parses a `.cub` map file, loads textures and colors, and renders a simple first-person view using MLX42.

## Overview

`cub3d` is a 42 project focused on:

- parsing map files in the `.cub` format
- validating map structure and required elements
- loading wall textures for each compass direction
- setting floor and ceiling colors
- rendering a playable 3D-like maze using a graphical library
- handling keyboard movement and window close events

## Features

- .cub map parsing for:
  - `NO`, `SO`, `EA`, `WE` texture paths
  - `F` and `C` floor/ceiling colors
  - playable maze map layout
- validation for incomplete or invalid map data
- movement controls using `W`, `A`, `S`, `D`
- escape key to close the window
- MLX42-based rendering loop

## Project structure

- `sources/` — main program entry and runtime logic
- `parsing/` — map parsing and validation
- `events/` — keyboard and window event handling
- `drawing/` — rendering-related code
- `includes/` — project headers
- `libft/` — custom C library used by the project
- `get_next_line/` — line-reading utility
- `maps/` — example map files
- `images/` — texture assets used by the renderer
- `MLX42/` — MLX42 graphics library dependency

## Requirements

This project depends on:

- C compiler (`cc`/`gcc`)
- `make`
- `MLX42`
- a macOS environment for the required frameworks (`Cocoa`, `OpenGL`, `IOKit`)

## Build

From the project root:

```bash
make
```

This will build the executable `cub3d` and compile the required project libraries.

## Run

```bash
./cub3d maps/map.cub
```

Replace `maps/map.cub` with your own valid map file.

## Example map format

The project expects a map file formatted like this:

```text
NO ./images/1.xpm
SO ./images/2.xpm
EA ./images/3.xpm
WE ./images/4.xpm
F 3, 45, 55
C 3, 45, 55
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Legend

- `0` = empty space
- `1` = wall
- `N`, `S`, `E`, `W` = player starting position and facing direction
- `F` and `C` = floor and ceiling colors in RGB format

## Controls

- `W` — move forward
- `S` — move backward
- `A` — move left
- `D` — move right
- `ESC` — quit the game

## Notes

This project is a simplified 3D maze renderer and is intended as a learning exercise in C, parsing, graphics programming, and game engine fundamentals.

## License

This project is for educational use as part of the 42 curriculum.

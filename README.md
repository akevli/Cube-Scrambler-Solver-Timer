# Final Project

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

**Author**: Alexander Li - [`akli2@illinois.edu`](mailto:akli2@illinois.edu)

# Rubik's Cube Scrambler, Timer, and Solver

![](https://i.imgur.com/v5m7FsT.png)
![](https://i.imgur.com/DTpilmF.png)

## Features
* The user will be able to time their solve.
* There will be graphs to plot the user's data for analysis.
    * Uses a Python 2.7 wrapper to plot graphs via matplotlib.
    * Exports a .png of the graph to /assets
* The program will provide scrambles for a 3x3 Rubik's cube.
* The program will also provide a solution to the scramble of the rubik's cube (via Kociemba).
* Provides a visualization of what the cube should look like based on the scramble.

## Dependencies
This program will require Python 2.7 and matplotlib installed. You must also 
have Visual Studio 2015 on Microsoft Windows to build this project.

* [Catch2](https://github.com/catchorg/Catch2)
* [Cinder](https://libcinder.org/)
* [SQlite3-CMake](https://github.com/alex85k/sqlite3-cmake)
* [SQLite-Modern-C](https://github.com/SqliteModernCpp/sqlite_modern_cpp)
* [MatPlotLib-CPP](https://github.com/lava/matplotlib-cpp)
* [kociemba](https://github.com/muodov/kociemba)

### Windows

#### Visual Studio

- [Visual Studio 2015+](https://visualstudio.microsoft.com/)
- [Python 2.7](https://www.python.org/downloads/release/python-2718/)

## Controls

| Key       | Action                                                      |
|---------- |-------------------------------------------------------------|
| `g`       | View and export the graph                                   |
| `t`       | Provide a new scramble                                      |
| `SPACE`   | Start / Stop the timer                                      |
| `v`       | View the solution                                           |

## Cube Scramble/Solve Notation
The names of the facelet positions of the cube (letters stand for Up, Left, Front, Right, Back, and Down):

```
             |************|
             |*U1**U2**U3*|
             |************|
             |*U4**U5**U6*|
             |************|
             |*U7**U8**U9*|
             |************|
 ************|************|************|************
 *L1**L2**L3*|*F1**F2**F3*|*R1**R2**R3*|*B1**B2**B3*
 ************|************|************|************
 *L4**L5**L6*|*F4**F5**F6*|*R4**R5**R6*|*B4**B5**B6*
 ************|************|************|************
 *L7**L8**L9*|*F7**F8**F9*|*R7**R8**R9*|*B7**B8**B9*
 ************|************|************|************
             |************|
             |*D1**D2**D3*|
             |************|
             |*D4**D5**D6*|
             |************|
             |*D7**D8**D9*|
             |************|
```
A cube definition string "UBL..." means that in position U1 we have the U-color, in position U2 we have the
B-color, in position U3 we have the L color etc. according to the order `U1`, `U2`, `U3`, `U4`, `U5`, `U6`, `U7`, `U8`, `U9`, `R1`, `R2`,
`R3`, `R4`, `R5`, `R6`, `R7`, `R8`, `R9`, `F1`, `F2`, `F3`, `F4`, `F5`, `F6`, `F7`, `F8`, `F9`, `D1`, `D2`, `D3`, `D4`, `D5`, `D6`, `D7`, `D8`, `D9`, `L1`, `L2`, `L3`, `L4`,
`L5`, `L6`, `L7`, `L8`, `L9`, `B1`, `B2`, `B3`, `B4`, `B5`, `B6`, `B7`, `B8`, `B9`.

Solution string consists of space-separated parts, each of them represents a single move:
* A single letter by itself means to turn that face clockwise 90 degrees.
* A letter followed by an apostrophe means to turn that face counterclockwise 90 degrees.
* A letter with the number 2 after it means to turn that face 180 degrees.

e.g. **`R U R’ U R U2 R’ U`**

## Additional Notes

* The program assumes that you will scramble the cube with green on the front
    and white on the top
* For the visualization of the cube after a scramble, the capital letters represent
    the layer of the cube and the color of the letter corresponds to the color
    of that piece
## DFS_Mouse_Simulator
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
---

## Contributors

1) [Rajan Pande](https://github.com/rpande1996): 
Graduate Student of M.Eng Robotics at University of Maryland. 
2) [Douglas Summerlin](https://github.com/dsumm1001): 
Graduate Student of M.Eng Robotics at University of Maryland.
3) [Prasanna Raghavan](https://github.com/prasannaraghavan): 
Graduate Student of M.Eng Robotics at University of Maryland.

## Overview

This code uses the DFS algorithm to help a mouse robot reach the goal position in a third-party simulator

## Softwares

* Recommended IDE: Visual Studio Code 1.63.2
* Recommended OS: Ubuntu 18.06

## Programming Languages

* C++ 17

## License 

```
MIT License

Copyright (c) 2021 Rajan Pande, Douglas Summerlin, Prasanna Raghavan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.
```

## Demo

Following demo is for Maze 3:
- [DFS Algorithm Representation](https://youtu.be/HOb_XCYA3K8)

![GIF](media/gif/Maze_3.gif)

## Build
Prerequisites:
```
mkdir -p ∼/mouse_simulator
cd ~/mouse_simulator
git clone https://github.com/mackorone/mms.git
git clone https://github.com/micromouseonline/mazefiles.git
git clone https://github.com/mackorone/mms-cpp.git
sudo apt-get install qt5-default
cd ~/mouse_simulator
git clone https://github.com/rpande1996/DFS_Mouse_Simulator
cd mms/src
qmake && make
cd ∼/mouse_simulator/mms/bin
./mms
```
Change the values as given:

![Image](https://github.com/rpande1996/DFS_Mouse_Simulator/blob/main/media/config.png)
```
1. Name: DFS_Mouse_Simulator
2. Directory: ~/mouse_simulator/DFS_Mouse_Simulator
3. Build Command: g++ src/api.cpp src/main.cpp src/node.cpp src/mouse.cpp src/util.cpp
4. Run Command: ./a.out
```

# XM2INC

-----------------

[![License](https://camo.githubusercontent.com/ec1b7780bdc1d8401873e5a03328cc295d44f6b797b35f493b32996c0faad199/68747470733a2f2f706f7365722e707567782e6f72672f6c61726176656c2f6672616d65776f726b2f6c6963656e73652e737667)](https://github.com/rialbat/XM2INC/blob/main/LICENSE)
[![GitHub issues](https://img.shields.io/github/issues-raw/rialbat/XM2INC)](https://github.com/rialbat/XM2INC)
[![Status](https://img.shields.io/badge/status-alpha-green)](https://github.com/rialbat/XM2INC)

XM2INC is a program that helps you include .xm files in your assembler projects.

## Manual compilation
-----------------
For this program, I used Qt Creator 8.0.1 and MinGW-W64.
If you want to compile this program manually, follow these steps:
1. **Clone the Repository** First, you need to clone the repository from GitHub to your local machine. You can do this using the following command in your terminal:
```cmd
git clone https://github.com/rialbat/XM2INC.git
```
2. **Navigate to the Project Directory** Change your current directory to the cloned repository:
3. **Compile the Project** Now, you can run CMake to compile the project
```cmd
cmake --build . -- target all
```
## Guide to using
-----------------
1. After opening the program, specify the path to the input file and the place where you want to save the result.

<p align="center">
  <img src="https://github.com/rialbat/XM2INC/blob/master/images/MainWindow.png?raw=true" width="500"/>
</p>

2. Select the desired conversion mode:
<ol style="list-style-type: lower-alpha">
  <li>Conversion from a binary file to .inc:</li>
  <p align="center">
  <img src="https://github.com/rialbat/XM2INC/blob/master/images/Result1.png?raw=true" width="500"/>
</p>
  <li>Converting from a text file to .inc:</li>
  <p align="center">
  <img src="https://github.com/rialbat/XM2INC/blob/master/images/Result2.png?raw=true" width="500"/>
</p>
<p align="center">
  <img src="https://github.com/rialbat/XM2INC/blob/master/images/Result3.png?raw=true" width="500"/>
</p>
</ol>

## TODO
-----------------

1. Add new file formats.
2. Clear the code.

## ![:octocat:](https://github.githubassets.com/images/icons/emoji/octocat.png ":octocat:")References
-----------------
1. XM files for tests - https://github.com/milkytracker/MilkyTracker

## 📄 License
-----------------
**[MIT License](https://github.com/rialbat/XM2INC/blob/main/LICENSE)**

Copyright (c) 2023 **[rialbat](https://github.com/rialbat)**

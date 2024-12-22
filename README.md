# A Visual Node-Based (very basic) Programming Language and IDE
Use visual nodes to craft your **dream** program!  
(very early in development)  
*Drako uses a custom UI library which is still very unstable*

![image](https://github.com/user-attachments/assets/d5c5a688-7716-41a3-903c-d739dc650401)

# How To Build
Drako is written in C++ but instead of the typical C++ build system (GNU Make or CMake), Drako uses the zig build system (and also the zig C/C++ compiler). To get started download [zig](https://ziglang.org/) 0.13.0 (stable). 
After installing zig, run the following commands:  
> [!WARNING]
> You need RAYLIB installed as a system library
```bash
git clone https://github.com/OsakiTsukiko/drako
cd drako
zig build run
```

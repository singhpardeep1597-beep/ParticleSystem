# Particle System — C++ / raylib

A small interactive particle emitter made in C++ with **raylib**. It uses a reusable pool of 1,000 particles to create colorful effects wherever the mouse is held down.

## Preview

![Particle System window preview](assets/Animation1.gif)


## Features

- A **1,000-particle object pool** instead of allocating particles every frame.
- Random particle colors, sizes, speeds, and directions.
- Additive blending for bright, overlapping particles.
- Gravity, fading, and automatic particle deactivation so particles can be reused.
- 500 × 500 window at a target of 60 FPS.

## Controls

| Input | Action |
| --- | --- |
| Hold left mouse button | Emit particles at the cursor |
| Close window / press Escape | Exit |

## Build with CMake

Requires a C++17 compiler, CMake 3.20+, and raylib. If raylib is not already installed as a CMake package, CMake will download raylib 5.5 while configuring (internet connection required).

```bash
cmake -S . -B build
cmake --build build --config Release
```

On Windows, the executable may be under `build/Release/` or `build/`, depending on the CMake generator.

## Visual Studio

The original Visual Studio solution is retained as `Particlesystem.slnx`. Open it in a compatible Visual Studio version. The `.vcxproj` still contains the developer's local raylib include/library paths; update those paths to match your installation if needed. The missing `Particl.cpp` reference was changed to a project-relative path.

## Project structure

```text
ParticleSystem/
├── CMakeLists.txt
├── Particlesystem.slnx
├── Particlesystem/
│   ├── main.cpp
│   ├── Particl.h
│   ├── Particl.cpp
│   ├── ParticleSystem.h
│   ├── ParticleSystem.cpp
│   └── Particlesystem.vcxproj
└── .gitignore
```

> **Source note:** The uploaded project ZIP did not contain the original `Particl.cpp` (the Visual Studio project referenced a file outside the project). A replacement implementation is included to make this repository self-contained; its motion and lifetime behavior may differ from the original.

Generated Visual Studio files, binaries, and local Git metadata are intentionally excluded.

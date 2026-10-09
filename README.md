*This project was built in the context of the 42 common core by Brieuc Coppieters & François Krakow.*

# miniRT

miniRT is a small ray tracer written in C. It reads a scene description from a `.rt` file and renders it in a window using the MiniLibX graphics library.

It supports spheres, planes and cylinders, lit by ambient light and a point light that casts shadows.

## Build

Requirements: Linux, `cc`, `make`, and the X11 development libraries (`libx11-dev`, `libxext-dev`).

```sh
make
```

This builds `libft`, the vectors library, MiniLibX and the `miniRT` executable.

## Usage

```sh
./miniRT scenes/scene.rt
```

Press `Esc` or close the window to quit.

## Scene files

A scene is a `.rt` file with one element per line. `A`, `C` and `L` can each appear only once.

| Element | Format | Example |
|---|---|---|
| Ambient light | `A <ratio 0-1> <R,G,B>` | `A 0.5 255,255,255` |
| Camera | `C <position> <orientation> <FOV 0-180>` | `C 0,-7,0 0,1,0 70` |
| Light | `L <position> <brightness 0-1> <R,G,B>` | `L -4,-8,2 0.8 255,255,255` |
| Sphere | `sp <center> <diameter> <R,G,B>` | `sp 0,0,0 3 123,164,45` |
| Plane | `pl <point> <normal> <R,G,B>` | `pl 0,2,0 0,-1,0 23,142,78` |
| Cylinder | `cy <center> <axis> <diameter> <height> <R,G,B>` | `cy -4,1,2 0,0,1 4 7 54,123,245` |

Positions are `x,y,z` coordinates. Orientations, normals and axes are normalized vectors (each component between -1 and 1).

Example scenes are in [scenes/](scenes/).

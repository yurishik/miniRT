*This project has been created as part of the 42 curriculum by hisasano, yurishik.*

# miniRT

## Description

**miniRT** is a minimal ray tracing engine written in C using the MiniLibX graphical library. The goal of this project is to simulate the physical behavior of light rays interacting with 3D geometric objects and render the computed scene as a 2D image from scratch.

### Key Features
- **Scene Parsing (`.rt` files):** Robust parsing and error handling for scene elements, including ambient lighting, camera orientation/FOV, light sources, and basic geometric shapes, with strict validation for duplicate identifiers and out-of-range parameters.
- **Ray-Object Intersections:** Precise mathematical intersection algorithms for spheres, planes, and cylinders (lateral surface and cap boundaries) using vector mathematics and quadratic equations.
- **Lighting and Shading:**
  - Ambient lighting and diffuse illumination calculated based on Lambert's cosine law.
  - Hard shadow casting to detect occlusions between intersection hit points and light sources.
- **Window Management:** Smooth rendering via MiniLibX image buffers with clean termination and full memory deallocation on exit.

---

## Instructions

### Requirements (Linux)
The dependencies below are quoted from the official [MiniLibX repository](https://github.com/42Paris/minilibx-linux):

> - MinilibX only support TrueColor visual type (8,15,16,24 or 32 bits depth)
> - gcc
> - make
> - X11 include files (package xorg)
> - XShm extension must be present (package libxext-dev)
> - Utility functions from BSD systems - development files (package libbsd-dev)
> - e.g. `sudo apt-get install gcc make xorg libxext-dev libbsd-dev` (Debian/Ubuntu)

### Compilation

To compile the project, run the following command in the root directory:

```bash
make
```

Available `Makefile` rules:

* `make` or `make all`: Compiles the `miniRT` executable.
* `make clean`: Removes intermediate object files (`.o`).
* `make fclean`: Removes object files and the `miniRT` binary.
* `make re`: Recompiles the entire project from scratch.
* `make test`: Runs automated invalid parsing test cases to verify expected error handling and messages.

### Usage

Execute the program by passing a valid `.rt` scene configuration file:

```bash
./miniRT rt_files/sample.rt
```

### Controls

* **`ESC` key:** Close the window and exit the program cleanly.
* **Window Close Button (`×`):** Terminate the process and free all allocated resources without memory leaks.


## Resources

### References
- [Introduction to Ray Tracing (jun-networks)](https://jun-networks.hatenablog.com/entry/2021/04/02/043216): Conceptual explanation and practical breakdown of fundamental ray tracing principles and mathematics.
- [42 Cursus Guide: Understand miniRT](https://42-cursus.gitbook.io/guide/4-rank-04/minirt/understand-minirt): Project architecture breakdown, common hurdles, and overall workflow guidelines within the 42 curriculum.
- [Building a miniRT 42 Project - Part 1 (Irem Oztimur)](https://medium.com/@iremoztimur/building-a-minirt-42-project-part-1-ae7a00aebdb9): Step-by-step introduction to setting up the ray tracing pipeline and vector operations.
- [The Mathematics Behind the miniRT 42 Project: A Comprehensive Exploration (Mohamad Mansuri)](https://medium.com/@mansurimohamad92/the-mathematics-behind-the-minirt-42-project-a-comprehensive-exploration-213e149c85d8): Deep dive into geometric formulas, ray-object intersection proofs (spheres, planes, cylinders), and lighting equations.


### Use of AI
- **Documentation & Translation:** AI was utilized to draft, format, and translate this `README.md` from Japanese into English, ensuring all requirements set by the 42 subject were properly addressed.
- **Test Case Generation:** AI was used to generate invalid `.rt` scene configuration files (e.g., duplicate elements, out-of-range values, formatting errors, and missing parameters) to assist in building the automated parsing test suite.
- **Conceptual Understanding:** AI was consulted to clarify core ray tracing principles, including the fundamental theory of ray-object intersections, vector operations, and lighting models.

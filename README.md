*This project has been created as part of the 42 curriculum by [your_login].*

# miniRT - A Simple 3D Ray Tracer in C

## Description
**miniRT** is a fundamental Computer Graphics project developed as part of the 42 curriculum. The primary goal of this project is to implement a minimalist ray tracing engine from scratch in C using the MiniLibX graphical library, without relying on third-party 3D graphics engines.

### Overview
The program casts mathematical rays from a virtual pinhole camera into a 3D scene, tests for intersections with geometric objects, and computes light interactions based on the Lambertian reflection model.

Key highlights of the implementation:
- **Pinhole Camera Ray Casting**: Maps 2D screen pixels to normalized 3D ray direction vectors, accounting for viewport bounds and aspect ratios.
- **Ray-Sphere Intersection**: Solves quadratic equation systems optimized with simplified discriminant formulas ($b = 2h$) under normalized direction vectors.
- **Lighting & Shading**: Evaluates surface normals and light directions to compute ambient illumination (ratio and RGB component multiplication) alongside direct diffuse reflection (clamped to prevent color overflow).
- **Efficient Memory Rendering**: Direct pixel-buffer manipulation via an off-screen image buffer (`my_mlx_pixel_put`) rather than individual synchronous drawing calls, ensuring smooth frame delivery.

---

## Features
- **Geometric Primitives**: Sphere rendering with ray-surface collision detection.
- **Illumination Model**:
  - **Ambient Lighting**: Global base illumination scaling object colors by ambient ratio and RGB tint.
  - **Diffuse Reflection**: Lambertian cosine law based on dot products between surface normals and light vectors.
- **Window & Event Management**:
  - Clean GUI initialization with MiniLibX.
  - Graceful exit on `ESC` key press or window close button click (releasing allocated image buffers).

---

## Instructions

### Prerequisites
- Clang or GCC compiler
- Make
- Standard C libraries and X11 development headers (for Linux/X-Window environments)

### Compilation
Clone the repository and run `make` at the root of the project:
```bash
make
```

This generates the `minirt` executable.

Additional build targets:

* `make clean`: Removes intermediate object files (`.o`).
* `make fclean`: Removes object files and the compiled binary.
* `make re`: Recompiles the entire project from scratch.

### Execution

Run the executable:

```bash
./minirt rt_files/sample.rt
```

### Controls

* **ESC**: Close window and quit cleanly.
* **Window Close Button ('X')**: Destroy window and exit.

---

## Resources

### References
- [レイトレーシング入門 (Introduction to Ray Tracing)](https://jun-networks.hatenablog.com/entry/2021/04/02/043216): Conceptual guide for ray-sphere intersection equations, vector calculations, and the Lambertian diffuse model.
- [Understand miniRT - 42 Cursus Guide](https://42-cursus.gitbook.io/guide/4-rank-04/minirt/understand-minirt): Architectural overview for miniRT, covering camera ray generation, viewport mapping, and scene management.
- [Building a miniRT (42 Project) - Part 1 by İrem Öztimur](https://medium.com/@iremoztimur/building-a-minirt-42-project-part-1-ae7a00aebdb9): Practical step-by-step roadmap for miniRT setup and MiniLibX image buffer rendering.

### Use of AI
During the development of this project, AI (Gemini) was utilized as a collaborative assistant for the following tasks:
- **Understanding Concepts**: Clarifying theoretical aspects of 3D ray tracing, including pinhole camera ray casting, quadratic intersection formulas (discriminants) for spheres, and Lambertian reflection using surface normals.
- **Translation**: Assisting in drafting and polishing this README into clear and natural English.
- **Debugging and Refactoring**: Restructuring code modularity (e.g., isolating `calc_ambient_color` and `calc_diffuse_color`) to strictly comply with Norminette rules and the 25-line function limit.
- **Data Structures**: Designing unified data structures (`t_vars`, `t_camera`, `t_light`, `t_sphere`, `t_ambient`) to cleanly pass scene configurations across rendering routines.
- **Implementation & Testing Advice**: Verifying off-screen buffer addressing (`my_mlx_pixel_put`), fine-tuning boundary parameters (such as minimum intersection distance to prevent surface acne and color clamping between `0.0` and `1.0`), and discussing leak-free resource destruction on exit.

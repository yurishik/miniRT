miniRT peer-review scene tests (Subject v10.0)

Folders:
5.5_translations_rotations: 01 sphere translation, 02/03 cylinder before/after 90-degree rotation around Z.
5.6_multi_objects: intersecting sphere/cylinder, and multiple objects of the same types.
5.7_camera_position_direction: camera positioned on X/Y/Z axes and at an arbitrary off-axis position; looking toward origin.
5.8_brightness: side lighting of sphere before/after translation.
5.9_shadows: one sphere casting a shadow on a plane, and a scene with several objects.

Usage: ./miniRT <path/to/file.rt>

Notes:
- All scenes use only A, C, L, sp, pl and cy defined by the mandatory subject.
- Rotating a cylinder 90 degrees about Z turns its axis from (0,1,0) into (+/-1,0,0); compare 02 and 03.
- In 5.5/01, the back sphere is larger, so both can be observed even though the centers line up along the camera direction; translation is 7, greater than each diameter (2 and 5).
- In 5.7/04, the direction vector is approximately normalized; minor decimal rounding is expected.
- In 5.8, compare the direction of the highlight/illumination after moving the sphere.
- A successful render alone does not establish that lighting, intersections, or shadows are correct: inspect the images.

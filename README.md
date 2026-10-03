# miniRT Architecture

## Design Policy

miniRTでは、依存関係をできるだけ一方向に保つ。

基本方針：

- `.c` ファイルは責務ごとに分割する
- `.h` ファイルは細分化しすぎず、モジュール単位でまとめる
- `sphere.h / plane.h / cylinder.h` は作らず、`object.h` にまとめる
- `hit.h` は作らず、`t_hit` は `scene.h` に置く
- Ray Tracing処理からMiniLibXを直接使用しない
- ParserはRendererを知らない
- RendererはParserを知らない
- `minirt.h` は現時点ではParser内部共通ヘッダとして使用する

---

## Directory Structure

```text
miniRT/
│
├── Makefile
├── README.md
│
├── include/
│   ├── vec3.h
│   ├── object.h
│   ├── scene.h
│   ├── image.h
│   ├── render.h
│   ├── parser.h
│   ├── minirt.h
│   ├── app.h
│   ├── get_next_line.h
│   └── utils.h
│
├── src/
│   │
│   ├── math/
│   │   ├── 
│   │   ├── 
│   │   └── 
│   │
│   ├── geometry/
│   │   ├── sphere.c
│   │   ├── plane.c
│   │   ├── cylinder.c
│   │   └── object.c
│   │
│   ├── render/
│   │   ├──
│   │   └── render.c
│   │
│   ├── parser/
│   │   ├── check_args.c
│   │   ├── 
│   │   └── 
│   │
│   ├── platform/
│   │   ├── mlx_init.c
│   │   ├── 
│   │   └── 
│   │
│   └── app/
│       ├── app.c
│       ├── cleanup.c
│       └── main.c
│
├── scenes/
│   ├── 
│   └── 
│
└── libft/
```

---

## Header Responsibilities

| Header | Responsibility |
|---|---|
| `vec3.h` | `t_vec3` とベクトル計算 |
| `object.h` | `t_color`, Sphere, Plane, Cylinder, `t_object` |
| `scene.h` | Ray, Camera, Ambient, Light, Hit, Scene |
| `image.h` | MiniLibX Image Buffer |
| `render.h` | Ray Tracing / Intersection / Lighting / Rendering |
| `parser.h` | Parserの公開関数 |
| `minirt.h` | 現在はParser内部共通ヘッダ。定数、libft、GNL、utils、`t_element_counts` |
| `app.h` | miniRT全体のApplication状態 |
| `get_next_line.h` | GNL |
| `utils.h` | 共通Utility |

---

## Header Dependency

```text
vec3.h
   ↑
   │
object.h
   ↑
   │
scene.h
   ↑
   │
render.h


parser.h
   │
   └────→ scene.h
           （parse_scene 実装時）


minirt.h
   ├────→ parser.h
   ├────→ get_next_line.h
   ├────→ utils.h
   └────→ libft.h


app.h
   ├────→ scene.h
   └────→ image.h
```

---

## Runtime Flow

```text
scene.rt
   ↓
Parser
   ↓
t_scene
   ↓
Camera → Ray
   ↓
Intersection
   ↓
Nearest Hit
   ↓
Lighting / Shadow
   ↓
Color
   ↓
t_image
   ↓
MiniLibX
   ↓
Window
```

---

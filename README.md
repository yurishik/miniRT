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
- MiniLibX固有処理は `platform.h` / `src/mlx/` にまとめる
- 描画計算用の `t_image` とMiniLibX側の画像バッファを分離する
- `minirt.h` はParser内部共通処理に加え、現在の共通定数・マクロをまとめている

---

## Directory Structure

`miniRT(6).zip` の現在の構成：

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
│   ├── platform.h
│   ├── get_next_line.h
│   └── utils.h
│
├── src/
│   │
│   ├── calc_vector/
│   │   ├── vec_basic.c
│   │   ├── vec_color.c
│   │   ├── vec_length.c
│   │   ├── vec_scalar.c
│   │   └── vec_vec.c
│   │
│   ├── object/
│   │   ├── sphere.c
│   │   └── object.c
│   │
│   ├── render/
│   │   ├── camera_ray.c
│   │   ├── color.c
│   │   ├── image.c
│   │   ├── lighting.c
│   │   ├── ray_color.c
│   │   └── render.c
│   │
│   ├── parser/
│   │   ├── check_args.c
│   │   ├── error.c
│   │   ├── parse_scene.c
│   │   ├── read_file.c
│   │   ├── set_a_c_l.c
│   │   ├── set_sp_pl_cy.c
│   │   ├── set_utils.c
│   │   ├── validate_a_c_l.c
│   │   ├── validate_chars.c
│   │   ├── validate_format.c
│   │   ├── validate_lines.c
│   │   ├── validate_sp_pl_cy.c
│   │   └── validate_structure.c
│   │
│   ├── mlx/
│   │   ├── mlx_init.c
│   │   ├── mlx_image.c
│   │   ├── mlx_events.c
│   │   └── mlx_cleanup.c
│   │
│   ├── app/
│   │   ├── app.c
│   │   ├── app_run.c
│   │   ├── cleanup.c
│   │   └── main.c
│   │
│   ├── get_next_line/
│   │   ├── get_next_line.c
│   │   └── get_next_line_utils.c
│   │
│   ├── utils/
│   │   ├── splitting.c
│   │   ├── utils.c
│   │   └── utils_for_debug.c
│   │
│   ├── main.c
│   └── mlx_utils/
│       └── utils.c
│
├── rt_files/
│   └── sample.rt
│
└── libft/
```

### 補足

`src/main.c` と `src/mlx_utils/utils.c` は旧構成のファイルとして現在も残っている。
現在の新しい構成では、実行入口は `src/app/main.c`、MiniLibX処理は `src/mlx/` に分割している。

---

## Header Responsibilities

| Header | Responsibility |
|---|---|
| `vec3.h` | `t_vec3` とベクトル計算関数 |
| `object.h` | `t_color`, Sphere, Plane, Cylinder, `t_object` |
| `scene.h` | Ray, Camera, Ambient, Light, Hit, Scene |
| `image.h` | Rendererが使用するMiniLibX非依存の画像バッファ `t_image` |
| `render.h` | Ray生成 / Intersection / Lighting / Color / Rendering |
| `parser.h` | Parserの関数宣言と `parse_scene()` |
| `minirt.h` | 共通定数・マクロ、libft、GNL、Parser内部共通要素、`t_element_counts` |
| `app.h` | `t_app` とApplication全体の初期化・実行・解放 |
| `platform.h` | MiniLibX側の状態 `t_platform` / `t_mlx_image` とPlatform API |
| `get_next_line.h` | GNL |
| `utils.h` | 共通Utility / Debug Utility |

---

## Main Structures

### `t_app`

Application全体の状態をまとめる。

```c
typedef struct s_app
{
    t_scene     scene;
    t_image     image;
    t_platform  platform;
}   t_app;
```

役割：

```text
t_scene
  └─ Parser / Ray Tracing用データ

t_image
  └─ Rendererが計算した最終ピクセルデータ

t_platform
  └─ MiniLibX / Window / MLX Image
```

### `t_image`

MiniLibXに依存しない描画結果用バッファ。

```c
typedef struct s_image
{
    int width;
    int height;
    int *pixels;
}   t_image;
```

Rendererはこの構造体へ描画し、MiniLibX関数を直接呼ばない。

### `t_platform`

MiniLibX固有の状態を保持する。

```c
typedef struct s_platform
{
    void        *mlx;
    void        *window;
    t_mlx_image image;
}   t_platform;
```

---

## Header Dependency

主な依存関係：

```text
vec3.h
   ↑
   │
object.h
   ↑
   │
scene.h
   ↑
   ├───────────────┐
   │               │
render.h        parser.h
   │
   └────→ image.h


image.h
   ↑
   │
platform.h


scene.h ───────┐
image.h ───────┼──→ app.h
platform.h ────┘


minirt.h
   ├────→ parser.h
   ├────→ get_next_line.h
   ├────→ utils.h
   └────→ libft.h
```

### 依存関係の意図

- `vec3.h` は最下層の数学データとして使用する
- `object.h` は `vec3.h` を使用する
- `scene.h` は `object.h` を使用する
- `render.h` は `scene.h` と `image.h` を使用する
- `parser.h` はScene/Objectを構築するため `scene.h` / `object.h` を使用する
- `platform.h` は描画済みの `t_image` をMiniLibXへ転送するため `image.h` を使用する
- `app.h` がScene / Image / Platformをまとめる

---

## Source Responsibilities

### `src/app/`

Application全体の制御を担当する。

```text
main.c
   ↓
app_run.c
   ├─ Parser
   ├─ Renderer
   ├─ Platform
   └─ Cleanup
```

- `main.c` : 引数チェック後に `app_run()` を呼ぶ
- `app.c` : `t_app` 初期化とGraphics初期化
- `app_run.c` : miniRT全体の実行フロー
- `cleanup.c` : Scene / Image / Platformの解放

### `src/render/`

MiniLibXを知らず、Ray Tracingと画像生成を担当する。

- `camera_ray.c` : CameraからRayを生成
- `ray_color.c` : Rayの色を決定
- `lighting.c` : Ambient / Diffuse lighting
- `color.c` : `t_vec3` の色を整数RGBへ変換
- `image.c` : `t_image` の確保・解放・pixel書き込み
- `render.c` : 全pixelについてRay Tracingを実行

### `src/object/`

ObjectとのIntersection処理を担当する。

- `sphere.c` : Sphereとの交差判定
- `object.c` : Scene内Objectを走査して最も近いHitを探す処理

現状、`find_nearest_hit()` のObject別分岐で実装されているのはSphereのみ。

### `src/parser/`

`.rt` ファイルを読み込み、検証後に `t_scene` を構築する。

入口：

```c
int parse_scene(t_scene *scene, const char *filename);
```

大きな流れ：

```text
.rt file
   ↓
read_valid_lines()
   ↓
validate_structure()
   ↓
validate_lines()
   ↓
t_scene
```

### `src/mlx/`

MiniLibX固有処理を担当する。

- `mlx_init.c` : MLX / Window / MLX Image初期化
- `mlx_image.c` : `t_image` をMLX Imageへ転送しWindowへ表示
- `mlx_events.c` : ESC / Window Close / `mlx_loop()`
- `mlx_cleanup.c` : MLXリソース解放

---

## Runtime Flow

現在のApplication全体の流れ：

```text
main()
   ↓
check_args()
   ↓
app_run(filename)
   ↓
app_init()
   ↓
parse_scene()
   ↓
t_scene
   ↓
app_init_graphics()
   ├─ image_init()
   └─ platform_init()
   ↓
render(scene, image)
   ↓
Camera
   ↓
Ray
   ↓
Intersection
   ↓
Lighting
   ↓
Color
   ↓
t_image
   ↓
platform_present()
   ↓
MLX Image
   ↓
Window
   ↓
platform_start_loop()
   ↓
Event Loop
```

---

## Renderer / MiniLibX Separation

今回の構成変更で重要な点。

### Renderer側

```text
t_scene
   ↓
render()
   ↓
t_image
```

Rendererは `mlx_pixel_put()` や `mlx_put_image_to_window()` を直接呼ばない。

### Platform側

```text
t_image
   ↓
platform_present()
   ↓
t_mlx_image
   ↓
mlx_put_image_to_window()
```

これにより、Ray Tracing処理とWindow処理を分離している。

---

## Current Implementation Status

`miniRT(6).zip` 時点の実装状況。

### 実装済み

- `.rt` の読み込みとParser入口 `parse_scene()`
- `t_app` によるScene / Image / Platformの統合
- RendererとMiniLibXの分離
- `t_image` の確保・pixel書き込み・解放
- MLX初期化 / 描画転送 / Event Loop / Cleanupの分割
- SphereのRay Intersection
- Ambient lighting
- Diffuse lighting
- Scene内Objectを走査する `find_nearest_hit()`

### 現在まだ途中の部分

- `ray_color.c` は現在 `find_nearest_hit()` を使用せず、`scene->objects` の先頭ObjectをSphereとして直接 `hit_sphere()` に渡している
- `find_nearest_hit()` 自体は存在するが、Object別IntersectionはSphereのみ対応
- PlaneのIntersectionは未実装
- CylinderのIntersectionは未実装
- Camera Rayは現在、CameraがZ軸正方向 `(0, 0, 1)` を向いている前提で計算しており、`camera.direction` をRay方向へ反映する処理は未実装
- Shadow判定は未実装
- `src/calc_vector/` は現在の実ファイル名であり、`src/math/` への変更はまだ反映されていない
- 旧構成の `src/main.c` と `src/mlx_utils/utils.c` がまだ残っている

---

## Common Constants

現在、共通定数は `minirt.h` にまとめている。

主な定数：

```c
#define TRUE 1
#define FALSE 0
#define NO_ERROR 0
#define HAS_ERROR 1

#define EPSILON 1e-6
#define M_PI 3.14159265358979323846

#define WIDTH 800
#define HEIGHT 600

#define KEY_ESC 65307
```

Parser用のID・範囲チェック用定数も `minirt.h` に置いている。

---

## Current Architecture Summary

```text
.rt File
   ↓
Parser
   ↓
t_scene
   │
   └──────────────┐
                  ↓
              Renderer
                  ↓
               t_image
                  ↓
              Platform
                  ↓
               MiniLibX
                  ↓
                Window
```

Application層が各モジュールを接続する。

```text
          app
     ┌─────┼─────┐
     ↓     ↓     ↓
  Parser Renderer Platform
     ↓     ↓     ↓
  t_scene t_image MiniLibX
```

ParserとRenderer、RendererとMiniLibXを直接結合せず、Application層を中心に役割を分離する方針。

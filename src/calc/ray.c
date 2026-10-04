/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 18:24:28 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/04 18:13:45 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdio.h>
/**
 * @brief カメラの視点から指定ピクセル (x, y) に向かうレイ（光線）を生成する
 * 
 * 2D の画像ピクセル座標 (x, y) を、アスペクト比を考慮した 3D 空間上の
 * スクリーン平面（ビューポート）の座標へとマッピングし、カメラ位置 (cam->position) から
 * その点へ向かう正規化された方向ベクトルを持つレイを構築する。
 * （※現状はカメラが Z 軸正方向 (0, 0, 1) を向いている前提）
 *
 * @param x スクリーンの水平ピクセル座標 (0 〜 WIDTH - 1)
 * @param y スクリーンの垂直ピクセル座標 (0 〜 HEIGHT - 1)
 * @param cam カメラ情報（視点位置、向き、ビューポート幅など）を保持する構造体
 * @return 生成されたレイ（原点 origin と正規化された方向ベクトル dir）
 */
t_ray	create_camera_ray(int x, int y, const t_camera *cam)
{
	t_ray	ray;
	double	viewport_width;
	double	viewport_height;
	double	screen_x;
	double	screen_y;

	viewport_width = 2.0 * tan((cam->fov * M_PI / 180.0) / 2.0);
	viewport_height = viewport_width * ((double)HEIGHT / WIDTH);
	screen_x = (((double)x / WIDTH) - 0.5) * viewport_width;
	screen_y = (0.5 - ((double)y / HEIGHT)) * viewport_height;
	ray.origin = cam->position;
	ray.direction = vec_normalize(vec_new(screen_x, screen_y, 1.0));
	return (ray);
}

/**
 * @brief 物体に照射される環境光（Ambient）による反射色を計算する
 * 物体の固有色と環境光の色を成分ごとに乗算 (vec_mult_vec) し、
 * 強度比率 (ratio) で定数倍 (vec_mult) する。
 *
 * @param obj_color 物体の固有色
 * @param ambient Ambient
 * @return 環境光によって反射されるRGBカラーベクトル
 */
static t_vec3	calc_ambient_color(t_color obj_color, const t_ambient *ambient)
{
	t_vec3	c_obj;
	t_vec3	c_amb;
	t_vec3	color;

	c_obj = color_to_vec(obj_color);
	c_amb = color_to_vec(ambient->color);
	color = vec_mult_vec(c_obj, c_amb);
	return (vec_mult(color, ambient->ratio));
}

/**
 * @brief 球体上の衝突点における拡散反射光（Diffuse）による反射色を計算する
 * 衝突点の法線ベクトル (hit->normal) と点光源方向の内積から拡散係数を求め、
 * 物体の固有色 (hit->color) と光源色・明るさを掛け合わせて反射色を算出する。
 * 
 * @param hit   衝突情報（衝突座標 point、法線ベクトル normal、物体色 color）
 * @param light 点光源データポインタ（位置 position、色 color、明るさ brightness）
 * @return 拡散反射光によって反射される RGB カラーベクトル
 */
static t_vec3	calc_diffuse_color(const t_hit *hit, const t_light *light)
{
	t_vec3	light_dir;
	t_vec3	c_obj;
	t_vec3	c_light;
	double	diff;

	light_dir = vec_normalize(vec_sub(light->position, hit->point));
	diff = vec_dot(hit->normal, light_dir);
	if (diff < 0.0)
		diff = 0.0;
	c_obj = color_to_vec(hit->color);
	c_light = color_to_vec(light->color);
	return (vec_mult_vec(c_obj, vec_mult(c_light, diff * light->brightness)));
}

/**
 * @brief レイを飛ばし、ピクセルに描画する最終的な色を決定する
 * 交差判定を行い、背景なら黒、衝突時はambient+diffuseを合成して
 * クランプ処理（上限 1.0）を行った色を返す。
 *
 * @param ray 判定対象のレイ
 * @param scene シーン全体のデータポインタ
 * @return 最終的なピクセルのRGBカラーベクトル
 */
t_vec3	ray_color(t_ray ray, const t_scene *scene)
{
	t_hit	hit;
	t_vec3	ambient_color;
	t_vec3	diffuse_color;

	if (!hit_sphere(ray, &scene->objects->shape.sphere, &hit))
	{
		return (vec_new(0.0, 0.0, 0.0));
	}
	hit.color = scene->objects->color;
	ambient_color = calc_ambient_color(hit.color, &scene->ambient);
	diffuse_color = calc_diffuse_color(&hit, &scene->light);
	return (vec_clamp(vec_add(ambient_color, diffuse_color), 0.0, 1.0));
}

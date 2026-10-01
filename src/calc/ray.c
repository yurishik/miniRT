/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 18:24:28 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/01 14:16:32 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/**
 * @brief カメラの視点から指定ピクセル (x, y) に向かうレイ（光線）を生成する
 * 
 * 2D の画像ピクセル座標 (x, y) を、アスペクト比を考慮した 3D 空間上の
 * スクリーン平面（ビューポート）の座標へとマッピングし、カメラ位置 (cam->pos) から
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
	double	viewport_height;
	double	screen_x;
	double	screen_y;

	viewport_height = cam->viewport_width * ((double)HEIGHT / WIDTH);
	screen_x = (((double)x / WIDTH) - 0.5) * cam->viewport_width;
	screen_y = (0.5 - ((double)y / HEIGHT)) * viewport_height;
	ray.origin = cam->pos;
	ray.dir = vec_normalize(vec_new(screen_x, screen_y, 1.0));
	return (ray);
}

/**
 * @brief レイと球体の交差判定を行い、最も手前の交点までの距離tを計算する
 * 
 * 球面の方程式とレイの直線方程式から2次方程式を立て、判別式を用いて衝突判定を行う。
 * レイの方向ベクトルが正規化済み (|ray.dir| = 1.0) であることを前提に、
 * 2次方程式の偶数公式 (b = 2h) を用いて割り算を排除し計算を最適化している。
 * 自己交差（シャドウアクネ等）を防止するため、EPSILON 以上の正の解のみを採用する。
 *
 * @param ray 判定対象のレイ
 * @param sp 判定対象の球体データ（中心座標、半径など）
 * @return 衝突した場合はカメラから交点までの距離t（最小の正数）、衝突しない場合は-1.0
 */
static double	hit_sphere(t_ray ray, const t_sphere *sp)
{
	t_vec3	oc;
	double	h;
	double	d;
	double	sqrtd;
	double	t;

	oc = vec_sub(ray.origin, sp->center);
	h = vec_dot(oc, ray.dir);
	d = h * h - (vec_dot(oc, oc) - (sp->radius * sp->radius));
	if (d < 0.0)
		return (-1.0);
	sqrtd = sqrt(d);
	t = -h - sqrtd;
	if (t > EPSILON)
		return (t);
	t = -h + sqrtd;
	if (t > EPSILON)
		return (t);
	return (-1.0);
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
static t_vec3	calc_ambient_color(t_vec3 obj_color, const t_ambient *ambient)
{
	t_vec3	color;

	color = vec_mult_vec(obj_color, ambient->color);
	return (vec_mult(color, ambient->ratio));
}

/**
 * @brief 球体上の衝突点における拡散反射光（Diffuse）による反射色を計算する
 * 法線と光源方向の内積から拡散係数を求め、物体の固有色に (diff * brightness) を定数倍して色を算出する。
 *
 * @param hit_pos 球体表面の衝突座標
 * @param sp 衝突した球体データポインタ
 * @param light 点光源データポインタ
 * @return 拡散反射光によって反射される RGB カラーベクトル
 */
static t_vec3	calc_diffuse_color(t_vec3 hit_pos, const t_sphere *sp,
					const t_light *light)
{
	t_vec3	normal;
	t_vec3	light_dir;
	double	diff;

	normal = vec_normalize(vec_sub(hit_pos, sp->center));
	light_dir = vec_normalize(vec_sub(light->pos, hit_pos));
	diff = vec_dot(normal, light_dir);
	if (diff < 0.0)
		diff = 0.0;
	return (vec_mult(sp->color, diff * light->brightness));
}

/**
 * @brief レイを飛ばし、ピクセルに描画する最終的な色を決定する
 * 交差判定を行い、背景なら黒、衝突時はambient+diffuseを合成して
 * クランプ処理（上限 1.0）を行った色を返す。
 *
 * @param ray 判定対象のレイ
 * @param vars シーン全体のデータポインタ
 * @return 最終的なピクセルのRGBカラーベクトル
 */
t_vec3	ray_color(t_ray ray, const t_vars *vars)
{
	double	t;
	t_vec3	hit_pos;
	t_vec3	ambient_color;
	t_vec3	diffuse_color;

	t = hit_sphere(ray, &vars->sp);
	if (t < 0.0)
		return (vec_new(0.0, 0.0, 0.0));
	hit_pos = vec_add(ray.origin, vec_mult(ray.dir, t));
	ambient_color = calc_ambient_color(vars->sp.color, &vars->ambient);
	diffuse_color = calc_diffuse_color(hit_pos, &vars->sp, &vars->light);
	return (vec_clamp(vec_add(ambient_color, diffuse_color), 0.0, 1.0));
}

#include "render.h"
#include "minirt.h"
#include <math.h>

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

	/* TODO: Camera orientation
	 * 現在はカメラが (0, 0, 1) を向いている前提。
	 * cam->direction から forward / right / up を作り、
	 * screen_x / screen_y をワールド座標系のray方向へ変換する。
	 */

	ray.direction = vec_normalize(vec_new(screen_x, screen_y, 1.0));
	return (ray);
}

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

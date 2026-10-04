/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:24:35 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/04 18:00:00 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief so_longから、画面描画用のデータを作成する
 *
 */
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief 色のベクトルデータからRGB情報のintに変換する
 *
 */
int	color_to_int(t_vec3 c)
{
	int	r;
	int	g;
	int	b;

	r = (int)(fmin(fmax(c.x, 0.0), 1.0) * 255.0);
	g = (int)(fmin(fmax(c.y, 0.0), 1.0) * 255.0);
	b = (int)(fmin(fmax(c.z, 0.0), 1.0) * 255.0);
	return ((r << 16) | (g << 8) | b);
}

/**
 * @brief 各ピクセルで計算して描画用のデータを作成する
 *
 * @param 描画用のデータの仮の構造体、一旦main.c内で固定値を設定している
 */
void	render(t_vars *vars)
{
	t_ray		ray;
	t_vec3		color;
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = create_camera_ray(x, y, &(vars->scene).camera);
			color = ray_color(ray, &(vars->scene));
			my_mlx_pixel_put(&(vars->img), x, y, color_to_int(color));
			x++;
		}
		y++;
	}
}

/**
 * @brief 描画バッファをウィンドウに転送し、イベントループを開始する
 * 
 */
void	start_mlx_loop(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img_ptr, 0, 0);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 17, close_window, vars);
	mlx_loop(vars->mlx);
}

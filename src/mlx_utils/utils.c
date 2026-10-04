/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:26:50 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/01 13:51:44 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief so_longから、GUI環境と画像バッファの初期化
 *
 */
int	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "miniRT");
	if (!vars->win)
		return (0);
	vars->img.img_ptr = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img.img_ptr)
		return (0);
	vars->img.addr = mlx_get_data_addr(vars->img.img_ptr,
			&vars->img.bpp, &vars->img.line_len, &vars->img.endian);
	return (1);
}

/**
 * @brief so_longから、リソースの解放とプロセスの正常終了
 *
 */
int	close_window(t_vars *vars)
{
	if (vars->img.img_ptr)
		mlx_destroy_image(vars->mlx, vars->img.img_ptr);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

/**
 * @brief so_longから、キーボード入力イベントの処理(ESC飲みに限定)
 *
 */
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		close_window(vars);
	return (0);
}

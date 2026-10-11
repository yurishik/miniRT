/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 17:11:25 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/11 17:11:26 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "minirt.h"
#include "mlx.h"
#include <stdlib.h>

/**
 * @brief 描画バッファをウィンドウに転送し、イベントループを開始する
 * 
 */
static int	close_app(t_app *app)
{
	app_cleanup(app);
	exit(0);
	return (0);
}

static int	key_hook(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
		return (close_app(app));
	return (0);
}

int	platform_start_loop(t_app *app)
{
	mlx_hook(app->platform.window, 2, 1L << 0, key_hook, app);
	mlx_hook(app->platform.window, 17, 0, close_app, app);
	mlx_loop(app->platform.mlx);
	return (0);
}

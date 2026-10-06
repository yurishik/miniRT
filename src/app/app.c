/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 14:24:16 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/06 17:34:08 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "minirt.h"
#include <stdlib.h>

void	app_init(t_app *app)
{
	app->scene.objects = NULL;
	app->image.width = 0;
	app->image.height = 0;
	app->image.pixels = NULL;
	app->platform.mlx = NULL;
	app->platform.window = NULL;
	app->platform.image.ptr = NULL;
	app->platform.image.addr = NULL;
}

int	app_init_graphics(t_app *app)
{
	if (image_init(&app->image, WIDTH, HEIGHT) != 0)
		return (1);
	if (platform_init(&app->platform, WIDTH, HEIGHT) != 0)
		return (1);
	return (0);
}

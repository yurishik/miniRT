/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 17:11:20 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/18 17:45:37 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platform.h"
#include "mlx.h"
#include <stdlib.h>

#ifdef __linux__

static void	destroy_mlx_display(void *mlx)
{
	if (mlx)
	{
		mlx_destroy_display(mlx);
		free(mlx);
	}
}

#else

static void	destroy_mlx_display(void *mlx)
{
	(void)mlx;
}

#endif

void	platform_destroy(t_platform *platform)
{
	if (!platform)
		return ;
	if (platform->mlx && platform->image.ptr)
		mlx_destroy_image(platform->mlx, platform->image.ptr);
	if (platform->mlx && platform->window)
		mlx_destroy_window(platform->mlx, platform->window);
	destroy_mlx_display(platform->mlx);
	platform->image.ptr = NULL;
	platform->image.addr = NULL;
	platform->window = NULL;
	platform->mlx = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 17:11:20 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/11 17:11:55 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platform.h"
#include "mlx.h"
#include <stdlib.h>

void	platform_destroy(t_platform *platform)
{
	if (!platform)
		return ;
	if (platform->mlx && platform->image.ptr)
		mlx_destroy_image(platform->mlx, platform->image.ptr);
	if (platform->mlx && platform->window)
		mlx_destroy_window(platform->mlx, platform->window);
#ifdef __linux__
	if (platform->mlx)
	{
		mlx_destroy_display(platform->mlx);
		free(platform->mlx);
	}
#endif
	platform->image.ptr = NULL;
	platform->image.addr = NULL;
	platform->window = NULL;
	platform->mlx = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 17:00:46 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/11 17:00:48 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

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

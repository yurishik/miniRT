/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 23:03:44 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/06 20:14:54 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLATFORM_H
# define PLATFORM_H

# include "image.h"

typedef struct s_mlx_image
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_image;

typedef struct s_platform
{
	void		*mlx;
	void		*window;
	t_mlx_image	image;
}	t_platform;

struct	s_app;

int		platform_init(t_platform *platform, int width, int height);
void	platform_destroy(t_platform *platform);
void	platform_present(t_platform *platform, const t_image *image);
int		platform_start_loop(struct s_app *app);

#endif

// platform_init()
//     ↓
// MLX初期化

// platform_present()
//     ↓
// t_image → MLX

// platform_start_loop()
//     ↓
// イベント / mlx_loop

// platform_destroy()
//     ↓
// MLX解放

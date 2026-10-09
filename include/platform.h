/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 23:03:44 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/07 18:59:37 by hisasano         ###   ########.fr       */
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
} t_mlx_image;

// image.ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
// image.addr = mlx_get_data_addr(
//     image.ptr,
//     &image.bits_per_pixel,
//     &image.line_length,
//     &image.endian
// );

typedef struct s_platform
{
	void		*mlx;
	void		*window;
	t_mlx_image	image;
} t_platform;

struct s_app;

int		platform_init(t_platform *platform, int width, int height);
void	platform_destroy(t_platform *platform);
void	platform_present(t_platform *platform, const t_image *image);
int		platform_start_loop(struct s_app *app);

#endif

// t_platform
// │
// ├── mlx
// │    └─ MiniLibX
// │
// ├── window
// │    └─ wondow
// │
// └── image
//      ├─ ptr
//      ├─ addr
//      ├─ bits_per_pixel
//      ├─ line_length
//      └─ endian

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

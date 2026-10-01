/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:14:12 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/01 13:56:56 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

typedef struct s_vars	t_vars;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

// utils.c
int		init_mlx(t_vars *vars);
int		close_window(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);

// render.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		color_to_int(t_vec3 c);
void	render(t_vars *vars);
void	start_mlx_loop(t_vars *vars);

#endif

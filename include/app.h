/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 14:32:11 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/06 20:13:09 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# include "scene.h"
# include "image.h"
# include "platform.h"

typedef struct s_app
{
	t_scene		scene;
	t_image		image;
	t_platform	platform;
}	t_app;

void	app_init(t_app *app);
int		app_init_graphics(t_app *app);
int		app_run(const char *filename);
void	app_cleanup(t_app *app);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 23:22:47 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/22 20:18:33 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "parser.h"
#include "render.h"

/**
 * @brief Load a scene, render it, and start the graphics event loop.
 *
 * Initializes the application, parses the scene file, sets up graphics,
 * renders the image, and displays it. Cleans up on failure.
 *
 * @param filename Path to the scene description file.
 * @return 0 on success, or 1 if initialization or rendering fails.
 */
int	app_run(const char *filename)
{
	t_app	app;

	app_init(&app);
	if (parse_scene(&app.scene, filename) != 0)
		return (app_cleanup(&app), 1);
	if (app_init_graphics(&app) != 0)
		return (app_cleanup(&app), 1);
	if (render(&app.scene, &app.image) != 0)
		return (app_cleanup(&app), 1);
	platform_present(&app.platform, &app.image);
	platform_start_loop(&app);
	app_cleanup(&app);
	return (0);
}

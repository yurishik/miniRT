/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 23:22:47 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/06 17:43:57 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include "parser.h"
#include "render.h"

int	app_run(const char *filename)
{
	t_app	app;

	app_init(&app);
	// App: 初期化

	if (parse_scene(&app.scene, filename) != 0)
		return (app_cleanup(&app), 1);
	// Parser: .rt -> t_scene
      //nopposann

	if (app_init_graphics(&app) != 0)
		return (app_cleanup(&app), 1);
	// Platform: MLX / Window / Image 初期化
    //sasano

	if (render(&app.scene, &app.image) != 0)
		return (app_cleanup(&app), 1);
	// Renderer: t_scene -> t_image
    //
	
	platform_present(&app.platform, &app.image);
	platform_start_loop(&app);
	// Platform: Event / Loop

	app_cleanup(&app);
	// App: 全リソース解放

	return (0);
}

// Scene
// Image
// Parserの入口
// Rendererの入口
// Platformの入口
// cleanup

// minirt(filename)
//     ↓
// scene初期化
//     ↓
// parse_scene()
//     ↓
// app / mlx 初期化
//     ↓
// render_scene()
//     ↓
// イベント設定
//     ↓
// mlx_loop()
//     ↓
// cleanup
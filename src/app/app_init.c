/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 14:24:16 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/04 14:37:34 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void    app_init(t_app *app)
{
    app->scene.objects = NULL;
	app->image.width = 0;
	app->image.height = 0;
	app->image.pixels = NULL;
	app->platform.mlx = NULL;
	app->platform.win = NULL;
}

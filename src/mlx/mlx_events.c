#include "app.h"
#include "minirt.h"
#include "mlx.h"
#include <stdlib.h>

/**
 * @brief 描画バッファをウィンドウに転送し、イベントループを開始する
 * 
 */

 static int	close_app(t_app *app)
{
	app_cleanup(app);
	exit(0);
	return (0);
}

static int	key_hook(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
		return (close_app(app));
	return (0);
}

int	platform_start_loop(t_app *app)
{
	mlx_hook(app->platform.window, 2, 1L << 0, key_hook, app);
	mlx_hook(app->platform.window, 17, 0, close_app, app);
	mlx_loop(app->platform.mlx);
	return (0);
}

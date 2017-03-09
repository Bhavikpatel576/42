
#include <mlx.h>

int main()
{
	void *mlx;
	void *win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000,1000, "mlx 42");
	mlx_loop(mlx);
	return(0);
}

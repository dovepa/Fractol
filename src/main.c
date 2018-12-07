/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/06 21:10:30 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int ft_exit(t_fract *fract)
{
	(void)fract;
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_pixel(unsigned int *data, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	data[y * WIN_WIDTH + x] = color;
	return ;
}

int ft_mouse(int x, int y, t_fract *fract)
{
	fract->mna->x = ((double)x / WIN_WIDTH) * (fract->val->xr - fract->val->xl);
	fract->mna->y = (double)y / WIN_HEIGHT * (fract->val->yb - fract->val->yt);
	ft_putendl("x");
	ft_putnbr(fract->mna->x);
	ft_putendl("");
	ft_putendl("y");
	ft_putnbr(fract->mna->y);
	ft_putendl("");
	ft_julia(fract);
	return (0);
}

int ft_key(int key, t_fract *fract)
{
	(void)fract;
	if (key == ESC_KEY)
		ft_exit(fract);
	if (key == MORE_KEY || key == LESS_KEY)
	{
		if (fract->mna->zoom <= 1 )
			fract->mna->zoom = 2.0;
		fract->mna->zoom += (2 * (key % 10) - 17)*20;
		ft_julia(fract);
	}
	if (key == Q_KEY || key == W_KEY)
	{
		if (fract->mna->imax <= 1 )
			fract->mna->imax = 2.0;
		fract->mna->imax +=( 2 * (key % 10) - 5)*5;
		ft_julia(fract);
	}
	if (key == RIGHT_KEY || key == LEFT_KEY)
	{
		fract->mna->x += (double)((2 * (key % 120) - 7) / 10.0);
		ft_julia(fract);
	}
	if (key == UP_KEY || key == DOWN_KEY)
	{
		fract->mna->y += (double)((2 * (key % 120) - 11) / 10.0);
		ft_julia(fract);
	}
	if (key == Q_KEY || key == W_KEY)
	{
		if (fract->mna->imax <= 1 )
			fract->mna->imax = 2.0;
		fract->mna->imax +=( 2 * (key % 10) - 5)*5;
		ft_julia(fract);
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_fract *fract;
	char *str1;

	if (argc != 2 || (ft_strcmp((const char*)argv[1], (const char*)"julia") != 0 \
	&& ft_strcmp((const char*)argv[1], (const char*)"mandelbrot") != 0))
		return (ft_usage("\x1b[1m\x1b[41m ./fractol : julia / mandelbrot / autre \x1b[0m"));

	if ((fract = ft_memalloc(sizeof(t_fract))) == NULL)
		return (1);
	if ((fract->img = ft_memalloc(sizeof(t_mlximg))) == NULL)
		return (1);
	if ((fract->mna = ft_memalloc(sizeof(t_manda))) == NULL)
		return (1);
	if ((fract->val = ft_memalloc(sizeof(t_val))) == NULL)
		return (1);

	str1 = ft_strjoin("42 Fract'ol : ", argv[1]);
	
	if (ft_init(str1, fract) == 1)
		return 1;
	fract->mna->zoom = 500;
	fract->mna->imax = 50;
	fract->mna->x = 0;
	fract->mna->y = 0;

	if (ft_strcmp((const char*)argv[1], (const char*)"julia") == 0)
		if (ft_julia(fract) == 1)
			return (ft_strerror("\x1b[1m\x1b[41m error \x1b[0m"));

	if (ft_strcmp((const char*)argv[1], (const char*)"mandelbrot") == 0)
		if (ft_mandelbrot(fract) == 1)
			return (ft_strerror("\x1b[1m\x1b[41m error \x1b[0m"));

	mlx_key_hook(fract->win_ptr, ft_key, fract);
	mlx_hook(fract->win_ptr, 6, 1L << 6, ft_mouse, fract);
	mlx_hook(fract->win_ptr, 17, 0, ft_exit, fract);
	mlx_loop(fract->mlx_ptr);
	return (0);
}

	


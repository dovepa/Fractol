/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/18 12:11:23 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int		ft_expose(t_fract *fract)
{
	ft_thread(fract);
	return (0);
}

int		ft_exit(t_fract *fract)
{
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_initval(t_fract *fract)
{
	fract->mna->zoom = 250;
	fract->mna->imax = 50;
	fract->mna->color = 0;
	fract->mna->j = 0;
	if (fract->fct == MNBR || fract->fct == TNBR)
	{
		fract->mna->xmin = -2.3;
		fract->mna->ymin = -1.6;
	}
	else if (fract->fct == BNBR)
	{
		fract->mna->xmin = -2.4;
		fract->mna->ymin = -2.2;
	}
	else if (fract->fct == JNBR)
	{
		fract->mna->xmin = -2;
		fract->mna->ymin = -1.6;
	}
	ft_expose(fract);
	return ;
}

int		main(int argc, char **argv)
{
	t_fract *fract;

	fract = NULL;
	fract = ft_infract(fract);
	if (argc == 2 && ((ft_strcmp((const char*)argv[1], (const char*)"julia")\
	== 0) || (ft_strcmp((const char*)argv[1], (const char*)"mandelbrot") \
	== 0) || (ft_strcmp((const char*)argv[1], (const char*)"burningship") == 0)\
	|| (ft_strcmp((const char*)argv[1], (const char*)"tricorn") == 0)))
		fract->fct = ft_strlen((const char*)argv[1]);
	else
		return (ft_usage("./fractol : julia mandelbrot burningship tricorn"));
	if (ft_init(argv[1], fract) == 1)
		return (ft_strerror("\x1b[1m\x1b[41m  --- Mlx init error --- \x1b[0m"));
	ft_initval(fract);
	ft_expose(fract);
	mlx_mouse_hook(fract->win_ptr, ft_scroll, fract);
	mlx_expose_hook(fract->win_ptr, ft_expose, fract);
	mlx_key_hook(fract->win_ptr, ft_key, fract);
	mlx_hook(fract->win_ptr, 6, 1L << 6, ft_mouse, fract);
	mlx_hook(fract->win_ptr, 17, 0, ft_exit, fract);
	mlx_hook(fract->win_ptr, 2, 0, ft_movearrow, fract);
	mlx_loop(fract->mlx_ptr);
	return (0);
}

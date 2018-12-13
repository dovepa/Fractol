/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:31:48 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/13 01:36:29 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"


int ft_findft(t_fract *fract)
{
	if (fract->fct == MNBR)
		return(ft_mandelbrot(fract));
	if (fract->fct == JNBR)
		return(ft_julia(fract));
	if (fract->fct == BNBR)
		return(ft_burningship(fract));
	if (fract->fct == TNBR)
		return(ft_tricorn(fract));
	return (0);
}

static void ft_help(void)
{
	ft_putendl("HELP FOR FRACTOL");
	ft_putendl("For zoom : - and +");
	ft_putendl("and Scroll wheel");
	ft_putendl("Change Iteration : q(-) and w(+)");
	ft_putendl("Move : Use arrow");
	ft_putendl("Quit : Esc");
	return;
}

int	main(int argc, char **argv)
{
	t_fract *fract;

	fract = NULL;
	fract = ft_infract(fract);

	if (argc == 2 && ((ft_strcmp((const char*)argv[1], (const char*)"julia") == 0) || \
	(ft_strcmp((const char*)argv[1], (const char*)"mandelbrot") == 0) || \
	(ft_strcmp((const char*)argv[1], (const char*)"burningship") == 0) || \
	(ft_strcmp((const char*)argv[1], (const char*)"tricorn") == 0)))
		fract->fct = ft_strlen((const char*)argv[1]);
	else
		return (ft_usage("\x1b[1m\x1b[41m ./fractol : julia / mandelbrot / burningship / tricorn\x1b[0m"));

	if (ft_init(argv[1], fract) == 1)
		return (ft_strerror("\x1b[1m\x1b[41m  --- Mlx init error --- \x1b[0m"));

	ft_help();
	if (fract->fct == JNBR)
	{
		fract->val->xmin = -1.7;
		fract->val->xmax = 2.0;
		fract->val->ymin = -1.4;
		fract->val->ymax = 1.2;
	}
	else
	{
		fract->val->xmin = -2.1;
		fract->val->xmax = 0.6;
		fract->val->ymin = -1.4;
		fract->val->ymax = 1.2;
	}
	ft_findft(fract);
	mlx_mouse_hook(fract->win_ptr, ft_scroll, fract);
	mlx_key_hook(fract->win_ptr, ft_key, fract);
	mlx_hook(fract->win_ptr, 6, 1L << 6, ft_mouse, fract);
	mlx_hook(fract->win_ptr, 17, 0, ft_exit, fract);
	mlx_hook(fract->win_ptr, 2, 0, ft_movearrow, fract);
	mlx_loop(fract->mlx_ptr);
	return (0);
}




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 02:03:42 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/09 10:35:15 by dpalombo         ###   ########.fr       */
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


int ft_mouse(int x, int y, t_fract *fract)
{
	if (fract->fct == JNBR)
	{
		fract->mna->xm = ((double)x / WIN_WIDTH) * (fract->val->xr - fract->val->xl);
		fract->mna->ym = (double)y / WIN_HEIGHT * (fract->val->yb - fract->val->yt);
		ft_julia(fract);
	}
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
		ft_findft(fract);
	}
	if (key == Q_KEY || key == W_KEY)
	{
		if (fract->mna->imax <= 1 )
			fract->mna->imax = 2.0;
		fract->mna->imax +=( 2 * (key % 10) - 5)*5;
		ft_findft(fract);
	}
	if (key == RIGHT_KEY || key == LEFT_KEY)
	{
		fract->mna->x += (double)((2 * (key % 120) - 7) / 10.0);
		ft_findft(fract);
	}
	if (key == UP_KEY || key == DOWN_KEY)
	{
		fract->mna->y += (double)((2 * (key % 120) - 11) / 10.0);
		ft_findft(fract);
	}
	if (key == Q_KEY || key == W_KEY)
	{
		if (fract->mna->imax <= 1 )
			fract->mna->imax = 2.0;
		fract->mna->imax +=( 2 * (key % 10) - 5)*5;
		ft_findft(fract);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 02:03:42 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/13 01:33:01 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int ft_exit(t_fract *fract)
{
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int		ft_scroll(int s, int x, int y, t_fract *fract)
{
	(void)x;
	(void)y;
	if (s == SCROLL_A)
	{
		fract->mna->zoom *=  1.5;
		fract->val->xmin  = ((double)(DWIN_WIDTH + fract->mna->x) / (fract->mna->zoom / 2)) / -2;
		fract->val->ymin = ((double)(DWIN_HEIGHT + fract->mna->y) / (fract->mna->zoom / 2)) / -2;
		fract->mna->imax++;
		ft_findft(fract);
	}
	if (s == SCROLL_B)
	{
		fract->mna->zoom /= 1.5;
		fract->val->xmin  = ((double)(DWIN_WIDTH + fract->mna->x) / (fract->mna->zoom / 2)) / -2;
		fract->val->ymin = ((double)(DWIN_HEIGHT + fract->mna->y) / (fract->mna->zoom / 2)) / -2;
		if (fract->mna->zoom <= 1 )
			fract->mna->zoom = 1;
		fract->mna->imax--;
		ft_findft(fract);
	}
	return (0);
}

int ft_mouse(int x, int y, t_fract *fract)
{
	if (fract->fct == JNBR)
	{
		fract->mna->xm = ((double)(x - DWIN_WIDTH) / WIN_WIDTH) * (fract->val->xmin - fract->val->xmax);
		fract->mna->ym = (double)(y - DWIN_HEIGHT) / WIN_HEIGHT * (fract->val->ymin - fract->val->ymax);
		ft_julia(fract);
	}
	return (0);
}

int ft_key(int key, t_fract *fract)
{
	if (key == ESC_KEY)
		ft_exit(fract);
	if (key == MORE_KEY)
		ft_scroll(SCROLL_A, 0, 0, fract);
	if (key == LESS_KEY)
		ft_scroll(SCROLL_B, 0, 0, fract);
	if (key == Q_KEY || key == W_KEY)
	{
		fract->mna->imax += ( 2 * (key % 10) - 5) * 10;
		if (fract->mna->imax <= 0)
			fract->mna->imax = 0;
		ft_findft(fract);
	}
	if (key == C_COLOR)
	{
		fract->mna->color++;
		if (fract->mna->color > 5 )
			fract->mna->color = 0;
		ft_findft(fract);
	}
	return (0);
}

int ft_movearrow(int key, t_fract *fract)
{
	if (key == RIGHT_KEY || key == LEFT_KEY)
	{
		fract->mna->x += (double)((2 * (key % 120) - 7) * 0.01);
		ft_findft(fract);
	}
	if (key == UP_KEY || key == DOWN_KEY)
	{
		fract->mna->y += (double)((2 * (key % 120) - 11) * 0.01);
		ft_findft(fract);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 02:03:42 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/16 03:36:37 by dpalombo         ###   ########.fr       */
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
	double mouse[2];

	mouse[0] = (double)x / fract->mna->zoom + fract->val->xmin;
	mouse[1] = (double)y / fract->mna->zoom + fract->val->ymin;
	if (s == SCROLL_A)
	{
		fract->mna->zoom *= 1.2;
		fract->val->xmin += mouse[0] - ((double)x / fract->mna->zoom + fract->val->xmin);
		fract->val->ymin += mouse[1] - ((double)y / fract->mna->zoom + fract->val->ymin);
		fract->mna->imax++;
		ft_expose(fract);
	}
	if (s == SCROLL_B)
	{
		fract->mna->zoom /= 1.2;
		fract->val->xmin += mouse[0] - ((double)x / fract->mna->zoom + fract->val->xmin);
		fract->val->ymin += mouse[1] - ((double)y / fract->mna->zoom + fract->val->ymin);
		fract->mna->imax--;
		ft_expose(fract);
	}
	return (0);
}

int ft_mouse(int x, int y, t_fract *fract)
{
	if (fract->fct == JNBR)
	{
		fract->mna->xm = (double)(x - DWIN_WIDTH) / WIN_WIDTH * (fract->val->xmin);
		fract->mna->ym = (double)(y - DWIN_HEIGHT) / WIN_HEIGHT * (fract->val->ymin);
		ft_julia(fract);
	}
	return (0);
}

int ft_key(int key, t_fract *fract)
{
	if (key == ESC_KEY)
		ft_exit(fract);
	if (key == Q_KEY || key == W_KEY)
	{
		fract->mna->imax += ( 2 * (key % 10) - 5) * 10;
		if (fract->mna->imax <= 0)
			fract->mna->imax = 0;
		ft_expose(fract);
	}
	if (key == C_COLOR)
	{
		fract->mna->color++;
		if (fract->mna->color > 5 )
			fract->mna->color = 0;
		ft_expose(fract);
	}
	return (0);
}

void	ft_initval(t_fract *fract)
{
	fract->mna->zoom = 250;
	fract->mna->imax = 50;
	fract->mna->color = 0;
	if (fract->fct == MNBR  || fract->fct == TNBR)
	{
		fract->val->xmin = - 2.3;
		fract->val->ymin = - 1.6;
	}
	else if (fract->fct == BNBR)
	{
		fract->val->xmin = - 2.4;
		fract->val->ymin = - 2.2;
	}
	else if (fract->fct == JNBR)
	{
		fract->val->xmin = - 2;
		fract->val->ymin = - 1.6;
	}
	ft_expose(fract);
	return ;
}

int ft_movearrow(int key, t_fract *fract)
{
	if (key == RIGHT_KEY || key == LEFT_KEY)
	{
		fract->val->xmin += (double)((2 * (key % 120) - 7) * 1) / fract->mna->zoom * 25;
		ft_expose(fract);
	}
	if (key == UP_KEY || key == DOWN_KEY)
	{
		fract->val->ymin -= (double)((2 * (key % 120) - 11) * 1) / fract->mna->zoom * 25;
		ft_expose(fract);
	}
	if (key == R_KEY)
		ft_initval(fract);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 02:03:42 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/18 11:54:15 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_scrollb(double *mousse, int x, int y, t_fract *fract)
{
	fract->mna->zoom /= 1.2;
	fract->mna->xmin += mousse[0] - (D(x) / fract->mna->zoom + \
	fract->mna->xmin);
	fract->mna->ymin += mousse[1] - (D(y) / fract->mna->zoom + \
	fract->mna->ymin);
	fract->mna->imax--;
	ft_expose(fract);
	return (0);
}

int			ft_scroll(int s, int x, int y, t_fract *fract)
{
	double mouse[2];

	mouse[0] = D(x) / fract->mna->zoom + fract->mna->xmin;
	mouse[1] = D(y) / fract->mna->zoom + fract->mna->ymin;
	if (s == 1 && fract->mna->fct == JNBR)
		fract->mna->j += 1;
	if (s == SCROLL_A)
	{
		fract->mna->zoom *= 1.2;
		fract->mna->xmin += mouse[0] - (D(x) / fract->mna->zoom + \
		fract->mna->xmin);
		fract->mna->ymin += mouse[1] - (D(y) / fract->mna->zoom + \
		fract->mna->ymin);
		fract->mna->imax++;
		ft_expose(fract);
	}
	if (s == SCROLL_B)
		ft_scrollb(mouse, x, y, fract);
	return (0);
}

int			ft_mouse(int x, int y, t_fract *fract)
{
	if (fract->mna->fct == JNBR && (fract->mna->j % 2) == 0)
	{
		fract->mna->xm = D((x - DWIN_WIDTH)) / WIN_WIDTH * (fract->mna->xmin);
		fract->mna->ym = D((y - DWIN_HEIGHT)) / WIN_HEIGHT * (fract->mna->ymin);
		ft_expose(fract);
	}
	return (0);
}

int			ft_key(int key, t_fract *fract)
{
	if (key == ESC_KEY)
		ft_exit(fract);
	if (key == Q_KEY || key == W_KEY)
	{
		fract->mna->imax += (2 * (key % 10) - 5) * 10;
		if (fract->mna->imax <= 0)
			fract->mna->imax = 0;
		ft_expose(fract);
	}
	if (key == C_COLOR)
	{
		fract->mna->color++;
		if (fract->mna->color > 5)
			fract->mna->color = 0;
		ft_expose(fract);
	}
	return (0);
}

int			ft_movearrow(int key, t_fract *fract)
{
	if (key == RIGHT_KEY || key == LEFT_KEY)
	{
		fract->mna->xmin += D(((2 * (key % 120) - 7) * 1)) / \
		fract->mna->zoom * 25;
		ft_expose(fract);
	}
	if (key == UP_KEY || key == DOWN_KEY)
	{
		fract->mna->ymin -= D(((2 * (key % 120) - 11) * 1)) / \
		fract->mna->zoom * 25;
		ft_expose(fract);
	}
	if (key == R_KEY)
		ft_initval(fract);
	return (0);
}

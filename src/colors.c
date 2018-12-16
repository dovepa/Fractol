/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 02:04:06 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/16 03:41:32 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_colornum(int a)
{
	int colortab[5];

	colortab[0] = PINK;
	colortab[1] = RED;
	colortab[2] = ORANGE;
	colortab[3] = BLUE;
	colortab[4] = YELLOW;
	return (colortab[a]);
}

static int		ft_pixel_color(int colorstart, t_fract *fract)
{
	int		r;
	int		g;
	int		b;
	int		colorresult;

	if (fract->val->i == 0)
		return (0x000000);
	else if (fract->val->i == fract->mna->imax)
		return (0x000000);
	else
		fract->val->i = fract->val->i / fract->mna->imax;
	r = ((int)((colorstart >> 16) & 255)) * fract->val->i * 2;
	g = ((int)((colorstart >> 8) & 255)) * fract->val->i * 2;
	b = ((int)(colorstart & 255)) * fract->val->i * 2;
	colorresult = r << 16 | g << 8 | b;
	return (colorresult);
}

static int		ft_pixel_gr(int colorstart, int colorend, t_fract *fract)
{
	int		r;
	int		g;
	int		b;
	double	dv;

	dv = fract->val->i - log(log(fract->val->z.r * fract->val->z.r + fract->val->z.i * fract->val->z.i))/log(2.0);
	if (fract->val->i == 0)
		return (WHITE);
	else if (dv == fract->mna->imax)
		return (0x000000);
	else
		dv = dv / fract->mna->imax;
	r = (((int)((colorend >> 16) & 255) + \
	(((int)((colorstart >> 16) & 255)) - ((int)((colorend >> 16) & 255))) * dv));
	g = (((int)((colorend >> 8) & 255) + \
	(((int)((colorstart >> 8) & 255)) - ((int)((colorend >> 8) & 255))) * dv));
	b = (((int)(colorend & 255) + \
	(((int)(colorstart & 255)) - ((int)(colorend & 255))) * dv));
	return ((r << 16 | g << 8 | b));
}

static int ft_multicolor(t_fract *fract)
{
	int	r;
	int	g;
	int	b;

	if (fract->val->i == fract->mna->imax)
		return (0x000000);
	r = (int)fract->val->i % 9 * 100;
	g = (int)fract->val->i % 3 * 100;
	b = (int)fract->val->i % 7 * 100;
	return (r << 16 | g << 8 | b);
}

int ft_colorpx(t_fract *fract)
{

	if (fract->mna->color == 0)
	{
		if (fract->val->i == fract->mna->imax)
			return (0x000000);
		return (ft_pixel_gr(WHITE, 0x091c36, fract));
	}
	if (fract->mna->color == 1)
		return (ft_multicolor(fract));
	if (fract->mna->color < 6)
	{
		if (fract->val->i == fract->mna->imax)
			return (0x000000);
		return (ft_pixel_color(ft_colornum(fract->mna->color - 2), fract));
	}
	else
		return (ft_multicolor(fract));
}

void	ft_pixel(unsigned int *data, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	data[y * WIN_WIDTH + x] = color;
	return ;
}

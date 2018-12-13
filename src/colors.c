/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 02:04:06 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/12 21:28:06 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static int	ft_colornum(int a)
{
	int colortab[5];

	colortab[0] = 0x091c36;
	colortab[1] = PINK;
	colortab[2] = 0x091c36;
	colortab[3] = WHITE;
	colortab[4] = YELLOW;
	return (colortab[a]);
}

static int		ft_pixel_color(int colorstart, int colorend, int i, int imax)
{
	int		r;
	int		g;
	int		b;
	double	dv;
	int		colorresult;

	if (i == 0)
		return (colorend);
	else if (i == imax)
		return (0x000000);
	else
		dv = (double)i / imax;

	r = (((int)((colorend >> 16) & 255) + (((int)((colorstart >> 16) & 255)) - ((int)((colorend >> 16) & 255))) * dv));
	g = (((int)((colorend >> 8) & 255) + \
	(((int)((colorstart >> 8) & 255)) - ((int)((colorend >> 8) & 255))) * dv));
	b = (((int)(colorend & 255) + \
	(((int)(colorstart & 255)) - ((int)(colorend & 255))) * dv));
	colorresult = r << 16 | g << 8 | b;
	return (colorresult);
}

static int		ft_pixel_gr(int colorstart, int colorend, int i, int imax, t_fract *fract)
{
	int		r;
	int		g;
	int		b;
	double	dv;
	double	sn;
	int		colorresult;

	sn = i - log(log(fract->val->z.r * fract->val->z.r + fract->val->z.i * fract->val->z.i))/log(2.0);
	if (sn == 0)
		return (colorend);
	else if (sn == imax)
		return (0x000000);
	else
		dv = sn / imax;
	r = (((int)((colorend >> 16) & 255) + \
	(((int)((colorstart >> 16) & 255)) - ((int)((colorend >> 16) & 255))) * dv));
	g = (((int)((colorend >> 8) & 255) + \
	(((int)((colorstart >> 8) & 255)) - ((int)((colorend >> 8) & 255))) * dv));
	b = (((int)(colorend & 255) + \
	(((int)(colorstart & 255)) - ((int)(colorend & 255))) * dv));
	colorresult = r << 16 | g << 8 | b;
	return (colorresult);
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

	if (fract->mna->color < 4)
	{
		if (fract->val->i == fract->mna->imax)
			return (0x000000);
		return (ft_pixel_color(ft_colornum(fract->mna->color + 1), \
		ft_colornum(fract->mna->color), fract->val->i, fract->mna->imax));
	}
	if (fract->mna->color == 4)
	{
		if (fract->val->i == fract->mna->imax)
			return (0x000000);
		return (ft_pixel_gr(WHITE, 0x091c36, fract->val->i, fract->mna->imax, fract));
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

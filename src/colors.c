/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 02:04:06 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/17 15:48:22 by dpalombo         ###   ########.fr       */
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

static int		ft_pixel_color(int colorstart, t_fract *fract, t_val val)
{
	int		r;
	int		g;
	int		b;
	int		colorresult;

	if (val.i == 0)
		return (0x000000);
	else if (val.i == fract->mna->imax)
		return (0x000000);
	else
		val.i = val.i / fract->mna->imax;
	r = I((colorstart >> 16) & 255) * val.i * 2;
	g = I((colorstart >> 8) & 255) * val.i * 2;
	b = I(colorstart & 255) * val.i * 2;
	colorresult = r << 16 | g << 8 | b;
	return (colorresult);
}

static int		ft_pixel_gr(int colorstart, int colorend, t_fract *fract, t_val val)
{
	int		r;
	int		g;
	int		b;
	double	dv;

	dv = val.i - log(log(val.z.r * val.z.r + val.z.i * val.z.i))/log(2.0);
	if (val.i == 0)
		return (WHITE);
	else if (dv == fract->mna->imax)
		return (0x000000);
	else
		dv = dv / fract->mna->imax;
	r = ((I((colorend >> 16) & 255) + \
	((I(colorstart >> 16) & 255) - (I(colorend >> 16) & 255)) * dv));
	g = ((I(((colorend >> 8) & 255)) + \
	((I(colorstart >> 8) & 255) - (I(colorend >> 8) & 255)) * dv));
	b = (I((colorend & 255) + \
	(I(colorstart & 255) - I(colorend & 255)) * dv));
	return ((r << 16 | g << 8 | b));
}

static int ft_multicolor(t_fract *fract, t_val val)
{
	int	r;
	int	g;
	int	b;

	if (val.i == fract->mna->imax)
		return (0x000000);
	r = I(val.i) % 9 * 100;
	g = I(val.i) % 3 * 100;
	b = I(val.i) % 7 * 100;
	return (r << 16 | g << 8 | b);
}

int ft_colorpx(t_fract *fract, t_val val)
{
	if (fract->mna->color == 0)
	{
		if (val.i == fract->mna->imax)
			return (0x000000);
		return (ft_pixel_gr(WHITE, 0x091c36, fract, val));
	}
	if (fract->mna->color == 1)
		return (ft_multicolor(fract, val));
	if (fract->mna->color < 6)
	{
		if (val.i == fract->mna->imax)
			return (0x000000);
		return (ft_pixel_color(ft_colornum(fract->mna->color - 2), fract, val));
	}
	else
		return (ft_multicolor(fract, val));
}

void	ft_pixel(unsigned int *data, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	data[y * WIN_WIDTH + x] = color;
	return ;
}

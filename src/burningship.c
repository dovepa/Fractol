/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 01:59:11 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/09 11:51:27 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_burningship(t_fract *fract)
{
	if (ft_inimg(fract) == 1)
		return (1);

	/////////////////////////// pas touche;
	int r = 0;
	int g = 0;
	int b = 255;
	int color = r << 16 | g << 8 | b;
	fract->val->xl = -2.1 + fract->mna->x;
	fract->val->xr = 0.6 - fract->mna->x;
	fract->val->yt = -1.2 - fract->mna->y;
	fract->val->yb = 1.2  + fract->mna->y;

	fract->val->x = 0;
	fract->val->y = 0;
	while(fract->val->x < WIN_WIDTH)
	{
		while(fract->val->y < WIN_HEIGHT)
		{
			fract->val->c.r = fract->val->x / fract->mna->zoom  + fract->val->xl;
			fract->val->c.i = fract->val->y / fract->mna->zoom  + fract->val->yt;
			fract->val->z.r = 0;
			fract->val->z.i = 0;
			fract->val->i =	0;

			while (fract->val->z.r*fract->val->z.r + fract->val->z.i*fract->val->z.i < 4 && \
			fract->val->i < fract->mna->imax )
			{
				double tmp = fract->val->z.r;
				fract->val->z.r = fract->val->z.r*fract->val->z.r - fract->val->z.i*fract->val->z.i + fract->val->c.r;
				fract->val->z.i = 2* fabs(fract->val->z.i*tmp) + fract->val->c.i;
				fract->val->i++;
			}
			if(fract->val->i == fract->mna->imax)
				ft_pixel(fract->img->data, fract->val->x, fract->val->y, 0x000000);
			else
			{
				b = fract->val->i * 255 / fract->mna->imax;
				color = r << 16 | g << 8 | b;
				ft_pixel(fract->img->data, fract->val->x, fract->val->y, color);
			}
			fract->val->y++;
		}
		fract->val->x++;
		fract->val->y = 0;
	}

	/////////////////////////// pas touche;
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img->img_ptr, 0, 0);
	ft_imgdel(fract);
	return (0);
}
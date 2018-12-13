/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 01:59:11 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/13 00:44:34 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"


int	ft_burningship(t_fract *fract)
{
	if (ft_inimg(fract) == 1)
		return (1);

	/////////////////////////// pas touche;
	// fract->val->xmin = -2.1;
	// fract->val->ymin = -1.9;
	// fract->val->xmax = 0.6;
	// fract->val->ymax = 1.2;

	fract->val->x = 0;
	fract->val->y = 0;
	while(fract->val->x < WIN_WIDTH)
	{
		while(fract->val->y < WIN_HEIGHT)
		{
			fract->val->c.r = fract->val->x / fract->mna->zoom  + fract->val->xmin + fract->mna->x;
			fract->val->c.i = fract->val->y / fract->mna->zoom  + fract->val->ymin - fract->mna->y;
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
			ft_pixel(fract->img->data, fract->val->x, fract->val->y, ft_colorpx(fract));
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

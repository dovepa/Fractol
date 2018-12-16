/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 01:59:11 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/16 02:39:26 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_burningship(t_fract *fract)
{
	if (ft_inimg(fract) == 1)
		return (1);
	fract->val->x = 0;
	fract->val->y = 0;
	while(fract->val->x < WIN_WIDTH)
	{
		while(fract->val->y < WIN_HEIGHT)
		{
			fract->val->c.r = fract->val->x / fract->mna->zoom  + fract->val->xmin;
			fract->val->c.i = fract->val->y / fract->mna->zoom  + fract->val->ymin;
			fract->val->z.r = 0;
			fract->val->z.i = 0;
			fract->val->i =	0;

			while (fract->val->z.r*fract->val->z.r + fract->val->z.i*fract->val->z.i < 4 && \
			fract->val->i < fract->mna->imax )
			{
				fract->val->tmp = fract->val->z.r;
				fract->val->z.r = fract->val->z.r*fract->val->z.r - fract->val->z.i*fract->val->z.i + fract->val->c.r;
				fract->val->z.i = 2* fabsl(fract->val->z.i* fract->val->tmp) + fract->val->c.i;
				fract->val->i++;
			}
			ft_pixel(fract->img->data, fract->val->x, fract->val->y, ft_colorpx(fract));
			fract->val->y++;
		}
		fract->val->x++;
		fract->val->y = 0;
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img->img_ptr, 0, 0);
	ft_imgdel(fract);
	return (0);
}

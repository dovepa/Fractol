/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:54:58 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/16 02:39:19 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static void ft_juliac(t_fract *fract)
{
	while(fract->val->x < WIN_WIDTH)
	{
		while(fract->val->y < WIN_HEIGHT)
		{
			fract->val->c.r = fract->mna->xm ;
			fract->val->c.i = fract->mna->ym ;
			fract->val->z.r = fract->val->x / fract->mna->zoom  + fract->val->xmin;
			fract->val->z.i = fract->val->y / fract->mna->zoom  + fract->val->ymin;
			fract->val->i =	0;

			while (fract->val->z.r*fract->val->z.r + fract->val->z.i*fract->val->z.i < 4 && \
			fract->val->i < fract->mna->imax )
			{
				fract->val->tmp = fract->val->z.r;
				fract->val->z.r = fract->val->z.r*fract->val->z.r - fract->val->z.i*fract->val->z.i + fract->val->c.r;
				fract->val->z.i = 2*fract->val->z.i* fract->val->tmp + fract->val->c.i;
				fract->val->i++;
			}
			ft_pixel(fract->img->data, fract->val->x, fract->val->y, ft_colorpx(fract));
			fract->val->y++;
		}
		fract->val->x++;
		fract->val->y = 0;
	}
	return ;
}

int	ft_julia(t_fract *fract)
{
	if (ft_inimg(fract) == 1)
		return (1);
	fract->val->x = 0;
	fract->val->y = 0;
	ft_juliac(fract);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img->img_ptr, 0, 0);
	ft_imgdel(fract);
	return (0);
}

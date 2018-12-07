/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:54:58 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/06 20:47:03 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

int	ft_julia(t_fract *fract)
{
	if (ft_inimg(fract) == 1)
		return (1);
	/////////////////////////// pas touche;
	int r = 0;
	int g = 0;
	int b = 255;
	int color = r << 16 | g << 8 | b;
	fract->val->xl = -2.1;
	fract->val->xr = 0.6;
	fract->val->yt = -1.2;
	fract->val->yb = 1.2;

	fract->val->x = 0;
	fract->val->y = 0;
	while(fract->val->x < WIN_WIDTH)
	{
		while(fract->val->y < WIN_HEIGHT)
		{
			fract->val->c.r = fract->mna->x;
			fract->val->c.i = fract->mna->y;
			fract->val->z.r =	fract->val->x / fract->mna->zoom  + fract->val->xl;
			fract->val->z.i =	fract->val->y / fract->mna->zoom  + fract->val->yt;
			fract->val->i =	0;

			while (fract->val->z.r*fract->val->z.r + fract->val->z.i*fract->val->z.i < 4 && \
			fract->val->i < fract->mna->imax )
			{
				double tmp = fract->val->z.r;
				fract->val->z.r = fract->val->z.r*fract->val->z.r - fract->val->z.i*fract->val->z.i + fract->val->c.r;
				fract->val->z.i = 2*fract->val->z.i*tmp + fract->val->c.i;
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


int ft_init(char *title, t_fract *fract)
{
	if ((fract->mlx_ptr = mlx_init()) == NULL ||	
	(fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title)) == NULL)
		return (1);
	return (0);
}

int	ft_imgdel(t_fract *fract)
{
	if (fract->img != NULL)
	{
		if (fract->img->img_ptr != NULL)
			mlx_destroy_image(fract->mlx_ptr, fract->img->img_ptr);
		ft_memdel((void **)&fract->img);
	}
	return (1);
}

int	ft_inimg(t_fract *fract)
{
	if ((fract->img = ft_memalloc(sizeof(t_mlximg))) == NULL)
		return (1);
	if ((fract->img->img_ptr = mlx_new_image(fract->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return (ft_imgdel(fract));
	fract->img->data = (unsigned int *)mlx_get_data_addr(fract->img->img_ptr, &fract->img->bpp,\
	 &fract->img->size_l, &fract->img->endian);
	return (0);
}

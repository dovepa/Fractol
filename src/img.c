/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 11:52:55 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/18 11:41:04 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

void	ft_pixel(unsigned int *data, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	data[y * WIN_WIDTH + x] = color;
	return ;
}

int		ft_imgdel(t_fract *fract)
{
	if (fract->img != NULL)
	{
		if (fract->img->img_ptr != NULL)
			mlx_destroy_image(fract->mlx_ptr, fract->img->img_ptr);
		ft_memdel((void **)&fract->img);
	}
	return (1);
}

t_fract	*ft_infract(t_fract *fract)
{
	if ((fract = ft_memalloc(sizeof(t_fract))) == NULL)
		return (NULL);
	return (fract);
}

int		ft_inimg(t_fract *fract)
{
	if ((fract->img = ft_memalloc(sizeof(t_mlximg))) == NULL)
		return (1);
	if ((fract->img->img_ptr = \
	mlx_new_image(fract->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return (ft_imgdel(fract));
	fract->img->data = (unsigned int *)mlx_get_data_addr(fract->img->img_ptr, \
	&fract->img->bpp, &fract->img->size_l, &fract->img->endian);
	return (0);
}

int		ft_init(char *title, t_fract *fract)
{
	if ((fract->mlx_ptr = mlx_init()) == NULL || \
	(fract->win_ptr = mlx_new_window(fract->mlx_ptr, \
	WIN_WIDTH, WIN_HEIGHT, title)) == NULL || \
	(fract->mna = (t_manda *)ft_memalloc(sizeof(t_manda))) == NULL)
		return (1);
	fract->mna->fct = 0;
	return (0);
}

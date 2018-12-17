/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:14:07 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/17 19:13:04 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

static void *ft_fct(void *fract)
{
	t_thread	*tmp;

	tmp = (t_thread *)fract;
	if (tmp->fract->fct == MNBR)
		ft_mandelbrot(tmp);
	if (tmp->fract->fct == JNBR)
		ft_julia(tmp);
	if (tmp->fract->fct == BNBR)
		ft_burningship(tmp);
	if (tmp->fract->fct == TNBR)
		ft_tricorn(tmp);
	return NULL;
}

int	ft_thread(t_fract *fract)
{
	int			i;

	if (ft_inimg(fract) == 1)
		return (1);
	i = 0;
	while (i < THREADNBR)
	{
		fract->thbase[i].id = i;
		fract->thbase[i].fract = fract;
		pthread_create(fract->thread + i, NULL, ft_fct, &(fract->thbase[i]));
		i++;
	}
	i = 0;
	while (i < THREADNBR)
	{
		pthread_join(fract->thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img->img_ptr, 0, 0);
	ft_imgdel(fract);
	return (1);
}

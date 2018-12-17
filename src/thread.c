/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:14:07 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/17 15:43:49 by dpalombo         ###   ########.fr       */
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
	t_render	*r;

	if (ft_inimg(fract) == 1)
		return (1);
	i = 0;
	r = &fract->render;
	while (i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].fract = fract;
		pthread_create(r->threads + i, NULL, ft_fct, &(r->args[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(r->threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, fract->img->img_ptr, 0, 0);
	ft_imgdel(fract);
	return (1);
}

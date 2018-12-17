/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:48:56 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/17 16:32:46 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

void	ft_tricorn(t_thread *tmp)
{
	t_val val;

	val.y = WIN_HEIGHT / THREADNBR * tmp->id;
	while(val.y < WIN_HEIGHT / THREADNBR * (tmp->id + 1))
	{
		val.x = 0;
		while(val.x < WIN_WIDTH)
		{
			val.c.r = val.x / tmp->fract->mna->zoom  + tmp->fract->mna->xmin;
			val.c.i = val.y / tmp->fract->mna->zoom  + tmp->fract->mna->ymin;
			val.z.r = 0;
			val.z.i = 0;
			val.i =	0;

			while (val.z.r*val.z.r + val.z.i*val.z.i < 4 && \
			val.i < tmp->fract->mna->imax )
			{
				val.tmp = val.z.r;
				val.z.r = val.z.r*val.z.r - val.z.i*val.z.i + val.c.r;
				val.z.i =  -2 * val.z.i* val.tmp + val.c.i;
				val.i++;
			}
			ft_pixel(tmp->fract->img->data, val.x, val.y, ft_colorpx(tmp->fract, val));
			val.x++;
		}
		val.y++;
	}
	return ;
}

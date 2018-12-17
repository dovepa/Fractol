/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:54:58 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/17 19:13:27 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfractol.h"

void	ft_julia(t_thread *tmp)
{
	t_val val;

	val.y = WIN_HEIGHT / THREADNBR * tmp->id;
	while (val.y < WIN_HEIGHT / THREADNBR * (tmp->id + 1))
	{
		val.x = 0;
		while(val.x < WIN_WIDTH)
		{
			val.c.r = tmp->fract->mna->xm;
			val.c.i = tmp->fract->mna->ym;
			val.z.r = (val.x / tmp->fract->mna->zoom) + tmp->fract->mna->xmin;
			val.z.i = (val.y / tmp->fract->mna->zoom) + tmp->fract->mna->ymin;
			val.i =	0;
			while (val.z.r * val.z.r + val.z.i * val.z.i < 4 && \
			val.i < tmp->fract->mna->imax )
			{
				val.tmp = val.z.r;
				val.z.r = val.z.r * val.z.r - val.z.i * val.z.i + val.c.r;
				val.z.i =  2 * val.z.i * val.tmp + val.c.i;
				val.i++;
			}
			ft_pixel(tmp->fract->img->data, val.x, val.y, ft_colorpx(tmp->fract, val));
			val.x++;
		}
		val.y++;
	}
	return ;
}

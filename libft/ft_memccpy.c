/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:39:44 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/19 15:05:30 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*cast_dest;
	unsigned char	*cast_src;

	i = 0;
	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	while (i < len)
	{
		cast_dest[i] = cast_src[i];
		if (cast_dest[i] == ((unsigned char)c))
			return ((dest + i + 1));
		i++;
	}
	return (NULL);
}

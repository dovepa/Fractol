/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:42:00 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/19 13:42:10 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	cast_c;
	unsigned char	*cast_s;

	i = 0;
	cast_c = (unsigned char)c;
	cast_s = (unsigned char*)s;
	while (i < len)
	{
		if (cast_s[i] == cast_c)
		{
			return ((void*)cast_s + i);
		}
		i++;
	}
	return (NULL);
}

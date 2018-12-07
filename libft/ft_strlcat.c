/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:27:21 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/15 14:48:08 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t idst;
	size_t isrc;

	idst = ft_strlen(dst);
	isrc = ft_strlen(src);
	if (size <= idst)
		return (size + isrc);
	if (isrc < size - idst)
	{
		ft_memcpy(dst + idst, src, isrc);
		dst += idst + isrc;
	}
	else
	{
		ft_memcpy(dst + idst, src, size - idst - 1);
		dst += size - 1;
	}
	*dst = '\0';
	return (isrc + idst);
}

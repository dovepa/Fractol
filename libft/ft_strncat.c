/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:30:36 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/14 10:19:17 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t nc;

	i = ft_strlen(dest);
	nc = 0;
	if (n == 0)
		return (dest);
	while (nc < n && ((char*)src)[nc] != '\0')
	{
		dest[i] = ((char*)src)[nc];
		i++;
		nc++;
	}
	dest[i] = '\0';
	return (dest);
}

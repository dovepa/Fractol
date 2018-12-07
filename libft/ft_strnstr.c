/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:18:06 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/20 18:30:41 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *tas, const char *var, size_t len)
{
	char	*cast_tas;
	char	*max;
	size_t	length;
	size_t	l2;

	max = (char *)(tas + len);
	length = ft_strlen(var);
	l2 = ft_strlen(tas);
	cast_tas = (char *)tas;
	if (!tas || !var || (length == 0))
		return ((char *)tas);
	if (l2 == 0)
		return (NULL);
	while ((cast_tas = ft_strchr(cast_tas, *var)) && cast_tas <= max)
	{
		if ((cast_tas + length <= max) && !ft_strncmp(cast_tas, var, length))
			return (cast_tas);
		cast_tas++;
	}
	return (NULL);
}

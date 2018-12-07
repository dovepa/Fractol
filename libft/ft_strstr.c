/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:18:03 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/17 10:38:25 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *tas, const char *var)
{
	int i;
	int pos;
	int len;

	i = 0;
	pos = 0;
	len = ft_strlen(var);
	if (len == 0)
		return ((char *)tas);
	while (tas[i] != '\0')
	{
		while (var[pos] == tas[i + pos])
		{
			if (pos == len - 1)
				return ((char *)tas + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohexp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:00:22 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/06 13:07:56 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

unsigned int	ft_atohexp(const char *str)
{
	int				i;
	double			c;
	unsigned int	result;

	result = 0;
	c = 0;
	i = ft_strlen(str) - 1;
	while ((i >= 2) && ((str[i] >= '0' && str[i] <= '9') || \
	(str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F')))
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			result = result + ((str[i] - 'a' + 10) * pow(16, c));
		if (str[i] >= 'A' && str[i] <= 'F')
			result = result + ((str[i] - 'A' + 10) * pow(16, c));
		if (str[i] >= '0' && str[i] <= '9')
			result = result + ((str[i] - '0') * pow(16, c));
		c++;
		i--;
	}
	return (result);
}

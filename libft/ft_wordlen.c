/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:45:47 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/06 13:09:50 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordlen(char *str, char sep)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != sep && str[i - 1] == sep) || \
		(str[i] != sep && i == 0))
			x++;
		i++;
	}
	return (x);
}

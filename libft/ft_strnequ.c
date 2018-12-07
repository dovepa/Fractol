/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:03:09 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/21 17:42:33 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		if (n == 0)
			return (1);
		while (s1[i] && s2[i] && s1[i] == s2[i] && i < (n - 1))
			i++;
		if (s1[i] == s2[i])
			return (1);
		return (0);
	}
	return (0);
}

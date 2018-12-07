/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:57:56 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/21 17:47:25 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrln(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*s;
	size_t	l;

	l = ft_nbrln(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = ft_strnew(ft_nbrln(n) + 1);
	if (s == NULL)
		return (NULL);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while (n)
	{
		s[l] = (n % 10) + '0';
		n /= 10;
		l--;
	}
	return (s);
}

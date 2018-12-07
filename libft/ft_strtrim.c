/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:19:58 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/24 12:06:39 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_countmin(char const *s)
{
	size_t i;

	i = 0;
	while ((s[i] == '\n') || (s[i] == '\t') || (s[i] == ' '))
		i++;
	return (i);
}

static	size_t	ft_countmax(char const *s)
{
	size_t j;

	j = ft_strlen(s) - 1;
	while ((s[j] == '\n') || (s[j] == '\t') || (s[j] == ' '))
		j--;
	return (j);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*tmp;

	if (s == NULL)
		return (NULL);
	k = ft_strlen(s);
	i = ft_countmin(s);
	j = ft_countmax(s);
	if (&s[i] == &s[k])
		return (ft_strnew(1));
	if ((tmp = (char *)malloc(sizeof(char) * (j - i + 2))) == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		tmp[k] = s[i];
		i++;
		k++;
	}
	tmp[k] = '\0';
	return (tmp);
}

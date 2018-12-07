/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:40:31 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/20 17:46:47 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	i;

	i = ft_strlen(s);
	if (!(cpy = ft_strnew(i)))
		return (NULL);
	cpy = ft_strcpy(cpy, s);
	return (cpy);
}

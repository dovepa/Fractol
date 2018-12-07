/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:27:55 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/14 17:55:13 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int remp, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char*)str)[i] = (unsigned char)remp;
		i++;
	}
	return (str);
}

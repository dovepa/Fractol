/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:44:24 by dpalombo          #+#    #+#             */
/*   Updated: 2018/11/30 14:36:40 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strerror(char const *str)
{
	char const *stre;

	stre = "error : ";
	ft_putstr(stre);
	ft_putendl(str);
	return (1);
}

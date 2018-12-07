/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:55:37 by dpalombo          #+#    #+#             */
/*   Updated: 2018/10/03 16:03:31 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrev(t_list **list)
{
	t_list	*tmp;
	t_list	*next;
	t_list	*listc;

	tmp = NULL;
	listc = *list;
	while (listc != NULL)
	{
		next = listc->next;
		listc->next = tmp;
		tmp = listc;
		listc = next;
	}
	*list = tmp;
}

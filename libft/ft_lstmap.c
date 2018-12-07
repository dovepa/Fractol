/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:55:24 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/21 19:51:24 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*buf;

	if (lst == NULL)
		return (NULL);
	if ((new = ft_lstnew(lst->content, lst->content_size)) == NULL)
		return (NULL);
	new = f(lst);
	buf = new;
	while (lst->next)
	{
		buf->next = f(lst->next);
		buf = buf->next;
		lst = lst->next;
	}
	return (new);
}

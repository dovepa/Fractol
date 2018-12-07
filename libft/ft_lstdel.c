/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:49:55 by dpalombo          #+#    #+#             */
/*   Updated: 2017/11/24 11:36:21 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf;

	if (alst && del)
	{
		buf = *alst;
		while (buf)
		{
			del(buf->content, buf->content_size);
			free(buf);
			buf = buf->next;
		}
		*alst = NULL;
	}
	return ;
}

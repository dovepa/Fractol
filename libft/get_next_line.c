/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:08:55 by dpalombo          #+#    #+#             */
/*   Updated: 2018/05/07 12:32:46 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_joinandfreelst(t_list *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(((char *)s1->content));
	s2_len = ft_strlen(s2);
	new_str = ft_strnew(s1_len + s2_len);
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
		*(new_str + i) = *(((char *)s1->content) + i);
	while (++j < s2_len)
		*(new_str + i++) = *(s2 + j);
	new_str[s1_len + s2_len] = '\0';
	free(s1->content);
	s1->content = (void *)new_str;
	return (s1);
}

static	t_list	*ft_parseurlist_fd(t_list **list_stock, size_t fd)
{
	t_list *listc;

	listc = *list_stock;
	while (listc)
	{
		if (listc->content_size == fd)
			return (listc);
		listc = listc->next;
	}
	listc = ft_lstnew("\0", (size_t)fd);
	ft_lstadd(list_stock, listc);
	listc = *list_stock;
	return (listc);
}

static	char	*ft_refree(char *src, int x)
{
	char	*dest;
	int		i;

	x += 1;
	i = 0;
	if (src == NULL)
		return (NULL);
	if ((dest = ft_strnew(ft_strlen(&src[x]))) == NULL)
		return (NULL);
	ft_strcpy(dest, &src[x]);
	free(src);
	return (dest);
}

static	int		ft_mouve(char **line, char *listc)
{
	int x;

	x = 0;
	while (listc[x] && listc[x] != '\n')
		x += 1;
	if ((*line = ft_strnew((size_t)(x))) == NULL)
		return (-1);
	*line = ft_strncpy(*line, (const char *)listc, (size_t)(x));
	return (x);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list_stock;
	t_list			*listc;
	int				rwr;
	char			buff[BUFF_SIZE + 1];
	int				x;

	if (fd < 0 || read(fd, buff, 0) < 0 || line == NULL)
		return (-1);
	listc = ft_parseurlist_fd(&list_stock, (size_t)fd);
	while ((rwr = read(fd, buff, BUFF_SIZE)) && \
	ft_strchr((char *)listc->content, '\n') != (char *)'\n')
	{
		buff[rwr] = '\0';
		if ((listc = ft_joinandfreelst(listc, buff)) == NULL)
			return (-1);
	}
	if (!ft_strlen(listc->content))
		return (0);
	if ((x = ft_mouve(line, (char *)listc->content)) == -1)
		return (-1);
	if (x < (int)ft_strlen(listc->content))
		listc->content = ft_refree(listc->content, x);
	else
		ft_strclr(listc->content);
	return (1);
}

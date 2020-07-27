/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:33:30 by mriley            #+#    #+#             */
/*   Updated: 2020/07/27 23:42:59 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_newcash(t_list *cash, void *str, int t)
{
	cash->content = ft_memalloc(t + 1);
	if (cash->content == NULL)
		return (NULL);
	cash->content = ft_memcpy(cash->content, str, t);
	((char *)cash->content)[t] = 0;
	cash->content_size = t;
	return (cash);
}

static t_list	*gnl_read(int fd)
{
	t_list	*cash1;
	char	buf[BUFF_SIZE + 1];
	int		h[3];
	char	*str;
	char	*tmp;

	ft_bzero(h, sizeof(h));
	str = NULL;
	while ((h[1] = read(fd, buf, BUFF_SIZE)) > 0 && h[2] == 0)
	{
		h[0] = h[0] + h[1];
		buf[h[1]] = '\0';
		if (fd == 0 && ft_strchr(buf, '\n') != NULL)
			break ;
		tmp = (str == NULL) ? ft_strdup(buf) : ft_strjoin(str, buf);
		free(str);
		str = tmp;
	}
	if (h[0] == 0 || str == NULL)
		return (NULL);
	cash1 = ft_lstnew(str, h[0]);
	free(str);
	return (cash1);
}

static char		*ft_line(t_list *cash, char **line)
{
	int		j;
	int		k;
	char	*tmp;

	j = 0;
	k = 0;
	if (cash->content == NULL)
	{
		*line = ft_memalloc(1);
		return (NULL);
	}
	k = ft_strlen((char*)cash->content);
	tmp = (char*)cash->content;
	while (tmp[j] != '\n' && tmp[j] != '\0')
		j++;
	*line = ft_strsub((char*)cash->content, 0, j);
	if (j == 0)
		*line = ft_strnew(1);
	if (!*line)
		return (NULL);
	cash->content = ft_strsub(tmp, j + 1, k - j);
	free(tmp);
	if (j == k)
		return (NULL);
	return (cash->content);
}

static void		gnl_free(t_list *cash1, t_list *cash, char **line)
{
	cash->content = ft_line(cash, line);
	if (cash1)
		free(cash1->content);
	free(cash1);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*head;
	t_list			*cash;
	t_list			*cash1;
	char			t[BUFF_SIZE];
	int				i;

	if (head == NULL)
		head = ft_lstnew(NULL, 0);
	if (fd < 0 || !line || BUFF_SIZE < 1 || (i = read(fd, t, 0)) < 0)
		return (-1);
	cash1 = gnl_read(fd);
	cash = head;
	i = 0;
	while (i++ <= fd)
	{
		if (cash->next == NULL)
			cash->next = ft_lstnew(NULL, 0);
		cash = cash->next;
	}
	if (cash1 && cash)
		cash = ft_newcash(cash, cash1->content, cash1->content_size);
	gnl_free(cash1, cash, line);
	if ((*line)[0] == '\0' && !cash->content)
		return (0);
	return (1);
}

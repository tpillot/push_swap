/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:55:23 by tpillot           #+#    #+#             */
/*   Updated: 2019/01/04 16:55:31 by tpillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static	t_buf	*check_fd(int fd, t_buf **buf)
{
	t_buf *new;
	t_buf *first;

	if (!*buf)
	{
		if (!(*buf = ft_memalloc(sizeof(t_buf))))
			return (NULL);
		(*buf)->fd = fd;
		return (*buf);
	}
	first = *buf;
	while (first->fd != fd && first->next)
		first = first->next;
	if (first->fd == fd)
		return (first);
	if (!(new = ft_memalloc(sizeof(t_buf))))
		return (NULL);
	new->fd = fd;
	first->next = new;
	return (new);
}

static	int		read_the_fd(int fd, t_buf *buf)
{
	int		ret;

	ret = read(fd, buf->buf_read, BUFF_SIZE);
	if (ret > 0)
	{
		(buf->buf_read)[ret] = '\0';
		buf->ptr_buf = buf->buf_read;
	}
	return (ret);
}

static	int		add_line(char **line, t_buf *buf)
{
	char	*tmp;
	char	*tmp2;

	tmp = buf->ptr_buf;
	buf->ptr_buf = ft_strchr(tmp, '\n');
	if (buf->ptr_buf)
		*(buf->ptr_buf) = '\0';
	if (*line)
	{
		tmp2 = *line;
		if (!(*line = ft_strjoin(*line, tmp)))
			return (-1);
		ft_strdel(&tmp2);
	}
	else if (!(*line = ft_strdup(tmp)))
		return (-1);
	if (buf->ptr_buf)
	{
		buf->ptr_buf++;
		if (*(buf->ptr_buf) == '\0')
			buf->ptr_buf = NULL;
		return (1);
	}
	return (0);
}

int				get_next_line(const	int fd, char **line)
{
	static	t_buf	*buf = NULL;
	t_buf			*current_buf;
	int				ret_read;
	int				ret_line;

	if (!line || fd < 0 || !(current_buf = check_fd(fd, &buf)))
		return (-1);
	*line = NULL;
	ret_read = 1;
	while (ret_read != 0)
	{
		if (!current_buf->ptr_buf &&
			(ret_read = read_the_fd(fd, current_buf)) == -1)
			return (-1);
		if (current_buf->ptr_buf)
		{
			if ((ret_line = add_line(line, current_buf)) == -1)
				return (-1);
			else if (ret_line)
				return (1);
		}
	}
	if (*line)
		return (1);
	return (0);
}

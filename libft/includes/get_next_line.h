/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 18:01:09 by tpillot           #+#    #+#             */
/*   Updated: 2019/01/04 18:01:12 by tpillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 17

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_buf
{
	char			buf_read[BUFF_SIZE + 1];
	char			*ptr_buf;
	int				fd;
	struct s_buf	*next;
}					t_buf;

int					get_next_line(const int fd, char **line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:17:46 by kchaouki          #+#    #+#             */
/*   Updated: 2022/11/01 12:37:57 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_read_and_stash(int fd, char **save)
{
	char	*buff;
	char	*tmp;
	int		x;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		(*save) = NULL;
		return ;
	}
	x = 0;
	while ("1337")
	{
		x = read(fd, buff, BUFFER_SIZE);
		if (x <= 0)
			break ;
		buff[x] = '\0';
		tmp = (*save);
		(*save) = ft_strjoin(tmp, buff);
		free (tmp);
		if (ft_check_newline(buff))
			break ;
	}
	free (buff);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;
	char		*tmp;

	ft_read_and_stash(fd, &save[fd]);
	if (fd == -1 || BUFFER_SIZE <= 0 || !save[fd])
		return (NULL);
	tmp = save[fd];
	line = ft_line_with_newline(tmp);
	save[fd] = ft_save(tmp);
	free(tmp);
	return (line);
}

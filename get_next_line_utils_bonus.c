/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:18:18 by kchaouki          #+#    #+#             */
/*   Updated: 2023/02/22 18:48:13 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_len(char	*str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*output;
	int		i;

	i = 0;
	output = malloc(ft_len(s1) + ft_len(s2) + 1);
	if (!output)
		return (NULL);
	while (s1 && *s1)
		output[i++] = *s1++;
	while (s2 && *s2)
		output[i++] = *s2++;
	output[i] = '\0';
	return (output);
}

int	ft_check_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_line_with_newline(char *line)
{
	char	*output;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	output = malloc(i + 2);
	if (!output)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		output[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		output[i] = line[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_save(char	*line)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || (line[i] == '\n' && line[i + 1] == '\0'))
		return (NULL);
	output = malloc(ft_len(line) - i + 1);
	if (!output)
		return (NULL);
	i++;
	while (line[i])
		output[j++] = line[i++];
	output[j] = '\0';
	return (output);
}

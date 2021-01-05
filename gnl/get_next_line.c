/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:58:18 by pstrait           #+#    #+#             */
/*   Updated: 2020/12/24 19:05:01 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

int		check_pref_buff(char **prev_buff, char **line)
{
	char	*pos;
	char	*p_prev_buff;

	if (*prev_buff)
	{
		free(*line);
		if ((pos = ft_strchr(*prev_buff, '\n')))
		{
			*pos = '\0';
			*line = ft_strdup(*prev_buff);
			p_prev_buff = *prev_buff;
			pos++;
			if (ft_strlen(pos))
			{
				*prev_buff = ft_strdup(pos);
				free(p_prev_buff);
			}
			else
				*prev_buff = NULL;
			return (1);
		}
		*line = ft_strdup(*prev_buff);
		free(*prev_buff);
		*prev_buff = NULL;
	}
	return (0);
}

int		read_file(int fd, char *buff, char **line, char **prev_buff)
{
	char		*pos;
	int			ret;
	char		*tmp_buff;

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((pos = ft_strchr(buff, '\n')))
		{
			*pos = '\0';
			tmp_buff = *line;
			*line = ft_strjoin(*line, buff);
			if (++pos < &buff[ret])
				*prev_buff = ft_strdup(pos);
			free(tmp_buff);
			free(buff);
			return (1);
		}
		tmp_buff = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp_buff);
	}
	free(buff);
	return (ret < 0 ? -1 : 0);
}

int		get_next_line(int fd, char **line)
{
	static char *prev_buff = NULL;
	char		*buff;
	int			ret_code;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = malloc(1);
	**line = '\0';
	if (check_pref_buff(&prev_buff, line) == 1)
		return (1);
	buff = malloc(sizeof(char*) * (BUFFER_SIZE) + 1);
	if (!buff)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	ret_code = read_file(fd, buff, line, &prev_buff);
	return (ret_code);
}

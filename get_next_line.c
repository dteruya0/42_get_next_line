/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:06:32 by dteruya           #+#    #+#             */
/*   Updated: 2024/12/18 12:19:53 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_store(char *stored, char *tmp, int fd)
{
	int		bytes_read;
	char	*buf;

	bytes_read = 1;
	if (stored == NULL)
		stored = ft_strdup("");
	while ((ft_strchr(stored, '\n') == NULL) && (bytes_read != 0))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stored);
			return (NULL);
		}
		tmp[bytes_read] = '\0';
		buf = stored;
		stored = ft_strjoin(buf, tmp);
		free (buf);
	}
	return (stored);
}

static char	*extract_line(char *stored)
{
	char	*line;
	int		i;

	i = 0;
	if (stored[i] == '\0')
		return (NULL);
	while (stored[i] != '\n' && stored[i] != '\0')
		i++;
	line = ft_substr(stored, 0, i + 1);
	return (line);
}

static char	*update_stored(char *stored)
{
	char	*temp;
	int		i;

	i = 0;
	while (stored[i] != '\0' && stored[i] != '\n')
		i++;
	if (stored[i] == '\0')
	{
		free(stored);
		return (NULL);
	}
	temp = ft_substr(stored, i + 1, ft_strlen(stored) - i);
	free (stored);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	stored = read_and_store(stored, tmp, fd);
	free(tmp);
	if (stored == NULL)
		return (NULL);
	line = extract_line(stored);
	stored = update_stored(stored);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:20:06 by dteruya           #+#    #+#             */
/*   Updated: 2024/12/18 16:22:29 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strcat;
	int		index;
	int		length1;
	int		length2;

	index = 0;
	length1 = ft_strlen(s1);
	length2 = length1 + ft_strlen(s2) + 1;
	strcat = (char *)malloc(length2 * sizeof(char));
	if (strcat == NULL)
		return (NULL);
	length2 = 0;
	while (index < length1)
	{
		strcat[index] = s1[index];
		index++;
	}
	while (s2[length2] != '\0')
		strcat[index++] = s2[length2++];
	strcat[index] = '\0';
	return (strcat);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		length;
	int		index;

	index = 0;
	length = 0;
	dup = (char *)s;
	length = (ft_strlen(s) + 1);
	dup = (char *)malloc(length * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (s[index] != '\0')
	{
		dup[index] = s[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != '\0' || s[index] == (char)c)
	{
		if (s[index] == (char)c)
			return ((char *)&s[index + 1]);
		index++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sbstr;
	size_t	count;
	size_t	index;

	index = 0;
	count = ft_strlen(s);
	if (start >= count)
		return (ft_strdup(""));
	count = (count - (size_t)start);
	if (count < len)
		sbstr = (char *)malloc((count + 1) * sizeof(char));
	else
	{
		count = len;
		sbstr = (char *)malloc((count + 1) * sizeof(char));
	}
	if (sbstr == NULL)
		return (NULL);
	while (index < count)
	{
		sbstr[index] = s[index + start];
		index++;
	}
	sbstr[index] = '\0';
	return (sbstr);
}

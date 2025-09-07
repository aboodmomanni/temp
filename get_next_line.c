/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:00:00 by marvin            #+#    #+#             */
/*   Updated: 2025/09/06 12:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *concatonate(char *left, char *buf)
{
	char *tmp;

	if (!left)
		return (f_dup(buf));
	tmp = f_join(left, buf);
	return (tmp);
}

static char *readloop(int fd, char *left)
{
	char *buf;
	int bytes;

	buf = malloc(BUFFER_SIZE + 1);
	bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		left = concatonate(left, buf);
		if (!left)
		{
			free(buf);
			return (NULL);
		}
		if (f_strchr(left, '\n') != -1)
			break;
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (bytes < 0)
	{
		free(left);
		return (NULL);
	}
	return (left);
}

char *extract_line(char *s)
{
	int i;
	char *line;

	if (!s || !s[0])
		return (NULL);
	i = f_strchr(s, '\n');
	if (i == -1)
		i = f_strlen(s);
	else
		i++;
	line = f_ssubstr(s, 0, i);
	return (line);
}

char *update_leftover(char *s)
{
	int start;
	char *new;

	if (!s)
		return (NULL);
	start = f_strchr(s, '\n');
	if (start == -1)
	{
		free(s);
		return (NULL);
	}
	start++;
	if (s[start] == '\0')
	{
		free(s);
		return (NULL);
	}
	new = f_ssubstr(s, start, f_strlen(s) - start);
	free(s);
	if (new[0] == '\0' || !new)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

char *get_next_line(int fd)
{
	static char *leftover;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = readloop(fd, leftover);
	if (!leftover)
		return (NULL);
	line = extract_line(leftover);
	leftover = update_leftover(leftover);
	return (line);
}
// int main()
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);
// }
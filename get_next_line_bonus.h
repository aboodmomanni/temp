/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:00:00 by marvin            #+#    #+#             */
/*   Updated: 2025/09/06 12:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 1024

char	*get_next_line(int fd);
char	*extract_line(char *string);
char	*update_leftover(char *string);
size_t	f_strlen(char *s);
int		f_strchr(char *s, int c);
char	*f_dup(char *s);
char	*f_join(char *s1, char *s2);
char	*f_ssubstr(char *s, unsigned int start, size_t len);

#endif

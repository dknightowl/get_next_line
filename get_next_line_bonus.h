/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:52:15 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/07 10:19:49 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// FOR TESTING
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

# define MAX_FD 1024
// # define MAX_FD 4096

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define SUCCESS 1
# define FAIL 0

# define READ_SUCCESS 1
# define READ_EOF 0
# define READ_ERROR -1

char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_idxof_newline(const char *s);

#endif
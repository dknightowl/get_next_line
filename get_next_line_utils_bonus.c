/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:52:45 by dkhoo             #+#    #+#             */
/*   Updated: 2025/06/07 17:06:34 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
	@brief Copies up to size - 1 characters from the NUL-terminated
	string 'src' to 'dst', NUL-terminating the result. Both 'src'
	and 'dst' must be NUL-terminated. Take the full size of the
	buffer (not just the length) and guarantee to NUL-terminate the
	result (as long as size is larger than 0)

	@param dst Destination string to copy to
	@param src Source string to copy from
	@param size Buffer size of

	@return Length of src string
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;

	if (!dst || !src)
		return (0);
	idx = 0;
	while (src[idx] && (idx + 1) < size)
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (size > 0)
		dst[idx] = '\0';
	while (src[idx])
		idx++;
	return (idx);
}

/**
	@brief Allocates memory (using malloc(3)) and
	returns a new string that is the result of
	concatenating 's1' and 's2'

	@param s1 First string
	@param s2 Second string

	@return Newly-created string, or NULL if
	allocation fails
*/
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s;
	size_t	idx;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = malloc(s1_len + s2_len + 1);
	if (!s)
		return (NULL);
	idx = 0;
	while (idx < s1_len)
	{
		s[idx] = s1[idx];
		idx++;
	}
	while ((idx - s1_len) < s2_len)
	{
		s[idx] = s2[idx - s1_len];
		idx++;
	}
	s[idx] = '\0';
	return (s);
}

/**
	@brief Allocates memory (using malloc(3)) and returns a
	substring from the string ’s’. The substring starts
	at index ’start’ and has a maximum length of ’len’.

	@param s String to obtain substring from
	@param start Index to start the substring from
	@param len Length of substring to obtain

	@return The substring, or NULL if an error occurred
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	char	*empty;

	slen = ft_strlen(s);
	if (start >= slen)
	{
		empty = malloc(1);
		if (empty)
		{
			empty[0] = '\0';
			return (empty);
		}
		return (NULL);
	}
	if ((slen - start) < len)
		len = slen - start;
	substr = malloc(len + 1);
	if (substr)
	{
		ft_strlcpy(substr, s + start, len + 1);
		return (substr);
	}
	return (NULL);
}

/**
	@brief Calculates the length of the string
	pointed to by 's', excluding the terminating null
	byte ('\0')

	@param s String to calculate length of

	@return Number of characters in 's', excluding the
	null byte
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
	@brief Retrieves the index of the newline
	character from the string, if it exists

	@param s String to search

	@return Index of newline character, or -1
	if it is not found
*/
int	ft_idxof_newline(const char *s)
{
	size_t	idx;
	size_t	s_len;

	idx = 0;
	s_len = ft_strlen(s);
	while (idx < s_len)
	{
		if (s[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

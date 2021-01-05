/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:37:22 by pstrait           #+#    #+#             */
/*   Updated: 2020/12/24 19:05:07 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_size;
	size_t src_size;
	size_t total_string_size;
	size_t size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	total_string_size = dstsize;
	if (!dst || !src)
		return ((size_t)NULL);
	if (total_string_size <= dst_size)
		return (total_string_size + src_size);
	dst += dst_size;
	size = total_string_size - dst_size - 1;
	while (size-- && *src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return (dst_size + src_size);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src,
		size_t dstsize)
{
	size_t			i;
	unsigned char	*psrc;
	unsigned char	*pdst;

	i = 0;
	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (dstsize < 1)
		return (ft_strlen(src));
	if (!dst || !src)
		return ((size_t)NULL);
	while (dstsize - 1 && psrc[i])
	{
		pdst[i] = psrc[i];
		dstsize--;
		i++;
	}
	pdst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_st;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size_st = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(size_st);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, size_st);
	ft_strlcat(str, s2, size_st);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char *str;

	str = malloc(ft_strlen(s1) + 1);
	if (str == NULL)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}

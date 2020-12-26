/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:25:50 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/07 16:25:53 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  memchr -- locate byte in byte string
**   DESCRIPTION
**      The memchr() function locates the first occurrence of c (converted to an unsigned char) in string s.
**   RETURN VALUES
**      The memchr() function returns a pointer to the byte located, or NULL if no such byte exists within n bytes.
*/


#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
  char *p_str = (char *)s;

  while(n)
  {
    if (*p_str == c)
      return p_str;
    n--;
    p_str++;
  }
  return NULL;

}

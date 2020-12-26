/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:08:09 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/09 16:44:59 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
  size_t i=0;
  unsigned char *d = (unsigned char *) dst;
  const unsigned char *s = (unsigned char *) src;

  while (n) {
      d[i] = s[i];
      if ((unsigned char)c == s[i])
        return &d[i+1];
      i++;
      n--;
  }
  return NULL;
}

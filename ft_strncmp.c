/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:06:44 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/11 15:02:20 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strncmp -- compare strings
*/

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
  unsigned char *ptr1=(unsigned char *)s1;
  unsigned char *ptr2=(unsigned char *)s2;

  while(n && *ptr1 && *ptr2)
  {
    if (*ptr1 == *ptr2)
    {
      n--;
      ptr1++;
      ptr2++;
    }
    else
      return (*ptr1 - *ptr2);
  }
   return (*ptr1 - *ptr2);
}

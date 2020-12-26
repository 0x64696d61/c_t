/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:07:05 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/07 21:07:07 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locate a substring in a string
*/

#include "libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
  char *ptr1 = (char *) haystack;
  char *ptr2 = (char *) needle;

  size_t i = 0;
  size_t j = 0;

  while (ptr1[i] != '\0') {
      while(ptr1[i] == ptr2[j])
      {
/*
**         printf("xxx %c\n", ptr2[j]);
**         printf("j =  %lu\n", j);
**         printf("strlen =  %lu\n", strlen(ptr2));
**         if (j == (strlen(ptr2) - 1))
*/
          return &ptr1[i-j];
        j++;
        i++;
      }
      i++;
      j=0;
  }
  return NULL;
}

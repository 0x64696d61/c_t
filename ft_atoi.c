/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:59:42 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/08 15:25:37 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// atoi, atoi_l -- convert ASCII string to integer

#include "libft.h"

int ft_atoi(const char *str)
{
  char *ptr = (char *) str;
  int result = 0;

  while(*ptr >= '0' && *ptr <= '9')
  {
    if (result != 0)
      result = result * 10;
    result += *ptr - '0';
    ptr++;
  }
  return result;
}

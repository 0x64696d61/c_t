/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrait <pstrait@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:07:46 by pstrait           #+#    #+#             */
/*   Updated: 2020/11/07 21:07:47 by pstrait          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *dest, int c, size_t len)
{
  unsigned char *ptr = dest;

    while(len > 0)
    {
        *ptr = c;
        ptr++;
        len--;
    }


    return dest;
}

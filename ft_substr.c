#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
   char *new_string = malloc(len + 1);
   if (new_string == NULL)
    return NULL;

   ft_bzero(new_string,len + 1);
    if (ft_strlen(s) > start)
      ft_strlcpy(new_string, &s[start], len +1);
    return new_string;
}

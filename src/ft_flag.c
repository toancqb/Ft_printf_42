#include "../includes/ft_printf.h"

void sharp_xXo(char *str1, char **str2)
{
  char *str_join;
  char *tmp;

  tmp = *str2;
  if (ft_strcmp(*str2, "0"))
  {
    *str2 = ft_strjoin(str1, tmp);
    free(tmp);
  }
}

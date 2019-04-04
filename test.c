#include <stdio.h>
#include "ft_printf.h"

int main()
{
     t_printf pf;

     pf.fmt = "-+ #0";
     opt_check(&pf);
     printf("%d", pf.opt);
     return (0);
}
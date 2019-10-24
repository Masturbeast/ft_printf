#include "ft_printf.h"

int					ft_nbrlen(uintmax_t nb, intmax_t base)
{
	int				len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len += 1;
	}
	return (len);
}

void  p_print2(unsigned long ptr)
{
   char		      *base;
   char				res[9];
   int				i;

   base = "0123456789abcdef";
   i = 8;
   while ((ptr / 16) > 0 || i >= 8)
   {
      res[i] = base[(ptr % 16)];
      ptr /= 16;
      i--;
   }
   res[i] = base[(ptr % 16)];
   ft_putchar('0');
   ft_putchar('x');
   while (i < 9)
   {
      ft_putchar(res[i]);
      i++;
   }
}

void  p_print(t_printf *pf)
{
   unsigned long	ptr;
   int		      twidth;
   int            len;
 
   ptr = p_conv(pf);
   len = ft_nbrlen(ptr, 16) + 2;
   pf->count += len;
   twidth = pf->width - len;
	if (pf->opt_size & O_MINUS)
	{
		p_print2(ptr);
		padding(pf, twidth, ' ');
	}
	else
	{
		padding(pf, twidth, ' ');
		p_print2(ptr);
	}
}
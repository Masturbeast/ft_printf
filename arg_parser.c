#include "ft_printf.h"
#include <stdio.h>

void     opt_check(t_printf *pf)
{
	int res;

	while ((res = get_opt("#0-+ ", *pf->fmt)) && pf->fmt++)
		pf->opt |= res;
	((pf->opt & O_ZERO) && (pf->opt & O_MINUS)) ? pf->opt &= ~O_ZERO : 0;
	((pf->opt & O_PLUS) && (pf->opt & O_SPACE)) ? pf->opt &= ~O_SPACE : 0;
}
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include "libft/libft.h"

# define BUFF_SIZE 4096

								/* FALGS IN BINARYWISE */

								/* OPTIONS */

# define O_HASH	(1 << 0)	/* option "#" --> 0000 0000 0000 0001 */
# define O_ZERO	(1 << 1)	/* option "0" --> 0000 0000 0000 0010 */
# define O_MINUS (1 << 2)	/* option "-" --> 0000 0000 0000 0100 */
# define O_PLUS	(1 << 3)	/* option "+" --> 0000 0000 0000 1000 */ 
# define O_SPACE (1 << 4)	/* option " " --> 0000 0000 0001 0000 */

								/* SIZE */

# define S_CHAR	(1 << 5)	/* size "hh"  --> 0000 0000 0010 0000 */
# define S_SHORT (1 << 6)	/* size "h"   --> 0000 0000 0100 0000 */
# define S_LONG (1 << 7)	/* size "l"   --> 0000 0000 1000 0000 */
# define S_LLONG (1 << 8)	/* size "ll"  --> 0000 0001 0000 0000 */
# define S_LDOUBLE (1 << 9)	/* size "L"   --> 0000 0010 0000 0000 */

					/* /!\ /!\ /!\ NOTES /!\ /!\ /!\ */

/*

- For S_CHAR: - with d or i, it's an signed char.
              - with u, o, x or X, it's an unsigned char.
- For S_SHORT: - with d or i, it's a short int.
               - with u, o, x or X, it's an unsigned short int.
- For S_LONG: - with d or i, it's a long int.
              - with u, o, x or X, it's an unsigned long int.
- For S_LLONG: - with d or im it's a long long int.
               - with u, o, x or X, it's an unsigned long long int.

			   Check plan.txt.
*/

typedef struct  s_format
{
	char	opt;
	int		minwidth;
	int		prec;
	char	size;
	char	conv;
	char	buff[BUFF_SIZE];
}               t_format;
/*
    flags (declared as variables) included in format struct:
    options
    minimal width
    precision
    size modifier
    conversion types

    (bitwise operation inchallah)
*/

void  ft_printf(const char *fmt, ...);

#endif
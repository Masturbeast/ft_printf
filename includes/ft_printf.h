#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>

# define BUFF_SIZE 4096

							/* FALGS IN BINARYWISE */

							/* OPTIONS */

# define O_HASH	(1 << 0)    /* option "#" --> 0000 0000 0000 0001 = 1    */
# define O_ZERO	(1 << 1)    /* option "0" --> 0000 0000 0000 0010 = 2    */
# define O_MINUS (1 << 2)   /* option "-" --> 0000 0000 0000 0100 = 4    */
# define O_PLUS	(1 << 3)    /* option "+" --> 0000 0000 0000 1000 = 8    */ 
# define O_SPACE (1 << 4)   /* option " " --> 0000 0000 0001 0000 = 16   */

							/* SIZE MODIFIERS */

# define S_SHORT (1 << 5)	/* size "h"   --> 0000 0000 0010 0000 = 32   */
# define S_LONG (1 << 6)	/* size "l"   --> 0000 0000 0100 0000 = 64   */
# define S_LDOUBLE (1 << 7) /* size "L"   --> 0000 0000 1000 0000 = 128  */
# define S_INTMAX (1 << 8)  /* size "j"	  --> 0000 0001 0000 0000 = 256  */
# define S_SIZE_T (1 << 9)  /* size "z"	  --> 0000 0010 0000 0000 = 512  */
# define S_CHAR (1 << 10)   /* size "hh"  --> 0000 0100 0000 0000 = 1024 */
# define S_LLONG (1 << 11)  /* size "ll"  --> 0000 1000 0000 0000 = 2048 */

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

typedef struct  s_printf
{
	char	*fmt;
	int		opt_size;
	int 	width;
	int		prec;
	char	conv;
	va_list args;

}               t_printf;
/*
    flags (declared as variables) included in format struct:
    options
    minimal width
    precision
    size modifier
    conversion types

    (bitwise operation inchallah)
*/

/* Main function */

int		ft_printf(const char *fmt, ...);

/* Parser funtcions */

void	opt_check(t_printf *pf);
void	width_check(t_printf *pf);
void	prec_check(t_printf *pf);
void	size_check(t_printf *pf);
int		conv_check(t_printf *pf);
int		arg_parser(t_printf *pf);
int		get_opt_size(char *str, char c);
char	get_conv(char *str, char c);

/*  Utils functions */

int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
size_t	ft_int_length(intmax_t n);
void	ft_putstr(char const *s);

/* Format options functions */

void	minus_padding(int width);
void    di_options_print(t_printf *pf);

/* Cast functions */

intmax_t	di_int_cast(t_printf *pf);
uintmax_t   oux_int_cast(t_printf *pf);

#endif
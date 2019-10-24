#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

							/* FLAGS IN BINARYWISE */

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
	char	res[300];
	va_list args;
	int		ilenght;
	int		index;
	int		count;
	int		dot;
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
void	reset_struct(t_printf *pf);

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

size_t			ft_int_length(uintmax_t n);
size_t			ft_strlen(const char *str);
long long int	int_cat(long long int x, long long int y);
long long int	ft_power(long long int x, long long int power);
void			ft_str_reverse(char *str, int len);
int				ft_inttostr(long long int x, char *str, int prec);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
char			*ft_itoa(int n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_strclr(char *s);
void			ft_putnbr(uintmax_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_itoa_base(unsigned int value, int base);
char			*ft_itoa_base_cap(unsigned int value, int base);
int				ft_nbrlen(uintmax_t nb, intmax_t base);

/* Format options functions */

void	padding(t_printf *pf, int width, char c);
void    fpadding(int width, char c);
void    di_options_print(t_printf *pf);
void    u_options_print(t_printf *pf);
void	o_options_print(t_printf *pf);
void	x_options_print(t_printf *pf);
void	x_cap_options_print(t_printf *pf);
int		f_options_print(t_printf *pf);
void	s_print(t_printf *pf);
void	c_print(t_printf *pf);
void	p_print(t_printf *pf);
void    p_print2(unsigned long ptr);
void	percent_print(t_printf *pf);
void    neg_int_print(t_printf *pf, int twidth, intmax_t print);
void	pos_int_print(t_printf *pf, int twidth, uintmax_t print);
void    pos_float_print(t_printf *pf, int twidth, char *res);
void	ft_ftoa(t_printf *pf, long double n);
//char	*neg_fround(t_printf *pf, long long int x, long double y);
char	*pos_fround(t_printf *pf, long long int x, long double y);
char	*decimal_manager(long long int y, int prec);

/* Cast functions */

intmax_t		di_int_cast(t_printf *pf);
uintmax_t   	oux_int_cast(t_printf *pf);
long double 	f_float_cast(t_printf *pf);
char			*s_conv(t_printf *pf);
int				c_conv(t_printf *pf);
unsigned long	p_conv(t_printf *pf);

#endif
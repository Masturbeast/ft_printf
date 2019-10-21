# Executable
NAME 	= 	libftprintf.a

# Compilation
CC		= 	@cc -O3
CFLAGS	= 	-Wall -Wextra -Werror -Iincludes

SRCSDIR = srcs/

UTILSDIR = utils/

CONVDIR = conv/

INCDIR = includes/

LIBFTDIR = includes/libft/

# Files && Objs

UTILS	=		$(UTILSDIR)ft_int_lenght.c		\
				$(UTILSDIR)get_conv.c			\
				$(UTILSDIR)get_opt_size.c		\
				$(UTILSDIR)int_cat.c			\
				$(UTILSDIR)ft_power.c			\
				$(UTILSDIR)ft_str_reverse.c		\
				$(UTILSDIR)ft_inttostr.c		\
				$(UTILSDIR)ft_atoi.c			\
				$(UTILSDIR)ft_memset.c			\
				$(UTILSDIR)ft_putchar.c			\
				$(UTILSDIR)ft_putnbr.c			\
				$(UTILSDIR)ft_bzero.c			\
				$(UTILSDIR)ft_strlen.c			\
				$(UTILSDIR)ft_strclr.c			\
				$(UTILSDIR)ft_strcpy.c			\
				$(UTILSDIR)ft_itoa_base.c		\

UTIOBJ		= 	$(UTILS:.c=.o)

CONV		=	$(CONVDIR)int_size_mod.c		\
				$(CONVDIR)float_size_mod.c		\
				$(CONVDIR)s_conv.c				\
				$(CONVDIR)c_conv.c				\
				$(CONVDIR)p_conv.c				\

CONVOBJ		=	$(CONV:.c=.o)

SRCS 		=	$(SRCSDIR)ft_printf.c			\
				$(SRCSDIR)ft_ftoa.c				\
				$(SRCSDIR)arg_parser.c			\
				$(SRCSDIR)di_options_print.c	\
				$(SRCSDIR)f_options_print.c		\
				$(SRCSDIR)s_print.c				\
				$(SRCSDIR)c_print.c				\
				$(SRCSDIR)p_print.c				\
				$(SRCSDIR)u_options_print.c		\
				$(SRCSDIR)o_options_print.c		\

SRCSOBJ		=	$(SRCS:.c=.o)

# **************************************************************************** #

# SPECIAL CHARS

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# Protect

.PHONY:	all clean fclean re

# **************************************************************************** #

# RULES

# Main rules
all				: 	$(NAME)

re				: 	fclean all

# Compilation rules

#
#$(info $(OBJ) $(UTIOBJ) $(CONVOBJ))
$(NAME)			:	 $(SRCSOBJ) $(UTIOBJ) $(CONVOBJ)
					@echo "-------------------------------------------------------------"
					@echo "|                  Debut de la compilation                  |"
					@echo "|                            42                             |"
					@echo "|                         FT_PRINTF                         |"
					@echo "|                       compilation :                       |"
					@echo "|                                                           |"
					@ar rc $(NAME) $(SRCSOBJ) $(UTIOBJ) $(CONVOBJ)
					@ranlib $(NAME)
					@echo "|                   make $(NAME)$(LOG_GREEN) ✓ $(LOG_NOCOLOR)                   |"
					@echo "-------------------------------------------------------------"
# Clean rules

clean			:
					@echo "-------------------------------------------------------------"
					@rm -rf $(SRCSOBJ) $(UTIOBJ) $(CONVOBJ)
					@echo "|                    Removes all .o$(LOG_GREEN) ✓ $(LOG_NOCOLOR) !                    |"
					@echo "-------------------------------------------------------------"

fclean			: 	clean
					@rm -f $(NAME)
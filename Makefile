# Executable
NAME 	= 	libftprintf.a

# Compilation
CC		= 	@cc -O3
CFLAGS	= 	-Wall -Wextra -Werror -Iincludes

SRCSDIR = srcs/

UTILSDIR = utils/

CONVDIR = conv/

INCDIR = includes/

# Files && Objs

UTILS	=		$(UTILSDIR)ft_atoi.c			\
				$(UTILSDIR)ft_int_lenght.c		\
				$(UTILSDIR)ft_putchar.c			\
				$(UTILSDIR)ft_putnbr.c			\
				$(UTILSDIR)get_conv.c			\
				$(UTILSDIR)get_opt_size.c		\
				$(UTILSDIR)ft_putstr.c			\


UTIOBJ	= $(UTILS:.c=.o)

CONV	=		$(CONVDIR)sint_size_mod.c		\

CONVOBJ	= $(CONV:.c=.o)

SRCS 	=		$(SRCSDIR)ft_printf.c			\
				$(SRCSDIR)arg_parser.c			\
				$(SRCSDIR)int_options.c				\

OBJ	   = $(SRCS:.c=.o)

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
$(NAME)			:	 $(OBJ) $(UTIOBJ) $(CONVOBJ)
					@echo "-------------------------------------------------------------"
					@echo "|                  Debut de la compilation                  |"
					@echo "|                            42                             |"
					@echo "|                         FT_PRINTF                         |"
					@echo "|                       compilation :                       |"
					@echo "|                                                           |"
					@ar rc $(NAME) $(OBJ) $(UTIOBJ) $(CONVOBJ)
					@ranlib $(NAME)
					@echo "|                   make $(NAME)$(LOG_GREEN) ✓ $(LOG_NOCOLOR)                   |"
					@echo "-------------------------------------------------------------"
# Clean rules

clean			:
					@echo "-------------------------------------------------------------"
					@rm -rf $(OBJ) $(UTIOBJ) $(CONVOBJ)
					@echo "|                    Removes all .o$(LOG_GREEN) ✓ $(LOG_NOCOLOR) !                    |"
					@echo "-------------------------------------------------------------"

fclean			: 	clean
					@rm -f $(NAME)
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 14:57:28 by ataguiro          #+#    #+#              #
#    Updated: 2017/03/17 12:12:04 by ataguiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Editable =====
NAME	:=	checker
INDEX	:=	1
# ====================

# ===== Standard =====
CC		:=	clang -pipe
CFLAGS	:=	-Wall -Wextra -Werror -g3
SRCDIR	:=	src/
OBJDIR	:=	obj/
INCDIR	:=	include/
LIBDIR	:=	../libft/
SRC		:=	$(SRCDIR)checker.c \
			$(SRCDIR)display.c \
			$(SRCDIR)stack.c \
			$(SRCDIR)errors.c \
			$(SRCDIR)exec/exec_pa.c \
			$(SRCDIR)exec/exec_pb.c \
			$(SRCDIR)exec/exec_sa.c \
			$(SRCDIR)exec/exec_sb.c \
			$(SRCDIR)exec/exec_ss.c \
			$(SRCDIR)exec/exec_ra.c \
			$(SRCDIR)exec/exec_rb.c \
			$(SRCDIR)exec/exec_rr.c \
			$(SRCDIR)exec/exec_rra.c \
			$(SRCDIR)exec/exec_rrb.c \
			$(SRCDIR)exec/exec_rrr.c
OBJ		:=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
INC		:=	-I./$(INCDIR) -I./$(LIBDIR)$(INCDIR)
LIBPATH	:=	-L./$(LIBDIR) -lft
CACHEF	:=	.cache_exists
# ====================

# ====== Colors ======
CLEAR		= "\033[2K"
UP			= "\033[A"
EOC			= "\033[0;0m"
BLACK		= "\033[0;30m"
RED			= "\033[0;31m"
BRED		= "\033[1;31m"
GREEN		= "\033[0;32m"
BGREEN		= "\033[1;32m"
YELLOW		= "\033[0;33m"
BLUE		= "\033[0;34m"
PURPLE		= "\033[0;35m"
CYAN		= "\033[0;36m"
WHITE		= "\033[0;37m"
# ====================

.PHONY: all libft norme clean fclean re
.SILENT:

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -o $@ $(LIBPATH) $(LIB) $(INC)
	echo "\033[1;32m" "\n✓ $@ ok ;)" "\033[0m"
	mv checker ../
	chmod 444 $(SRC)

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF) include
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	printf "\r"
	printf $(BGREEN)"[ compiling $(NAME)... ] "
	printf "$(shell echo 'scale=2;$(INDEX)/15 * 100' | bc)%%"$(EOC)
	$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(OBJDIR)exec || mkdir $(OBJDIR)exec
	test -d $(CACHEF) || touch $(CACHEF)

%.c:
	printf $(RED)"Missing file : $@\n"$(EOC)

libft:
	make -C $(LIBDIR)

norme:
	norminette $(SRCDIR) $(INCDIR) | grep -v Norme -B1 || true
	norminette $(LIBFT)$(SRCDIR) $(LIBFT)$(INCDIR) | grep -v Norme -B1 || true

ret:
	chmod +w $(SRC)

clean:
	make -C $(LIBDIR) clean
	rm -rf $(OBJDIR) $(CACHEF)
	printf $(YELLOW)"All objects removed\n"$(EOC)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f ../$(NAME)
	printf $(RED)"$(NAME) removed\n"$(EOC)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/25 13:43:46 by ataguiro          #+#    #+#              #
#    Updated: 2017/03/17 14:23:16 by ataguiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

all:
	make -C checker_f
	make -C ps_f

clean:
	make -C checker_f clean
	make -C ps_f clean

fclean:
	make -C checker_f fclean
	make -C ps_f fclean

ret:
	make -C checker_f ret
	make -C ps_f ret

norme:
	make -C checker_f norme
	make -C ps_f norme

re: fclean all

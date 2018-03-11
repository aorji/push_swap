# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aorji <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/25 18:11:26 by aorji             #+#    #+#              #
#    Updated: 2018/01/25 18:11:28 by aorji            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
SRC		=	swap/main.c swap/ft_ss.c swap/ft_p.c swap/ft_len.c swap/ft_new_elem.c \
			swap/ft_rr.c swap/ft_rrr.c swap/ft_swap_3.c swap/ft_mediana.c \
			swap/ft_sort.c
FLG		=	-Wall -Wextra -Werror
PRNTF	=	ft_printf/libftprintf.a

all: $(NAME)

$(NAME): 
	@ make -C ft_printf
	@ gcc $(FLG) -o $(NAME) $(SRC) $(PRNTF)

clean:
	@ cd ft_printf && make clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ cd ft_printf && make fclean

re: fclean all

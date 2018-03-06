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
SRC		=	swap/main.c swap/ft_ss.c swap/ft_p.c swap/ft_len.c swap/ft_new_elem.c
FLG		=	-Wall -Wextra -Werror
LIB		=	libft/libft.a
PRNTF	=	ft_printf/libftprintf.a

all: $(NAME)

$(NAME): 
	@ make -C libft
	@ make -C ft_printf
	@ gcc $(FLG) -o $(NAME) $(SRC) $(LIB) $(PRNTF)

clean:
	@ cd libft && make clean
	@ cd ft_printf && make clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ cd libft && make fclean
	@ cd ft_printf && make fclean

re: fclean all

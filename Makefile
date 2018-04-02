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

P_NAME	=	push_swap
C_NAME	=	checker
FLG		=	-Wall -Wextra -Werror -g3
H 		=	swap/push_swap.h
	
SRC		=	swap/ft_ss.c swap/ft_p.c swap/ft_len.c swap/ft_new_elem.c \
			swap/ft_rr.c swap/ft_rrr.c swap/ft_swap_3.c swap/ft_mediana.c \
			swap/ft_sort.c

P_SRC	=	swap/main.c
C_SRC	=	checker.c

P_OBJ	=	$(P_SRC:.c=.o) $(SRC:.c=.o)
C_OBJ	=	$(C_SRC:.c=.o) $(SRC:.c=.o)

PRNTF	=	ft_printf/libftprintf.a

all: $(P_NAME) $(C_NAME) 
	
	@ P_OBJ: $(P_SRC) $(SRC) $(H)
	@ gcc $(FLG) $(P_SRC) $(SRC) $(H) -c 

	@ C_OBJ: $(C_SRC) $(SRC) $(H)
	@ gcc $(FLG) $(C_SRC) $(SRC) $(H) -c 

$(P_NAME): $(P_OBJ) $(H)
	@ make -C ft_printf
	@ gcc $(FLG) -o $(P_NAME) $(P_OBJ) -I.$(H) $(PRNTF)

$(C_NAME): $(C_OBJ) $(H)
	@ make -C ft_printf
	@ gcc $(FLG) -o $(C_NAME) $(C_OBJ) -I.$(H) $(PRNTF)

clean:
	@ make clean -C ./ft_printf
	@ /bin/rm -f $(C_OBJ) $(P_OBJ)

fclean: clean
	@ make fclean -C ./ft_printf
	@ /bin/rm -f $(C_NAME) $(P_NAME) $(PRNTF)

re: fclean all

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:02:48 by aorji             #+#    #+#             */
/*   Updated: 2018/03/06 17:02:50 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

typedef	struct		s_stack
{
	int				data;
	int				block;
	struct s_stack	*next;
}					t_stack;

void				ft_push(char **param);
t_stack				*ft_make_stack(char **param, int len);
t_stack				*ft_stack_new(void);
int					ft_count_param(char **param);
t_stack				*ft_stack_new(void);
void				ft_sa(t_stack **a);
void				ft_sb(t_stack **b);
void				ft_ss(t_stack **a, t_stack **b);
void				ft_pa(t_stack **a, t_stack **b);
void				ft_pb(t_stack **b, t_stack **a);
int 				ft_st_len(t_stack *st);

#endif

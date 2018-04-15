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
# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>

typedef	struct		s_stack
{
	int				data;
	int				block;
	struct s_stack	*next;
}					t_stack;

typedef	struct		s_res
{
	char			*move;
	int				v;
	struct s_res	*next;
}					t_res;

typedef	struct		s_flags
{
	int				v;
	int				o;
	int				c;
	int				p;
}					t_flag;

void				ft_push(char **param, t_flag f, int len);
t_stack				*ft_make_stack(char **param, int len);
t_stack				*ft_stack_new(int h);
int					ft_count_param(char **param);
void				ft_sa(t_stack **a, t_res **r);
void				ft_sb(t_stack **b, t_res **r);
void				ft_ss(t_stack **a, t_stack **b);
int					ft_pa(t_stack **a, t_stack **b, int half, t_res **r);
int					ft_pb(t_stack **a, t_stack **b, int half, t_res **r);
int					ft_st_len(t_stack *st);
int					ft_ra(t_stack **a, int h, t_res **r);
int					ft_rb(t_stack **b, int h, t_res **r);
int					ft_rr(t_stack **a, t_stack **b, int h);
int					ft_rra(t_stack **a, int h, t_res **r);
int					ft_rrb(t_stack **b, int h, t_res **r);
void				ft_rrr(t_stack **a, t_stack **b, int h);
int					ft_sort_3(t_stack **a, int n, t_res **r);
void				ft_pr_a(t_stack *stack_a);
void				ft_pr_b(t_stack *stack_a);
void				ft_pr(t_stack *a, t_stack *b);
int					ft_mediana(t_stack *stack_a, int len);
int					ft_sort(t_stack **stack_a, t_stack **stack_b,
	int half, t_res **r);
int					ft_mediana_b(t_stack *stack_a, int len);
int					zero_block(t_stack **stack_a);
int					st_len(t_stack *st);
int					smaller(t_stack *st, int med);
int					sm_eq_m(t_stack *st, int med);
int					eq(t_stack *st, int med);
int					bg_eq_m(t_stack *st, int med);
int					biger_that_m(t_stack *st, int med);
int					block_len(t_stack *st, int h);
int					t_block_len(t_stack *st);
int					count_rr_zero(t_stack *a, int l);
int					count_rr(t_stack *b, int l);
int					last(t_stack *stack_a);
t_res				*r_new(int i);
void				clean_move(t_res **h);
void				res_str(t_res **r, const char *s);
int					ft_flag(char *str);
void				debug(t_stack *a, t_stack *b, const char *s);
void				remove_if_one(t_res **h, const char *s1,
	const char *s2, const char *s3);
void				remove_if_two(int len, t_res **h, const char *s1,
	const char *s2);
int					r_len(t_res *st);
void				fr(t_res *t1, t_res *t2);
void				ft_clean(t_res **a, const char *s1, const char *s2);
void				ft_print_res(t_res	**h, t_flag f, int len);
int					f(t_stack **a, t_stack **b, int argc, char ***p);
void				rm_first(t_res **h, const char *s1, const char *s2);
void				ft_sort_b(t_stack **stack_a, t_stack **stack_b,
	int bl, t_res **r);
int					from_1(t_stack **a, t_stack **b, t_res **r, int *med);
int					from_2(t_stack **a, t_res **r, int bl_len);
int					from_3(t_stack **a, t_res **r, int *med);
int					from_4(t_stack **a, t_res **r, int *med);
#endif

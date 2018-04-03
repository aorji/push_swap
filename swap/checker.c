/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:56:14 by aorji             #+#    #+#             */
/*   Updated: 2018/04/02 14:56:20 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		i++;
		(!ft_strcmp("sa", line)) ? ft_sa(stack_a) : 0;
		(!ft_strcmp("sb", line)) ? ft_sb(stack_b) : 0;
		(!ft_strcmp("ss", line)) ? ft_ss(stack_a, stack_b) : 0;
		(!ft_strcmp("pa", line)) ? ft_pa(stack_a, stack_b, 1) : 0;
		(!ft_strcmp("pb", line)) ? ft_pb(stack_a, stack_b, 1) : 0;
		(!ft_strcmp("ra", line)) ? ft_ra(stack_a, 1) : 0;
		(!ft_strcmp("rb", line)) ? ft_rb(stack_b, 1) : 0;
		(!ft_strcmp("rr", line)) ? ft_rr(stack_a, stack_b, 1) : 0;
		(!ft_strcmp("rra", line)) ? ft_rra(stack_a, 1) : 0;
		(!ft_strcmp("rrb", line)) ? ft_rrb(stack_b, 1) : 0;
		(!ft_strcmp("rrr", line)) ? ft_rrr(stack_a, stack_b, 1) : 0;
	}
	printf("moves = %i\n", i);
}

int		main(int argc, char **argv)
{
	char	**param;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		num;

	if (argc < 2)
		return (0);
	if (argc == 2)
		param = ft_strsplit(argv[1], ' ');
	if (argc > 2)
		param = ++argv;
	stack_a = ft_make_stack(param, ft_count_param(param));
	stack_b = NULL;
	ft_make_moves(&stack_a, &stack_b);
	while (stack_a && stack_a->next)
	{
		num = stack_a->data;
		if (num > stack_a->next->data)
			return (ft_printf("Error\n"));
		stack_a = stack_a->next;
	}
	return (ft_printf("OK\n"));
}

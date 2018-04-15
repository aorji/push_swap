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

void	ft_make_moves(t_stack **a, t_stack **b, char **line)
{
	while (ft_strdel(line) && get_next_line(0, line) > 0)
	{
		((!ft_strcmp("sa", *line)) ||
		!ft_strcmp("\x1b[0;36msa\x1b[0m", *line)) ? ft_sa(a, NULL) : 0;
		(!ft_strcmp("sb", *line) ||
		!ft_strcmp("\x1b[0;36msb\x1b[0m", *line)) ? ft_sb(b, NULL) : 0;
		(!ft_strcmp("ss", *line) ||
		!ft_strcmp("\x1b[0;36mss\x1b[0m", *line)) ? ft_ss(a, b) : 0;
		(!ft_strcmp("pa", *line) || !ft_strcmp("\x1b[0;36mpa\x1b[0m", *line)) ?
		ft_pa(a, b, 1, NULL) : 0;
		(!ft_strcmp("pb", *line) || !ft_strcmp("\x1b[0;36mpb\x1b[0m", *line)) ?
		ft_pb(a, b, 1, NULL) : 0;
		(!ft_strcmp("ra", *line) || !ft_strcmp("\x1b[0;36mra\x1b[0m", *line)) ?
		ft_ra(a, 1, NULL) : 0;
		(!ft_strcmp("rb", *line) || !ft_strcmp("\x1b[0;36mrb\x1b[0m", *line)) ?
		ft_rb(b, 1, NULL) : 0;
		(!ft_strcmp("rr", *line) || !ft_strcmp("\x1b[0;36mrr\x1b[0m", *line)) ?
		ft_rr(a, b, 1) : 0;
		(!ft_strcmp("rra", *line) || !ft_strcmp("\x1b[0;36mrra\x1b[0m", *line))
		? ft_rra(a, 1, NULL) : 0;
		(!ft_strcmp("rrb", *line) || !ft_strcmp("\x1b[0;36mrrb\x1b[0m", *line))
		? ft_rrb(b, 1, NULL) : 0;
		(!ft_strcmp("rrr", *line) || !ft_strcmp("\x1b[0;36mrrr\x1b[0m", *line))
		? ft_rrr(a, b, 1) : 0;
	}
}

int		main(int argc, char **argv)
{
	char	**param;
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *t;

	if (argc < 2)
		return (0);
	(argc == 2) ? param = ft_strsplit(argv[1], ' ') : 0;
	(argc > 2) ? param = ++argv : 0;
	stack_a = ft_make_stack(param, ft_count_param(param));
	stack_b = NULL;
	ft_make_moves(&stack_a, &stack_b, &line);
	while (stack_a && stack_a->next)
	{
		t = stack_a;
		if (stack_a->data > stack_a->next->data || ft_st_len(stack_b))
			return (f(&stack_a, &stack_b, argc, &param) * ft_printf("KO\n"));
		stack_a = stack_a->next;
		free(t);
	}
	f(&stack_a, &stack_b, argc, &param);
	return (ft_printf("OK\n"));
}

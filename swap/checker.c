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

static void	ft_fr(t_stack **a, t_stack **b, int argc, char ***p)
{
	t_stack	*t;
	char	**param;

	free(*b);
	param = *p;
	while (*a)
	{
		t = *a;
		*a = (*a)->next;
		free(t);
	}
	if (argc == 2)
	{
		while (*param)
		{
			ft_strdel(param);
			param++;
		}
	}
}

void		ft_make_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		((!ft_strcmp("sa", line)) || !ft_strcmp("\x1b[0;36msa\x1b[0m", line)) ?
		ft_sa(stack_a, NULL) : 0;
		(!ft_strcmp("sb", line) || !ft_strcmp("\x1b[0;36msb\x1b[0m", line)) ?
		ft_sb(stack_b, NULL) : 0;
		(!ft_strcmp("ss", line) || !ft_strcmp("\x1b[0;36mss\x1b[0m", line)) ?
		ft_ss(stack_a, stack_b) : 0;
		(!ft_strcmp("pa", line) || !ft_strcmp("\x1b[0;36mpa\x1b[0m", line)) ?
		ft_pa(stack_a, stack_b, 1, NULL) : 0;
		(!ft_strcmp("pb", line) || !ft_strcmp("\x1b[0;36mpb\x1b[0m", line)) ?
		ft_pb(stack_a, stack_b, 1, NULL) : 0;
		(!ft_strcmp("ra", line) || !ft_strcmp("\x1b[0;36mra\x1b[0m", line)) ?
		ft_ra(stack_a, 1, NULL) : 0;
		(!ft_strcmp("rb", line) || !ft_strcmp("\x1b[0;36mrb\x1b[0m", line)) ?
		ft_rb(stack_b, 1, NULL) : 0;
		(!ft_strcmp("rr", line) || !ft_strcmp("\x1b[0;36mrr\x1b[0m", line)) ?
		ft_rr(stack_a, stack_b, 1) : 0;
		(!ft_strcmp("rra", line) || !ft_strcmp("\x1b[0;36mrra\x1b[0m", line)) ?
		ft_rra(stack_a, 1, NULL) : 0;
		(!ft_strcmp("rrb", line) || !ft_strcmp("\x1b[0;36mrrb\x1b[0m", line)) ?
		ft_rrb(stack_b, 1, NULL) : 0;
		(!ft_strcmp("rrr", line) || !ft_strcmp("\x1b[0;36mrrr\x1b[0m", line)) ?
		ft_rrr(stack_a, stack_b, 1) : 0;
		ft_strdel(&line);
	}
}

int			main(int argc, char **argv)
{
	char	**param;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *t;

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
		t = stack_a;
		if (stack_a->data > stack_a->next->data || ft_st_len(stack_b))
		{
			ft_fr(&stack_a, &stack_b, argc, &param);
			return (ft_printf("KO\n"));
		}
		stack_a = stack_a->next;
		free(t);
	}
	ft_fr(&stack_a, &stack_b, argc, &param);
	system("leaks checker");
	return (ft_printf("OK\n"));
}

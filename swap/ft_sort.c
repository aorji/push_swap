/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:16:11 by aorji             #+#    #+#             */
/*   Updated: 2018/03/09 20:16:13 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b(t_stack **stack_a, t_stack **stack_b, int bl, t_res **r)
{
	static int mediana;
	static int m;

	if (!(m++))
		mediana = ft_mediana(*stack_b, block_len(*stack_b, (*stack_b)->block));
	if (!bg_eq_m(*stack_b, mediana) && !(m = 0))
		return ;
	if ((*stack_b)->data > mediana && ft_pa(stack_a, stack_b, bl, r))
	{
		while (!bg_eq_m(*stack_b, mediana) && *stack_b &&
			count_rr(*stack_b, last(*stack_b)))
			ft_rrb(stack_b, last(*stack_b), r);
		ft_sort_b(stack_a, stack_b, bl, r);
	}
	else if ((*stack_b)->data < mediana && ft_rb(stack_b, (*stack_b)->block, r))
		ft_sort_b(stack_a, stack_b, bl, r);
	else if ((*stack_b)->data == mediana && biger_that_m(*stack_b, mediana)
		&& ft_pa(stack_a, stack_b, bl, r))
		ft_sort_b(stack_a, stack_b, bl, r);
	else if ((*stack_b)->data == mediana && !biger_that_m(*stack_b, mediana)
		&& ft_pa(stack_a, stack_b, bl, r))
	{
		while (*stack_b && count_rr(*stack_b, last(*stack_b)))
			ft_rrb(stack_b, last(*stack_b), r);
	}
}

int		ft_sort(t_stack **a, t_stack **b, int half, t_res **r)
{
	int			bl_len;
	static int	med[2];

	(!(med[1]++)) ? med[0] = ft_mediana(*a, ft_st_len(*a)) : 0;
	if (!(*a)->block && !ft_st_len(*b))
		return (1);
	else if (!t_block_len(*a))
		return (from_1(a, b, r, &med[0]) * ft_sort(a, b, (*a)->block, r));
	else if ((bl_len = t_block_len(*a)) <= 3 && ((smaller(*a, med[0])
		&& eq(*a, med[0])) || (!smaller(*a, med[0]))))
		return (from_2(a, r, bl_len) * ft_sort(a, b, half, r));
	else if ((*a)->data > med[0] && (*a)->block && ft_ra(a, half, r))
		return (ft_sort(a, b, half, r));
	else if ((*a)->data < med[0] && (*a)->block && ft_pb(a, b, half, r))
	{
		if (!sm_eq_m(*a, med[0]))
			return (from_3(a, r, &med[0]) * ft_sort(a, b, st_len(*a) / 2, r));
		return (ft_sort(a, b, half, r));
	}
	else if ((*a)->data == med[0] && !(smaller(*a, med[0])) && (*a)->block)
		return (ft_pb(a, b, half, r) * from_4(a, r, &med[0]) *
			ft_sort(a, b, st_len(*a) / 2, r));
	else if ((*a)->data == med[0] && smaller(*a, med[0]) && (*a)->block)
		return (ft_pb(a, b, half, r) * ft_sort(a, b, half, r));
	return (1);
}

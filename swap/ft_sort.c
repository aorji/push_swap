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

static void	ft_sort_b(t_stack **stack_a, t_stack **stack_b, int bl, t_res **r)
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

int			ft_sort(t_stack **a, t_stack **b, int half, t_res **r)
{
	int			bl_len;
	static int	mm;
	static int	med;

	if (!(mm++))
		med = ft_mediana(*a, ft_st_len(*a));
	if (!(*a)->block && !ft_st_len(*b))
		return (1);
	else if (!t_block_len(*a))
	{
		ft_sort_b(a, b, (*b)->block / 2, r);
		med = ft_mediana_b(*a, block_len(*a, (*a)->block));
		ft_sort(a, b, (*a)->block, r);
	}
	else if ((bl_len = t_block_len(*a)) <= 3 && ((smaller_that_m(*a, med)
		&& eq(*a, med)) || (!smaller_that_m(*a, med))))
	{
		while (count_rr_zero(*a, last(*a)))
			ft_rra(a, last(*a), r);
		ft_sort_3(a, bl_len, r);
		ft_sort(a, b, half, r);
	}
	else if ((*a)->data > med && (*a)->block && ft_ra(a, half, r))
		return (ft_sort(a, b, half, r));
	else if ((*a)->data < med && (*a)->block && ft_pb(a, b, half, r))
	{
		if (!sm_eq_m(*a, med))
		{
			while (count_rr_zero(*a, last(*a)))
				ft_rra(a, last(*a), r);
			med = ft_mediana_b(*a, t_block_len(*a));
			return (ft_sort(a, b, ft_st_len_true(*a) / 2, r));
		}
		return (ft_sort(a, b, half, r));
	}
	else if ((*a)->data == med && !(smaller_that_m(*a, med)) && (*a)->block)
	{
		ft_pb(a, b, half, r);
		while (count_rr_zero(*a, last(*a)))
			ft_rra(a, last(*a), r);
		med = ft_mediana_b(*a, t_block_len(*a));
		return (ft_sort(a, b, ft_st_len_true(*a) / 2, r));
	}
	else if ((*a)->data == med && smaller_that_m(*a, med)
		&& (*a)->block && ft_pb(a, b, half, r))
		return (ft_sort(a, b, half, r));
	return (1);
}

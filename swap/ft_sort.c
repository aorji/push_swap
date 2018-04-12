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
		while (!bg_eq_m(*stack_b, mediana) && *stack_b && count_rr(*stack_b, last(*stack_b)))
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

int	ft_sort(t_stack **stack_a, t_stack **stack_b, int half, t_res **r)
{

	int bl_len;
	static int mm;
	static int mediana;

	if (!(mm++))
		mediana = ft_mediana(*stack_a, ft_st_len(*stack_a));
	if (!(*stack_a)->block && !ft_st_len(*stack_b))
		return (1);
	else if (!t_block_len(*stack_a))
	{
		ft_sort_b(stack_a, stack_b, (*stack_b)->block/2, r);
		mediana = ft_mediana_b(*stack_a, block_len(*stack_a, (*stack_a)->block));
		ft_sort(stack_a, stack_b, (*stack_a)->block, r);
	}
	else if ((bl_len = t_block_len(*stack_a)) <= 3 && ((smaller_that_m(*stack_a, mediana) 
		&& eq(*stack_a, mediana)) || (!smaller_that_m(*stack_a, mediana))))
	{
		while (count_rr_zero(*stack_a, last(*stack_a)))
			ft_rra(stack_a, last(*stack_a), r);
		ft_sort_3(stack_a, bl_len, r);
		ft_sort(stack_a, stack_b, half, r);
	}
	else if ((*stack_a)->data > mediana && (*stack_a)->block && ft_ra(stack_a, half, r))
		return (ft_sort(stack_a, stack_b, half, r));
	else if ((*stack_a)->data < mediana && (*stack_a)->block && ft_pb(stack_a, stack_b, half, r))
	{
		if (!sm_eq_m(*stack_a, mediana))
		{
			while (count_rr_zero(*stack_a, last(*stack_a)))
				ft_rra(stack_a, last(*stack_a), r);
			mediana = ft_mediana_b(*stack_a, t_block_len(*stack_a));
			return (ft_sort(stack_a, stack_b, ft_st_len_true(*stack_a)/2, r));
		}
		return (ft_sort(stack_a, stack_b, half, r));
	}
	else if ((*stack_a)->data == mediana && !(smaller_that_m(*stack_a, mediana)) && (*stack_a)->block)
	{
		ft_pb(stack_a, stack_b, half, r);
		while (count_rr_zero(*stack_a, last(*stack_a)))
			ft_rra(stack_a, last(*stack_a), r);
		mediana = ft_mediana_b(*stack_a, t_block_len(*stack_a));
		return (ft_sort(stack_a, stack_b, ft_st_len_true(*stack_a)/2, r));
	}
	else if ((*stack_a)->data == mediana && smaller_that_m(*stack_a, mediana) 
		&& (*stack_a)->block && ft_pb(stack_a, stack_b, half, r))
		return (ft_sort(stack_a, stack_b, half, r));
	return (1);
}

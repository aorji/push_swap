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

static int	ft_sort_b(t_stack **stack_a, t_stack **stack_b, int mediana, int bl)
{
	if (!bg_eq_m(*stack_b, mediana))
		return (1);
	if ((*stack_b)->data > mediana)
	{
		ft_pa(stack_a, stack_b, bl);
		if (!bg_eq_m(*stack_b, mediana))
			if (*stack_b)
				while (count_rr(*stack_b, last(*stack_b)))
					ft_rrb(stack_b, last(*stack_b));
		ft_sort_b(stack_a, stack_b, mediana, bl);
	}
	else if ((*stack_b)->data < mediana)
	{
		ft_rb(stack_b, (*stack_b)->block);
		ft_sort_b(stack_a, stack_b, mediana, bl);
	}
	else if ((*stack_b)->data == mediana && biger_that_m(*stack_b, mediana))
	{
		ft_pa(stack_a, stack_b, bl);
		ft_sort_b(stack_a, stack_b, mediana, bl);
	}
	else if ((*stack_b)->data == mediana && !biger_that_m(*stack_b, mediana))
	{
		ft_pa(stack_a, stack_b, bl);
		if (*stack_b)
			while (count_rr(*stack_b, last(*stack_b)))
				ft_rrb(stack_b, last(*stack_b));
	}
	return (1);
}

int	ft_sort(t_stack **stack_a, t_stack **stack_b, int mediana, int half)
{
	int m;
	int m1;
	int bl_len;

	if (!(*stack_a)->block && !ft_st_len(*stack_b))
		return (1);
	else if (!t_block_len(*stack_a))
	{
		m = ft_mediana(*stack_b, block_len(*stack_b, (*stack_b)->block));
		ft_sort_b(stack_a, stack_b, ft_mediana(*stack_b, block_len(*stack_b, (*stack_b)->block)), (*stack_b)->block/2);
		m1 = ft_mediana_b(*stack_a, block_len(*stack_a, (*stack_a)->block));
		ft_sort(stack_a, stack_b, m1, (*stack_a)->block);
	}
	else if ((bl_len = t_block_len(*stack_a)) <= 3 && ((smaller_that_m(*stack_a, mediana) && eq(*stack_a, mediana)) || (!smaller_that_m(*stack_a, mediana))))
	{
		while (count_rr_zero(*stack_a, last(*stack_a)))
				ft_rra(stack_a, last(*stack_a));
		ft_sort_3(stack_a, bl_len);
		ft_sort(stack_a, stack_b, mediana, half);
	}
	else if ((*stack_a)->data > mediana && (*stack_a)->block)
	{
		ft_ra(stack_a, half);
		return (ft_sort(stack_a, stack_b, mediana, half));
	}
	else if ((*stack_a)->data < mediana && (*stack_a)->block)
	{
		ft_pb(stack_a, stack_b, half);
		if (!sm_eq_m(*stack_a, mediana))
		{
			while (count_rr_zero(*stack_a, last(*stack_a)))
				ft_rra(stack_a, last(*stack_a));
			return (ft_sort(stack_a, stack_b, ft_mediana_b(*stack_a, t_block_len(*stack_a)), ft_st_len_true(*stack_a)/2));
		}
		return (ft_sort(stack_a, stack_b, mediana, half));
	}
	else if ((*stack_a)->data == mediana && !(smaller_that_m(*stack_a, mediana)) && (*stack_a)->block)
	{
		ft_pb(stack_a, stack_b, half);
		while (count_rr_zero(*stack_a, last(*stack_a)))
				ft_rra(stack_a, last(*stack_a));
		return (ft_sort(stack_a, stack_b, ft_mediana_b(*stack_a, t_block_len(*stack_a)), ft_st_len_true(*stack_a)/2));
	}
	else if ((*stack_a)->data == mediana && smaller_that_m(*stack_a, mediana) && (*stack_a)->block)
	{
		ft_pb(stack_a, stack_b, half);
		return (ft_sort(stack_a, stack_b, mediana, half));
	}
	return (1);
}

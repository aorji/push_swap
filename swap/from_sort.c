/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:03:45 by aorji             #+#    #+#             */
/*   Updated: 2018/04/15 15:03:47 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	from_1(t_stack **a, t_stack **b, t_res **r, int *med)
{
	ft_sort_b(a, b, (*b)->block / 2, r);
	*med = ft_mediana_b(*a, block_len(*a, (*a)->block));
	return (1);
}

int	from_2(t_stack **a, t_res **r, int bl_len)
{
	while (count_rr_zero(*a, last(*a)))
		ft_rra(a, last(*a), r);
	ft_sort_3(a, bl_len, r);
	return (1);
}

int	from_3(t_stack **a, t_res **r, int *med)
{
	while (count_rr_zero(*a, last(*a)))
		ft_rra(a, last(*a), r);
	*med = ft_mediana_b(*a, t_block_len(*a));
	return (1);
}

int	from_4(t_stack **a, t_res **r, int *med)
{
	while (count_rr_zero(*a, last(*a)))
		ft_rra(a, last(*a), r);
	*med = ft_mediana_b(*a, t_block_len(*a));
	return (1);
}

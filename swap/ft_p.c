/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:15:03 by aorji             #+#    #+#             */
/*   Updated: 2018/03/06 18:15:04 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa(t_stack **a, t_stack **b, int half)
{
	t_stack *head;

	if (ft_st_len(*b) < 1)
		return (1);
	head = ft_stack_new(half);
	head->data = (*b)->data;
	head->block = half;
	head->next = (*a);
	*b = (*b)->next;
	*a = head;
	g_count_moves++;
	// printf("%s\n", "p");
	return (1);
}

int	ft_pb(t_stack **a, t_stack **b, int half)
{
	ft_pa(b, a, half);
	return (1);
}

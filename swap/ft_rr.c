/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:21:39 by aorji             #+#    #+#             */
/*   Updated: 2018/03/07 15:21:41 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a)
{
	int s;
	t_stack	*head;
	
	if (ft_st_len(*a) < 2)
		return ;
	s = (*a)->data;
	head = (*a);
	(*a) = (*a)->next;
	while (head->next)
		head = head->next;
	head->next = ft_stack_new();
	head->next->data = s;
}

void	ft_rb(t_stack **b)
{
	ft_ra(b);
}


void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a);
	ft_rb(b);
}

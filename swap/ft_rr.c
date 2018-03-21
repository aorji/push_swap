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

int	ft_ra(t_stack **a, int h)
{
	int s;
	t_stack	*head;
	
	if (ft_st_len(*a) < 2)
		return (0);
	s = (*a)->data;
	head = (*a);
	(*a) = (*a)->next;
	while (head->next)
		head = head->next;
	head->next = ft_stack_new(h);
	head->next->data = s;
	return(1);
}

int	ft_rb(t_stack **b, int h)
{
	ft_ra(b, h);
	return (1);
}


int	ft_rr(t_stack **a, t_stack **b, int h)
{
	ft_ra(a, h);
	ft_rb(b, h);
	return (1);
}

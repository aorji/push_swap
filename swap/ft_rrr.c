/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:49:26 by aorji             #+#    #+#             */
/*   Updated: 2018/03/07 15:49:29 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **a)
{
	t_stack	*new;
	t_stack	*run;
	
	if (ft_st_len(*a) < 2)
		return ;
	new = ft_stack_new();
	new->next = (*a);
	run = new->next;
	while (run->next->next)
		run = run->next;
	new->data = run->next->data;
	run->next = NULL;
	(*a) = new;
}

void	ft_rrb(t_stack **b)
{
	ft_rra(b);
}



void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a);
	ft_rrb(b);
}

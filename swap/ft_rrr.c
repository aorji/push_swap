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

int		ft_rra(t_stack **a, int h)
{
	t_stack	*new;
	t_stack	*run;

	if (ft_st_len(*a) < 2)
		return (1);
	new = ft_stack_new(h);
	new->next = (*a);
	run = new->next;
	while (run->next->next)
		run = run->next;
	new->data = run->next->data;
	run->next = NULL;
	(*a) = new;
	ft_printf("%s\n", "rra");
	return (1);
}

int		ft_rrb(t_stack **a, int h)
{
	t_stack	*new;
	t_stack	*run;

	if (ft_st_len(*a) < 2)
		return (1);
	new = ft_stack_new(h);
	new->next = (*a);
	run = new->next;
	while (run->next->next)
		run = run->next;
	new->data = run->next->data;
	run->next = NULL;
	(*a) = new;
	ft_printf("%s\n", "rrb");
	return (1);
}

void	ft_rrr(t_stack **a, t_stack **b, int h)
{
	t_stack	*new;
	t_stack	*run;

	(ft_st_len(*a) < 2 && ft_st_len(*b) < 2) ? 0 : ft_printf("%s\n", "rrr");
	if (ft_st_len(*a) >= 2)
	{
		new = ft_stack_new(h);
		new->next = (*a);
		run = new->next;
		while (run->next->next)
			run = run->next;
		new->data = run->next->data;
		run->next = NULL;
		(*a) = new;
	}
	if (ft_st_len(*b) >= 2)
	{
		new = ft_stack_new(h);
		new->next = (*b);
		run = new->next;
		while (run->next->next)
			run = run->next;
		new->data = run->next->data;
		run->next = NULL;
		(*b) = new;
	}
}

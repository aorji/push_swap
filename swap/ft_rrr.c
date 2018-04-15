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

int		ft_rra(t_stack **a, int h, t_res **r)
{
	t_stack	*new;
	t_stack	*run;
	t_stack *tmp;

	if (ft_st_len(*a) < 2)
		return (1);
	new = ft_stack_new(h);
	new->next = (*a);
	run = new->next;
	while (run->next->next)
		run = run->next;
	new->data = run->next->data;
	tmp = run->next;
	run->next = NULL;
	free(tmp);
	(*a) = new;
	r && ((*r)->v) ? debug(*a, NULL, "rra") : 0;
	r ? res_str(r, "rra") : 0;
	return (1);
}

int		ft_rrb(t_stack **a, int h, t_res **r)
{
	t_stack	*new;
	t_stack	*run;
	t_stack *tmp;

	if (ft_st_len(*a) < 2)
		return (1);
	new = ft_stack_new(h);
	new->next = (*a);
	run = new->next;
	while (run->next->next)
		run = run->next;
	new->data = run->next->data;
	tmp = run->next;
	run->next = NULL;
	free(tmp);
	(*a) = new;
	r && ((*r)->v) ? debug(NULL, *a, "rrb") : 0;
	r ? res_str(r, "rrb") : 0;
	return (1);
}

void	ft_rrr(t_stack **a, t_stack **b, int h)
{
	t_stack	*new;
	t_stack	*run;
	t_stack *tmp;

	if (ft_st_len(*a) >= 2)
		ft_rra(a, h, NULL);
	if (ft_st_len(*b) >= 2)
		ft_rra(b, h, NULL);
}

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

int	ft_ra(t_stack **a, int h, t_res **r)
{
	int		s;
	t_stack	*head;
	t_stack	*tmp;

	if (ft_st_len(*a) < 2)
		return (1);
	s = (*a)->data;
	head = (*a);
	tmp = (*a);
	(*a) = (*a)->next;
	while (head->next)
		head = head->next;
	free(tmp);
	head->next = ft_stack_new(h);
	head->next->data = s;
	r && ((*r)->v) ? debug(*a, NULL, "ra") : 0;
	r ? res_str(r, "ra") : 0;
	return (1);
}

int	ft_rb(t_stack **a, int h, t_res **r)
{
	int		s;
	t_stack	*head;
	t_stack	*tmp;

	if (ft_st_len(*a) < 2)
		return (1);
	s = (*a)->data;
	head = (*a);
	tmp = (*a);
	(*a) = (*a)->next;
	while (head->next)
		head = head->next;
	free(tmp);
	head->next = ft_stack_new(h);
	head->next->data = s;
	r && ((*r)->v) ? debug(NULL, *a, "rb") : 0;
	r ? res_str(r, "rb") : 0;
	return (1);
}

int	ft_rr(t_stack **a, t_stack **b, int h)
{
	int		s;
	t_stack	*head;
	t_stack	*tmp;

	if (ft_st_len(*a) >= 2)
		ft_ra(a, h, NULL);
	if (ft_st_len(*b) >= 2)
		ft_rb(b, h, NULL);
	return (1);
}

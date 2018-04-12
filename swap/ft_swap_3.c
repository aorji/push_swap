/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 17:07:46 by aorji             #+#    #+#             */
/*   Updated: 2018/03/09 17:07:48 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_type1(t_stack **stack_a, int h, t_res **r)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data &&
		(*stack_a)->next->data < (*stack_a)->next->next->data)
		ft_sa(stack_a, r);
	else if ((*stack_a)->data > (*stack_a)->next->next->data &&
		(*stack_a)->next->data < (*stack_a)->next->next->data)
		ft_ra(stack_a, h, r);
	else if ((*stack_a)->data > (*stack_a)->next->next->data &&
		(*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		ft_ra(stack_a, h, r);
		ft_sa(stack_a, r);
	}
}

static	void	ft_type2(t_stack **stack_a, int h, t_res **r)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data)
	{
		ft_rra(stack_a, h, r);
		ft_sa(stack_a, r);
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data)
		ft_rra(stack_a, h, r);
}

static	void	ft_type4(t_stack **stack_a, int h, t_res **r)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data)
	{
		ft_ra(stack_a, h, r);
		ft_sa(stack_a, r);
		ft_rra(stack_a, h, r);
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data)
	{
	
		ft_ra(stack_a, h, r);
		ft_sa(stack_a, r);
		ft_rra(stack_a, h, r);
		ft_sa(stack_a, r);
	}
}

static	void	ft_type3(t_stack **stack_a, int h, t_res **r)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data &&
		(*stack_a)->next->data < (*stack_a)->next->next->data)
		ft_sa(stack_a, r);
	else if ((*stack_a)->data > (*stack_a)->next->next->data &&
		(*stack_a)->next->data < (*stack_a)->next->next->data)
	{
		ft_sa(stack_a, r);
		ft_ra(stack_a, h, r);
		ft_sa(stack_a, r);
		ft_rra(stack_a, h, r);
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data &&
		(*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		ft_sa(stack_a, r);
		ft_ra(stack_a, h, r);
		ft_sa(stack_a, r);
		ft_rra(stack_a, h, r);
		ft_sa(stack_a, r);
	}
}

int				ft_sort_3(t_stack **stack_a, int n, t_res **r)
{
	if (n == 1 || (n == 3 && ((*stack_a)->data < (*stack_a)->next->data &&
		(*stack_a)->next->data < (*stack_a)->next->next->data)))
		return (zero_block(stack_a));
	else if (ft_st_len(*stack_a) > 3 && n == 3)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			ft_type3(stack_a, n / 2, r);
		else if ((*stack_a)->data < (*stack_a)->next->data)
			ft_type4(stack_a, n / 2, r);
		zero_block(stack_a);
	}
	else if (n == 2 && zero_block(stack_a))
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			ft_sa(stack_a, r);
	}
	else if (n == 3)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			ft_type1(stack_a, n / 2, r);
		else if ((*stack_a)->data < (*stack_a)->next->data)
			ft_type2(stack_a, n / 2, r);
		zero_block(stack_a);
	}
	return (1);
}

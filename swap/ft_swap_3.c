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

static	int		zero_block(t_stack **stack_a)
{
	t_stack *bl;

	bl = *stack_a;
	while (bl)
	{
		bl->block = 0;
		bl = bl->next;
	}
	return (1);
}

static	void	ft_type1(t_stack **stack_a, int h)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data &&
		(*stack_a)->next->data < (*stack_a)->next->next->data)
		ft_sa(stack_a);
	else if ((*stack_a)->data > (*stack_a)->next->next->data &&
		(*stack_a)->next->data < (*stack_a)->next->next->data)
		ft_ra(stack_a, h);
	else if ((*stack_a)->data > (*stack_a)->next->next->data &&
		(*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		ft_ra(stack_a, h);
		ft_sa(stack_a);
	}
}

static	void	ft_type2(t_stack **stack_a, int h)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data)
	{
		ft_rra(stack_a, h);
		ft_sa(stack_a);
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data)
		ft_rra(stack_a, h);
}

static	void	ft_type4(t_stack **stack_a, int h)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data)
	{
		ft_ra(stack_a, h);
		ft_sa(stack_a);
		ft_rra(stack_a, h);
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data)
	{
		ft_ra(stack_a, h);
		ft_sa(stack_a);
		ft_rra(stack_a, h);
		ft_sa(stack_a);
	}
}

static	void	ft_type3(t_stack **stack_a, int h)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data &&
		(*stack_a)->next->data < (*stack_a)->next->next->data)
		ft_sa(stack_a);
	else if ((*stack_a)->data > (*stack_a)->next->next->data &&
		(*stack_a)->next->data < (*stack_a)->next->next->data)
	{
		ft_sa(stack_a);
		ft_ra(stack_a, h);
		ft_sa(stack_a);
		ft_rra(stack_a, h);
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data &&
		(*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		ft_sa(stack_a);
		ft_ra(stack_a, h);
		ft_sa(stack_a);
		ft_rra(stack_a, h);
		ft_sa(stack_a);
	}	
}

int				ft_sort_3(t_stack **stack_a, int n)
{
	if (n == 1 || (n == 3 && ((*stack_a)->data < (*stack_a)->next->data &&
		(*stack_a)->next->data < (*stack_a)->next->next->data)))
		return(zero_block(stack_a));
	else if (ft_st_len(*stack_a) > 3 && n == 3 && zero_block(stack_a))
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			ft_type3(stack_a, n / 2);
		else if ((*stack_a)->data < (*stack_a)->next->data)
			ft_type4(stack_a, n / 2);
	}
	else if (n == 2 && zero_block(stack_a))
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			ft_sa(stack_a);
	}
	else if (n == 3 && zero_block(stack_a))
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			ft_type1(stack_a, n / 2);
		else if ((*stack_a)->data < (*stack_a)->next->data)
			ft_type2(stack_a, n / 2);
	}
	return (1);
}

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

static void zero_block(t_stack **stack_a)
{
	t_stack *bl;
	bl = *stack_a;

	while (bl)
	{
		bl->block = 0;
		bl = bl->next;
	}
}

static void	ft_type1(t_stack **stack_a)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data && 
		(*stack_a)->next->data < (*stack_a)->next->next->data)
	{
		ft_sa(stack_a);
		//ft_printf("%s\n", "sa");
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data && 
		(*stack_a)->next->data < (*stack_a)->next->next->data)
	{
		ft_ra(stack_a);
		// ft_printf("%s\n", "ra");
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data && 
		(*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		// ft_printf("%s\n%s\n", "ra", "sa");
	}	
}

static	void	ft_type2(t_stack **stack_a)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data)
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
		// ft_printf("%s\n%s\n", "rra", "sa");
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data)
	{
		ft_rra(stack_a);
		// ft_printf("%s\n", "rra");
	}
}

void	ft_sort_3(t_stack **stack_a, int n)
{
	if (n == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
		{
			ft_sa(stack_a);
			// ft_printf("%s\n", "sa");
		}
		return ;
	}
	else if (n == 1 || ((*stack_a)->data < (*stack_a)->next->data &&
		(*stack_a)->next->data < (*stack_a)->next->next->data))
		return ;
	else if (n == 3)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			ft_type1(stack_a);
		else if ((*stack_a)->data < (*stack_a)->next->data)
			ft_type2(stack_a);
	}
	zero_block(stack_a);
}

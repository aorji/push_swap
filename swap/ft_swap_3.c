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

static void	ft_type1(t_stack **stack_a, int h)
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
		ft_ra(stack_a, h);
		// ft_printf("%s\n", "ra");
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data && 
		(*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		ft_ra(stack_a, h);
		ft_sa(stack_a);
		// ft_printf("%s\n%s\n", "ra", "sa");
	}	
}

static	void	ft_type2(t_stack **stack_a, int h)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data)
	{
		ft_rra(stack_a, h);
		ft_sa(stack_a);
		// ft_printf("%s\n%s\n", "rra", "sa");
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data)
	{
		ft_rra(stack_a, h);
		// ft_printf("%s\n", "rra");
	}
}

static	void	ft_type4(t_stack **stack_a, int h)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data)
	{
		ft_ra(stack_a, h);
		ft_sa(stack_a);
		ft_rra(stack_a, h);
		// ft_printf("%s\n%s\n", "rra", "sa");
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data)
	{
		ft_ra(stack_a, h);
		ft_sa(stack_a);
		ft_rra(stack_a, h);
		ft_sa(stack_a);
		// ft_printf("%s\n", "rra");
	}
}

static	void	ft_type3(t_stack **stack_a, int h)
{
	if ((*stack_a)->data < (*stack_a)->next->next->data && 
		(*stack_a)->next->data < (*stack_a)->next->next->data)
	{
		ft_sa(stack_a);
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data && 
		(*stack_a)->next->data < (*stack_a)->next->next->data)
	{
		ft_sa(stack_a);
		ft_ra(stack_a, h);
		ft_sa(stack_a);
		ft_rra(stack_a, h);
		// ft_printf("%s\n", "ra");
	}
	else if ((*stack_a)->data > (*stack_a)->next->next->data && 
		(*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		ft_sa(stack_a);
		ft_ra(stack_a, h);
		ft_sa(stack_a);
		ft_rra(stack_a, h);
		ft_sa(stack_a);
		// ft_printf("%s\n%s\n", "ra", "sa");
	}	
}

int	ft_sort_3(t_stack **stack_a, int n)
{
	if (n == 1 || ((*stack_a)->data < (*stack_a)->next->data &&
		(*stack_a)->next->data < (*stack_a)->next->next->data))
	{
		zero_block(stack_a);
		return (1);
	}
	else if (ft_st_len(*stack_a) > 3 && n == 3)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			ft_type3(stack_a, n/2);
		else if ((*stack_a)->data < (*stack_a)->next->data)
			ft_type4(stack_a, n/2);
		zero_block(stack_a);
		return (1);
	}
	// printf("--------------------->%s\n", "sort 3");
	else if (n == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
		{
			ft_sa(stack_a);
			// ft_printf("%s\n", "sa");
		}
		zero_block(stack_a);
		return (1);
	}
	
	else if (n == 3)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			ft_type1(stack_a, n/2);
		else if ((*stack_a)->data < (*stack_a)->next->data)
			ft_type2(stack_a, n/2);
		zero_block(stack_a);
	}
	return (1);
}

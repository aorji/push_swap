/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:16:11 by aorji             #+#    #+#             */
/*   Updated: 2018/03/09 20:16:13 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int smaller_that_m(t_stack *st, int med) // ест что-то меньше, чем медиана -> 1;
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->data < med)
			return(1);
		s = s->next;
	}
	return (0);
}

static int biger_that_m(t_stack *st, int med) // ест что-то больше, чем медиана -> 1;
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->data > med)
			return(1);
		s = s->next;
	}
	return (0);
}

static int block_len(t_stack *st, int h)
{
	int i;
	i = 0;
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->block == h)
			i++;
		s = s->next;
	}
	return (i);
}

static int	ft_sort_b(t_stack **stack_a, t_stack **stack_b, int mediana, int half)
{
	if (ft_st_len(*stack_b) == 1)
		return (ft_pa(stack_a, stack_b, half) * ft_sort_b(stack_a, stack_b, mediana, half));
	if (!biger_that_m(*stack_b, mediana))
		return (1);
	else if ((*stack_b)->data > mediana)
		return (ft_pa(stack_a, stack_b, half) * ft_sort_b(stack_a, stack_b, mediana, half));
	else if ((*stack_b)->data < mediana)
		return (ft_rb(stack_b, (*stack_b)->block) * ft_sort_b(stack_a, stack_b, mediana, half));
	else if ((*stack_b)->data == mediana)
		return (ft_rb(stack_b, (*stack_b)->block) * ft_sort_b(stack_a, stack_b, mediana, half));
	return (1);
}


int	ft_sort(t_stack **stack_a, t_stack **stack_b, int mediana, int half)
{
	int len;
	int bl_len;

	len = ft_st_len(*stack_a);
	// printf("med = %d\n", mediana);
	ft_pr_a(*stack_a);
	ft_pr_b(*stack_b);
	if (!(*stack_a)->block && !ft_st_len(*stack_b))
		return (1);
	else if (!(*stack_a)->block)
		return (ft_sort_b(stack_a, stack_b, ft_mediana(*stack_b, block_len(*stack_b, half)), block_len(*stack_b, half)/2) * ft_sort(stack_a, stack_b, mediana, half));
	else if ((bl_len = block_len(*stack_a, half)) <= 3)
		return (ft_sort_3(stack_a, bl_len) * ft_sort(stack_a, stack_b, mediana, half));
	else if ((*stack_a)->data > mediana)
		return (ft_ra(stack_a, half) * ft_sort(stack_a, stack_b, mediana, half));
	else if ((*stack_a)->data < mediana)
		return (ft_pb(stack_a, stack_b, half) * ft_sort(stack_a, stack_b, mediana, half));
	else if ((*stack_a)->data == mediana && !(smaller_that_m(*stack_a, mediana)))
		return (ft_pb(stack_a, stack_b, half) * ft_sort(stack_a, stack_b, ft_mediana(*stack_a, ft_st_len(*stack_a)), half));
	else if ((*stack_a)->data == mediana && smaller_that_m(*stack_a, mediana))
		return (ft_ra(stack_a, half) * ft_sort(stack_a, stack_b, mediana, half));
	return (1);
}


// работает на 9 -  make re && ./push_swap 3 2 1 4 -9 0 77 -23 44
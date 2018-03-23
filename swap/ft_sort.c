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
static int t_block_len(t_stack *st)
{
	int i;
	i = 0;
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->block)
			i++;
		s = s->next;
	}
	return (i);
}

static int	ft_sort_b(int a, t_stack **stack_a, t_stack **stack_b, int mediana, int half)
{a = 0;
	half = 3;
	printf("---> %s\n", "b");
	printf("med = %d\n", mediana);
	ft_pr_a(*stack_a);
	ft_pr_b(*stack_b);
	printf("half = %d\n", half);
	if ((*stack_b)->data > mediana)
		ft_sort_b(ft_pa(stack_a, stack_b, half), stack_a, stack_b, mediana, half);
	else if ((*stack_b)->data < mediana)
		ft_sort_b(ft_rb(stack_b, (*stack_b)->block), stack_a, stack_b, mediana, half);
	else if ((*stack_b)->data == mediana && biger_that_m(*stack_b, mediana))
		ft_sort_b(ft_rb(stack_b, (*stack_b)->block), stack_a, stack_b, mediana, half);
	else if ((*stack_b)->data == mediana && !biger_that_m(*stack_b, mediana))
		return (ft_pa(stack_a, stack_b, half));
	return (1);
}

int	ft_sort(int a, t_stack **stack_a, t_stack **stack_b, int mediana, int half)
{
	int len;
	int bl_len;
	a = 0;

	printf("---> %s\n", "a");
	printf("med = %d\n", mediana);
	ft_pr_a(*stack_a);
	ft_pr_b(*stack_b);
	len = ft_st_len(*stack_a);
	if (!(*stack_a)->block && !ft_st_len(*stack_b))
		return (1);
	else if (!(*stack_a)->block)
		return (ft_sort(ft_sort_b(1, stack_a, stack_b, ft_mediana(*stack_b, block_len(*stack_b, (*stack_b)->block)), block_len(*stack_b, (*stack_b)->block)), stack_a, stack_b, mediana, len/2));
	else if ((bl_len = t_block_len(*stack_a)) == 3 && !smaller_that_m(*stack_a, mediana))
		return (ft_sort(ft_sort_3(stack_a, bl_len), stack_a, stack_b, mediana, half));
	else if ((*stack_a)->data > mediana)
		return (ft_sort(ft_ra(stack_a, half), stack_a, stack_b, mediana, half));
	else if ((*stack_a)->data < mediana)
		return (ft_sort(ft_pb(stack_a, stack_b, half), stack_a, stack_b, mediana, half));
	else if ((*stack_a)->data == mediana && !(smaller_that_m(*stack_a, mediana)))
		return (ft_sort(ft_pb(stack_a, stack_b, half), stack_a, stack_b, ft_mediana(*stack_a, ft_st_len(*stack_a)), len/2));
	else if ((*stack_a)->data == mediana && smaller_that_m(*stack_a, mediana))
		return (ft_sort(ft_ra(stack_a, half), stack_a, stack_b, mediana, half));
	return (1);
}


// make re && ./push_swap 3 2 1 4 -9 0 77 -23 44 5 33 45 -12 34 100 -100 71
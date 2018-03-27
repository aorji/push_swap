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
static int count_rr(t_stack *b, int l)
{
	while (b)
	{
		if (b->block > l)
			return(1);
		b = b->next;
	}
	return (0);
}

static int last(t_stack *stack_a)
{
	while(stack_a->next)
		stack_a = stack_a->next;
	return (stack_a->block);
}

static int	ft_sort_b(int a, t_stack **stack_a, t_stack **stack_b, int mediana, int bl)
{
	int i;
	printf("---> %s\n", "b");
	printf("med = %d\n", mediana);
	printf("bl = %d\n", bl);
	ft_pr_a(*stack_a);
	ft_pr_b(*stack_b);
	if ((*stack_b)->data > mediana)
		ft_sort_b(ft_pa(stack_a, stack_b, bl), stack_a, stack_b, mediana, bl);
	else if ((*stack_b)->data < mediana)
		ft_sort_b(ft_rb(stack_b, (*stack_b)->block), stack_a, stack_b, mediana, bl);
	else if ((*stack_b)->data == mediana && biger_that_m(*stack_b, mediana))
		ft_sort_b(ft_rb(stack_b, (*stack_b)->block), stack_a, stack_b, mediana, bl);
	else if ((*stack_b)->data == mediana && !biger_that_m(*stack_b, mediana))
	{
		ft_pa(stack_a, stack_b, bl);
		if (*stack_b)
		{
			while (count_rr(*stack_b, last(*stack_b)))
				ft_rrb(stack_b, last(*stack_b));
		}
	}
	return (1);
}

static int last_rr(int i, t_stack **stack_a, t_stack **stack_b)
{
	if (((*stack_a)->block == 0 || (*stack_a)->block == -1) && last(*stack_a) > 0)
		last_rr(ft_rra(stack_a, -1), stack_a, stack_b);
	return (1);
}

static void change_bl(t_stack **stack_a, int i)
{
	t_stack *tmp;

	tmp = *stack_a;
	while (tmp && tmp->block == -1)
	{
		tmp->block = i;
		tmp = tmp->next;
	}
}

static int char_f(t_stack *stack_a, t_stack *stack_b, bl_len)
{
	t_stack *tmp;

	tmp = stack_b;
	while (bl_len)
	{
		tmp = stack_b;
		while (tmp)
		{
			if (stack_a->data < tmp->data)
				return (0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
		bl_len--;
	}
	return (1);
}
// static int check(t_stack *stack_a, t_stack *stack_b)
// {

// }

int	ft_sort(int a, t_stack **stack_a, t_stack **stack_b, int mediana, int half)
{
	static int d = 0;
	int m;
	int m1;
	int bl;
	int k;
	int bl_len;
	int i = 0;
	a = 0;

	printf("---> %s\n", "a");
	printf("med = %d\n", mediana);
	ft_pr_a(*stack_a);
	ft_pr_b(*stack_b);
	if (!(*stack_a)->block && !ft_st_len(*stack_b))
		return (1);
	else if (!(*stack_a)->block && last(*stack_a))
	{
		last_rr(1, stack_a, stack_b);
		m1 = ft_mediana_b(*stack_a, block_len(*stack_a, (*stack_a)->block));
		ft_sort(1, stack_a, stack_b, m1, half);
	}
	else if ((*stack_a)->block == -1 && t_block_len(*stack_a) > 3)
	{
		change_bl(stack_a, t_block_len(*stack_a));
		ft_sort(1, stack_a, stack_b, mediana, half);
	}
	else if (!(*stack_a)->block && !t_block_len(*stack_a))
	{
		m = ft_mediana(*stack_b, block_len(*stack_b, (*stack_b)->block));
		ft_sort_b(1, stack_a, stack_b, m, (*stack_b)->block/2);
		m1 = ft_mediana_b(*stack_a, block_len(*stack_a, (*stack_a)->block));
		ft_sort(1, stack_a, stack_b, m1, (*stack_a)->block);
	}
	else if ((bl_len = t_block_len(*stack_a)) <= 3 && (!last(*stack_a) || !d) && char_f(*stack_a, *stack_b, bl_len))
	{
		d = 1;
		ft_sort(ft_sort_3(stack_a, bl_len), stack_a, stack_b, mediana, half);
	}
	else if ((*stack_a)->data > mediana && (*stack_a)->block)
		return (ft_sort(ft_ra(stack_a, half), stack_a, stack_b, mediana, half));
	else if ((*stack_a)->data < mediana && (*stack_a)->block)
		return (ft_sort(ft_pb(stack_a, stack_b, half), stack_a, stack_b, mediana, half));
	else if ((*stack_a)->data == mediana && !(smaller_that_m(*stack_a, mediana)) && (*stack_a)->block)
		return (ft_sort(ft_pb(stack_a, stack_b, half), stack_a, stack_b, ft_mediana_b(*stack_a, block_len(*stack_a, (*stack_a)->block)), ft_st_len(*stack_a)/2));
	else if ((*stack_a)->data == mediana && smaller_that_m(*stack_a, mediana) && (*stack_a)->block)
		return (ft_sort(ft_ra(stack_a, half), stack_a, stack_b, mediana, half));
	else if (t_block_len(*stack_a) <= 3 && (k = last(*stack_a)))
		ft_sort(ft_rra(stack_a, k), stack_a, stack_b, mediana, half);
	return (1);
}

// make re && ./push_swap 3 2 1 4 -9 0 77 -23 44 5 33 45 -12 34 100 -100 71
// make re && ./push_swap 3 2 1 4 -9 0 77 -23 44 5 33 45 -12 34 100 -100 71 17 -99 -101 || 20
// make re && ./push_swap 3 2 1 4 -9 0 77 -23 44 5 33 45 -12 34 100 -100 71 17 -99 12 10 || 21
// make re && ./push_swap 3 2 1 4 -9 0 77 -23 44 5 33 45 -12 34 100 -100 71 17 -99 12 10 81 11 -51 199 912 || 26
// make re && ./push_swap -1 3 2 1 4 -9 0 -16 77 -23 44 5 33 45 -12 34 115 -100 16 785983 -71 17 -99 12 10 81 11 -51 199 912 10239 
// len = 31
// make re && ./push_swap 2147483645 -2147483645 -1 3 2 1 4 -9 0 -16 77 -23 44 5 33 -11 513 45 -12 34 2147483646 -2147483646 115 -100 16 785983 -71 17 -99 12 10 81 11 -51 199 912 10239 -88 2147483647 -2147483647 
//len = 40


// check!!! 

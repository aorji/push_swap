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

// // static void zero_block(t_stack **stack_a)
// // {
// // 	t_stack *bl;
// // 	bl = *stack_a;

// // 	while (bl->block)
// // 	{
// // // 		bl->block = 0;
// // // 		bl = bl->next;
// // // 	}
// // // }

// static int count_bl(t_stack *b, int half)
// {
// 	int i;

// 	i = 0;
// 	while (b)
// 	{
// 		if (b->block == half)
// 			i++;
// 		b = b->next;
// 	}
// 	return (i);
// }

// // // static void ft_in_b(t_stack **stack_a, t_stack **stack_b, int mediana, int half)
// // // {
// // // 	printf("%d\n", (*stack_b)->data);
// // // 	printf("%d\n", mediana);
// // // 	if ((*stack_b)->block == half)
// // // 	{
// // // 		if ((*stack_b)->data > mediana)
// // // 		{
// // // 			ft_pa(stack_a, stack_b, half / 2);
// // // 			ft_in_b(stack_a, stack_b, mediana, half);
// // // 		}
// // // 		if ((*stack_b)->data <mediana)
// // // 		{
// // // 			ft_rb(stack_b);
// // // 			ft_in_b(stack_a, stack_b, mediana, half);
// // // 		}
// // // 		if ((*stack_b)->data == mediana)
// // // 		{
// // // 			ft_pr_a(*stack_a);
// // // 			ft_pr_b(*stack_b);
// // // 		}
// // // 	}
// // // 	else
// // // 	{
// // // 		ft_pr_a(*stack_a);
// // // 		ft_pr_b(*stack_b);
// // // 	}
// // // }

// // static void un_ra(t_stack **stack_a, int i)
// // {
// // 	while (i)
// // 	{
// // 		ft_rra(stack_a);
// // 		i--;
// // 	}
// // }

// // static void ft_sort_a(t_stack **stack_a, t_stack **stack_b, int half, int i, int mediana)
// // {
// // 	int cb;

// // 	cb = count_bl(*stack_b, half);
// // 	if (cb <= 3)
// // 	{
// // 		if (i)
// // 		{
// // 			un_ra(stack_a, i);
// // 			ft_sort_a(stack_a, stack_b, half, 0, mediana);
// // 		}
// // 		ft_sort_3(stack_a, cb);
// // 		zero_block(stack_a);
// // 	}
// // 	if (cb > 3 && (*stack_a)->block)
// // 	{
// // 		if ((*stack_a)->data >= mediana)
// // 		{
// // 			ft_ra(stack_a);
// // 			i++;
// // 		}
// // 		else if ((*stack_a)->data < mediana)
// // 			ft_pb(stack_a, stack_b, half);
// // 		ft_sort_a(stack_a, stack_b, half, i, mediana);
// // 	}

// // }

// static int	ft_sort_b(t_stack **stack_a, t_stack **stack_b, int half)
// {
// 	int cb;
// 	int s;

// 	cb = count_bl(*stack_b, half);
// 	// if ((cb = count_bl(*stack_b, half)) > 3)
// 	// {
// 	// 	printf("%s\n", "exit");
// 	// 	return (1);
// 	// }
// 	// s = cb;	
// 	// if (!cb && !ft_st_len(*stack_b))
// 	// 	return (1);
// 	// if (!cb)
// 	// {
// 	// 	printf("%d\n", half);
// 	// 	ft_sort_b(stack_a, stack_b, ++half);
// 	// }
// 	printf("1\n");
// 	if (cb > 3)
// 	{
// 		return (1);
// 	}
// 	printf("2\n");
// 	if (cb <= 3)
// 	{
// 		printf("3\n");
// 		while (s)
// 		{
// 			ft_pa(stack_a, stack_b, half);
// 			s--;
// 		}
// 		ft_sort_3(stack_a, cb);
// 		ft_sort_b(stack_a, stack_b, ++half);
// 	}
// 	return (1);
// 	// 	while (cb > 3)
// 	// 	{
// 	// 		mediana = ft_mediana(*stack_b, ft_st_len(*stack_b));
// 	// 		if ((*stack_b)->data > mediana)
// 	// 			ft_pa(stack_a, stack_b, half / 2);
// 	// 		if ((*stack_b)->data <= mediana)
// 	// 		{
// 	// 			ft_rb(stack_b);
// 	// 			j++;
// 	// 		}
// 	// 		cb--;
// 	// 		i++;
// 	// 	}
// 	// 	ft_sort_a(t_stack **stack_a, t_stack **stack_b, int half, 0);
// 	// 	// ft_sort_3(stack_a, i);
// 	// 	// zero_block(stack_a);
// 	// 	while (j--)
// 	// 		ft_rrb(stack_b);
// 	// 	// ft_pr_a(*stack_a);
// 	// 	// ft_pr_b(*stack_b);
// 	// 	// ft_sort_b(stack_a, stack_b, half);
// 	// }
// }

static int smallest(t_stack *st, int i)
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (i > s->data)
			return (0);
		s = s->next;
	}
	return (1);
}

int	ft_sort(t_stack **stack_a, t_stack **stack_b, int mediana, int half)
{
	int len;

	len = ft_st_len(*stack_a);
	if (!(*stack_a)->block)
		return (1);
	if (len > 3 && (*stack_a)->block)
	{
		if ((*stack_a)->data >= mediana)
		{
			if ((*stack_a)->data == mediana)
			{
				if (smallest(*stack_a, mediana))
				{
					mediana = ft_mediana(*stack_a, len);
					half = ft_st_len(*stack_a) / 2;
				}
			}
			ft_ra(stack_a);
		}
		else if ((*stack_a)->data < mediana)
		{
			ft_pb(stack_a, stack_b, half);
		}
		ft_sort(stack_a, stack_b, mediana, half);
	}
	else if (len <= 3 && (*stack_a)->block)
	{
		ft_sort_3(stack_a, len);
		ft_sort(stack_a, stack_b, mediana, half);
	}
	return (1);
}

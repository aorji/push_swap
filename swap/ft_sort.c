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

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int mediana)
{
	int len;
	t_stack *bl;

	len = ft_st_len(stack_a);
	if (len > 3 && stack_a->block)
	{
		if (stack_a->data >= mediana)
		{
			ft_ra(&stack_a);
			ft_printf("%s\n", "ra");
			if (stack_a->data == mediana)
				mediana = ft_mediana(stack_a, len);
		}
		else if (stack_a->data < mediana)
		{
			ft_pb(&stack_a, &stack_b);
			ft_printf("%s\n", "pb");
		}
		ft_sort(stack_a, stack_b, mediana);
	}
	else if (len <= 3 && stack_a->block)
	{
		ft_sort_3(&stack_a, len);
		bl = stack_a;
		while (bl)
		{
			bl->block = 0;
			bl = bl->next;
		}
		ft_sort(stack_a, stack_b, mediana);
	}
	else if (!stack_a->block)
	{
		ft_pr_a(stack_a);
		ft_pr_b(stack_b);
	}
	return ;
	//make re && ./push_swap -29 61 538 1 2 3 0 5 -1 76 39 30 -40 -100 55 88 -77 33 -51 -123
}

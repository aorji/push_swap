/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:13:11 by aorji             #+#    #+#             */
/*   Updated: 2018/04/03 17:13:15 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_pr_a(t_stack *stack_a)
{
	ft_printf("%s\n", "stack_a =");
	while (stack_a)
	{
		ft_printf("a = %d		bl = %d\n", stack_a->data, stack_a->block);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
}

void ft_pr_b(t_stack *stack_a)
{
	ft_printf("%s\n", "stack_b =");
	while (stack_a)
	{
		ft_printf("b = %d		bl = %d\n", stack_a->data, stack_a->block);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
}
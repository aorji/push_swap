/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_modif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:17:54 by aorji             #+#    #+#             */
/*   Updated: 2018/04/03 20:18:12 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last(t_stack *stack_a)
{
	while (stack_a->next)
		stack_a = stack_a->next;
	return (stack_a->block);
}

int	zero_block(t_stack **stack_a)
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

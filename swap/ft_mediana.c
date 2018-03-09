/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediana.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:06:57 by aorji             #+#    #+#             */
/*   Updated: 2018/03/09 19:06:59 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mediana(t_stack *stack_a, int len)
{
	int i;
	stack_a = sort_list(stack_a, len);
	len /= 2;
	while (len)
	{
		stack_a = stack_a->next;
		len--;
	}
	i = stack_a->data;
	printf("med = %d\n", i);
	return (i);
}
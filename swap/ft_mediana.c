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
	t_stack *new;
	t_stack *med;

	med = stack_a;
	while(med)
	{
		i = 0;
		new = stack_a;
		while (new)
		{
			if (new->data > med->data)
				i++;
			new = new->next;
		}
		if (i == len/2)
			return (med->data);
		med = med->next;
	}
	return (ft_printf("ERROR: your mediana is a BULL SHIT"));
}
int	ft_mediana_b(t_stack *stack_a, int len)
{
	int i;
	t_stack *new;
	t_stack *med;

	med = stack_a;
	if (!med->block)
		return(0);
	while(med && med->block)
	{
		i = 0;
		new = stack_a;
		while (new && new->block)
		{
			if (new->data > med->data)
				i++;
			new = new->next;
		}
		if (i == len/2)
			return (med->data);
		med = med->next;
	}
	return (ft_printf("ERROR: your mediana_b is a BULL SHIT"));
}

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
		else
			return (i);
		s = s->next;
	}
	return (i);
}

int	ft_mediana(t_stack *stack_a, int len)
{
	int i;
	t_stack *new;
	t_stack *med;

	med = stack_a;
	if (!med->block)
		return(0);
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
	ft_printf("ERROR: your mediana_b is a BULL SHIT");
	exit(1);
}
int	ft_mediana_b(t_stack *stack_a, int len)
{
	int i;
	t_stack *new;
	t_stack *med;	

  	// printf("len = %d\n", len);
	med = stack_a;
	if (!med->block)
		return(0);
	if (block_len(stack_a, stack_a->block) == 1)
		return (stack_a->data);
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
	ft_printf("ERROR: your mediana_b is a BULL SHIT");
	exit(1);
}

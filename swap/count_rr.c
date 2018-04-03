/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:17:05 by aorji             #+#    #+#             */
/*   Updated: 2018/04/03 20:17:08 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rr(t_stack *b, int l)
{
	if (l == 0)
		return (0);
	while (b)
	{
		if (b->block > l)
			return (1);
		b = b->next;
	}
	return (0);
}

int	count_rr_zero(t_stack *a, int l)
{
	int	i;

	i = 0;
	if (!l)
		return (0);
	while (a)
	{
		if (a->block == 0)
			return (1);
		a = a->next;
	}
	return (0);
}

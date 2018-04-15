/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:39:26 by aorji             #+#    #+#             */
/*   Updated: 2018/04/03 18:39:28 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smaller(t_stack *st, int med)
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->data < med)
			return (1);
		s = s->next;
	}
	return (0);
}

int	sm_eq_m(t_stack *st, int med)
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->data <= med)
			return (1);
		s = s->next;
	}
	return (0);
}

int	eq(t_stack *st, int med)
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->data == med)
			return (1);
		s = s->next;
	}
	return (0);
}

int	bg_eq_m(t_stack *st, int med)
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->data >= med)
			return (1);
		s = s->next;
	}
	return (0);
}

int	biger_that_m(t_stack *st, int med)
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->data > med)
			return (1);
		s = s->next;
	}
	return (0);
}

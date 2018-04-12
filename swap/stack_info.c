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

int ft_flag(char *str)
{
	if (!ft_strcmp(str, "-v") || !ft_strcmp(str, "-p") || !ft_strcmp(str, "-c") || !ft_strcmp(str, "-o"))
		return (1);
	return (0);
}

int	smaller_that_m(t_stack *st, int med)
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

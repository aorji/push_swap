/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:56:50 by aorji             #+#    #+#             */
/*   Updated: 2018/03/06 20:56:52 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_st_len(t_stack *st)
{
	int i;
	
	i = 0;
	while (st)
	{
		i++;
		st = st->next;
	}
	return (i);
}

int ft_st_len_true(t_stack *st)
{
	int i;
	
	i = 0;
	while (st)
	{
		if (st->data)
			i++;
		st = st->next;
	}
	return (i);
}

int		ft_count_param(char **param)
{
	int i;

	i = 0;
	while (*param)
	{
		i++;
		param++;
	}
	return (i);
}

// int block_len(t_stack *st, int h)
// {
// 	int i;
// 	i = 0;
// 	t_stack *s;

// 	s = st;
// 	while (s)
// 	{
// 		if (s->block == h)
// 			i++;
// 		s = s->next;
// 	}
// 	return (i);
// }

// int t_block_len(t_stack *st)
// {
// 	int i;
// 	i = 0;
// 	t_stack *s;

// 	s = st;
// 	while (s)
// 	{
// 		if (s->block)
// 			i++;
// 		s = s->next;
// 	}
// 	return (i);
// }

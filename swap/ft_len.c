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
		st =st->next;
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
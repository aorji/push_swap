/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:42:54 by aorji             #+#    #+#             */
/*   Updated: 2018/04/15 13:42:56 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fr(t_res *t1, t_res *t2)
{
	free(t1->move);
	free(t2->move);
	free(t2);
	free(t1);
}

int		f(t_stack **a, t_stack **b, int argc, char ***p)
{
	t_stack	*t;
	char	**param;

	free(*b);
	param = *p;
	while (*a)
	{
		t = *a;
		*a = (*a)->next;
		free(t);
	}
	if (argc == 2)
	{
		while (*param)
		{
			ft_strdel(param);
			param++;
		}
	}
	return (1);
}

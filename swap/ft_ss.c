/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:14:32 by aorji             #+#    #+#             */
/*   Updated: 2018/03/06 18:14:34 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a)
{
	int c;

	if (ft_st_len(*a) < 2)
		return;
	c = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = c;
	g_count_moves++;
	ft_printf("%s\n", "sa");
}

void	ft_sb(t_stack **a)
{
	int c;

	if (ft_st_len(*a) < 2)
		return;
	c = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = c;
	g_count_moves++;
	ft_printf("%s\n", "sa");
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
}

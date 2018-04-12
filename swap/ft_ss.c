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

void	ft_sa(t_stack **a, t_res **r)
{
	int c;

	if (ft_st_len(*a) < 2)
		return ;
	c = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = c;
	r && ((*r)->v) ? debug(*a, NULL, "sa") : 0;
	r ? res_str(r, "sa") : 0;
}

void	ft_sb(t_stack **a, t_res **r)
{
	int c;

	if (ft_st_len(*a) < 2)
		return ;
	c = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = c;
	r && ((*r)->v) ? debug(NULL, *a, "sb") : 0;
	r ? res_str(r, "sb") : 0;
}

void	ft_ss(t_stack **a, t_stack **b)
{
	int c;

	if (ft_st_len(*a) < 2 && ft_st_len(*b) < 2)
		return ;
	if (ft_st_len(*a) >= 2)
	{
		c = (*a)->data;
		(*a)->data = (*a)->next->data;
		(*a)->next->data = c;
	}
	if (ft_st_len(*b) >= 2)
	{
		c = (*b)->data;
		(*b)->data = (*b)->next->data;
		(*b)->next->data = c;
	}
}

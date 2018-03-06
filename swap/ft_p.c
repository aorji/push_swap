/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:15:03 by aorji             #+#    #+#             */
/*   Updated: 2018/03/06 18:15:04 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **a, t_stack **b)
{
	char **p;
	t_stack *head;

	if (ft_st_len(*b) < 1)
		return ;
	p = (char **)malloc(sizeof(char *) * 2);
	p[0] = (char *)malloc(sizeof(char) * 2);
	p[1] = NULL;
	p[0][0] = (*b)->data + 48;
	p[0][1] = '\0';
	head = ft_make_stack(p, 1);
	head->next = (*a);
	*b = (*b)->next;
	*a = head;
}

void	ft_pb(t_stack **b, t_stack **a)
{
	char **p;
	t_stack *head;

	if (ft_st_len(*a) < 1)
		return ;
	p = (char **)malloc(sizeof(char *) * 2);
	p[0] = (char *)malloc(sizeof(char) * 2);
	p[1] = NULL;
	p[0][0] = (*a)->data + 48;
	p[0][1] = '\0';
	head = ft_make_stack(p, 1);
	head->next = (*b);
	*a = (*a)->next;
	*b = head;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:00:34 by aorji             #+#    #+#             */
/*   Updated: 2018/01/31 15:03:19 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int cmp(int a, int b)
{
	return (a <= b);
}

t_stack	*sort_list(t_stack *lst, int i)
{
	t_stack	*head;
	t_stack	*nlst;
	int a;
	int j;
	int k;

	head = lst;
	j = 0;
	k = 0;
	while (k < i)
	{
		lst = head;
		while (j < i - 1)
		{
			nlst = lst->next;
			if (!cmp(lst->data, nlst->data))
			{
				a = lst->data;
				lst->data = nlst->data;
				nlst->data = a;
			}
			lst = lst->next;
			j++;
		}
		k++;
		j = 0;
	}
	return (head);
}

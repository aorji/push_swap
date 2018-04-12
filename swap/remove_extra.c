/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:39:21 by aorji             #+#    #+#             */
/*   Updated: 2018/04/12 16:39:25 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	r_len(t_res *st)
{
	int	i;

	i = 0;
	while (st)
	{
		i++;
		st = st->next;
	}
	return (i);
}

static void remove_if_two(int len, t_res **h, const char *s1, const char *s2)
{
	int i;
	t_res *a;
	t_res *t1;
	t_res *t2;

	i = 0;
	while (*h && (*h)->next && !ft_strcmp((*h)->move, s1) && !ft_strcmp((*h)->next->move, s2))
	{
		t1 = (*h);
		t2 = (*h)->next;
		(*h) = (*h)->next->next;
		free(t1->move);
		free(t2->move);
		free(t2);
		free(t1);
	}
	while (i < len)
	{
		a = (*h);
		while (a && a->next && a->next->next)
		{
			if (!ft_strcmp(a->next->move, s1) && !ft_strcmp(a->next->next->move, s2))
			{
				t1 = a->next;
				t2 = a->next->next;
				a->next = a->next->next->next;
				free(t1->move);
				free(t2->move);
				free(t2);
				free(t1);
			}
			else
				a = a->next;
		}
		i++;
	}
}

static void remove_if_one(t_res **h, const char *s1, const char *s2, const char *s3)
{
	int i;
	int len;
	t_res *t1;
	t_res *a;
	char *t2;
	i = 0;
	len = r_len(*h);
	while (i < len)
	{
		a = (*h);
		while (a && a->next)
		{
			if (!ft_strcmp(a->move, s1) && !ft_strcmp(a->next->move, s2))
			{
				t1 = a->next;
				t2 = a->move;
				a->move = ft_strcpy(a->move, s3);
				a->next = a->next->next;
				free(t2);
				free(t1->move);
				free(t1);
			}
			a = a->next;
		}
		i++;
	}
}

void	clean_move(t_res **h)
{
	int len;

	len = r_len(*h);
	remove_if_two(len, h, "rra", "ra");
	remove_if_two(len, h, "ra", "rra");
	remove_if_two(len, h, "rrb", "rb");
	remove_if_two(len, h, "rb", "rrb");
	remove_if_one(h, "ra", "rb", "rr");
	remove_if_one(h, "rra", "rrb", "rrr");
	remove_if_one(h, "sa", "sb", "ss");
	remove_if_one(h, "rb", "ra", "rr");
	remove_if_one(h, "rrb", "rra", "rrr");
	remove_if_one(h, "sb", "sa", "ss");
	
}

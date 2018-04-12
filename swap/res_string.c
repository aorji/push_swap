/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:16:36 by aorji             #+#    #+#             */
/*   Updated: 2018/04/04 16:16:39 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_res*	r_new(void)
{
	t_res *r;

	r = (t_res *)malloc(sizeof(t_res));
	r->move = (char*)malloc(sizeof(char) * 4);
	r->next = NULL;
	return (r);
}

void	res_str(t_res **r, const char *s)
{
	if (ft_strlen((*r)->move))
	{
		(*r)->next = r_new();
		(*r)->next->v = (*r)->v;
		(*r) = (*r)->next;
	}
	(*r)->move = ft_strcpy((*r)->move, s);
}

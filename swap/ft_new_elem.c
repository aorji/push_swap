/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:57:48 by aorji             #+#    #+#             */
/*   Updated: 2018/03/06 20:57:49 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(void)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	new->next = NULL;
	return (new);
}

t_stack	*ft_make_stack(char **param, int len)
{
	int i;
	t_stack *new;
	t_stack *head;

	if (len == 0)
		return (NULL);
	i = 0;	
	new = ft_stack_new();
	head = new;
	while (i < len)
	{
		new->data = ft_atoi(param[i]);
		if (i + 1 < len)
			new->next = ft_stack_new();
		new = new->next;
		i++;
	}
	return (head);
}
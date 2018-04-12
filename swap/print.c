/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:13:11 by aorji             #+#    #+#             */
/*   Updated: 2018/04/03 17:13:15 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pr_a(t_stack *stack_a)
{
	ft_printf("%s\n", "stack_a =");
	while (stack_a)
	{
		ft_printf("a = %d		bl = %d\n", stack_a->data, stack_a->block);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
}

void	ft_pr_b(t_stack *stack_a)
{
	ft_printf("%s\n", "stack_b =");
	while (stack_a)
	{
		ft_printf("b = %d		bl = %d\n", stack_a->data, stack_a->block);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
}

void	ft_print_res(t_res **h, t_flag f, int len)
{
	t_res	*tmp;
	t_res	*header;
	int		i;

	i = 0;
	header = *h;
	while (header)
	{
		i++;
		if (f.c && !header->next)
			ft_printf("%1b%s%b\n", header->move);
		else
			ft_printf("%s\n", header->move);
		tmp = header;
		header = header->next;
		free(tmp->move);
		free(tmp);
	}
	if (f.o)
		ft_printf("used %d  operations\n", i);
	if (f.p)
		ft_printf("sorted %d  parameters\n", len);
	free(header);
}

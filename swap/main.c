/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:35:33 by aorji             #+#    #+#             */
/*   Updated: 2018/03/06 16:35:36 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	check(t_stack *stack_a)
{
	int a;

	if (stack_a)
		a = stack_a->data;
	while (stack_a && stack_a->next)
	{
		if (stack_a->next->data < a)
			return (0);
		a = stack_a->next->data;
		stack_a = stack_a->next;
	}
	return (1);
}

void		ft_push(char **param)
{
	int		len;
	int		mediana;
	t_stack *stack_a;
	t_stack *stack_b;

	len = ft_count_param(param);
	stack_a = ft_make_stack(param, len);
	if (check(stack_a))
		return ;
	stack_b = NULL;
	mediana = ft_mediana(stack_a, ft_st_len(stack_a));
	ft_sort(&stack_a, &stack_b, mediana, len / 2);
	free(stack_a);
	free(stack_b);
}

int			main(int argc, char **argv)
{
	char **param;

	if (argc < 2)
		return (0);
	if (argc == 2)
		param = ft_strsplit(argv[1], ' ');
	if (argc > 2)
		param = ++argv;
	ft_push(param);
	if (argc == 2)
	{
		while (*param)
		{
			ft_strdel(param);
			param++;
		}
	}
	// system("leaks push_swap");
	return (0);
}

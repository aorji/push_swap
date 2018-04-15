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

static	int		check(t_stack *stack_a)
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

void			ft_push(char **param, t_flag f, int len)
{
	t_res	*r;
	t_res	*header;
	t_stack *tmp;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = ft_make_stack(param, len);
	if (check(stack_a))
		return ;
	stack_b = NULL;
	r = r_new(f.v);
	header = r;
	ft_sort(&stack_a, &stack_b, len / 2, &r);
	clean_move(&header);
	ft_print_res(&header, f, len);
	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
	free(stack_b);
}

int				main(int argc, char **argv)
{
	char	**param;
	t_flag	flags;

	flags = (t_flag){0};
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		param = ft_strsplit(argv[1], ' ');
		flags = check_flags(&param, flags);
	}
	if (argc > 2)
	{
		param = ++argv;
		flags = check_flags(&param, flags);
	}
	ft_push(param, flags, ft_count_param(param));
	while (argc == 2 && *param)
	{
		ft_strdel(param);
		param++;
	}
	return (0);
}

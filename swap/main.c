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

static t_flag check_flags(char ***param, t_flag f)
{
	char **p;
	int i;

	p = *param;
	i = 0;
	while (p[i])
	{
		if (!ft_strcmp(p[i], "-v"))
			f.v = 1;
		if (!ft_strcmp(p[i], "-o"))
			f.o = 1;
		if (!ft_strcmp(p[i], "-c"))
			f.c = 1;
		if (!ft_strcmp(p[i], "-p"))
			f.p = 1;
		i++;
	}
	return (f);
}

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

void		ft_push(char **param, t_flag f)
{
	int		len;
	int 	i;
	t_res	*r;
	t_res	*header;
	t_res	*tmp;
	t_stack *t;
	t_stack *stack_a;
	t_stack *stack_b;

	i = 0;
	len = ft_count_param(param);
	stack_a = ft_make_stack(param, len);
	if (check(stack_a))
		return ;
	stack_b = NULL;
	r = r_new();
	r->v = f.v;
	header = r;
	ft_sort(&stack_a, &stack_b, len / 2, &r);
	clean_move(&header);
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
	while (stack_a)
	{
		t = stack_a;
		stack_a = stack_a->next;
		free(t);
	}
	free(stack_b);
	free(header);
}

int			main(int argc, char **argv)
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
	ft_push(param, flags);
	if (argc == 2)
	{
		while (*param)
		{
			ft_strdel(param);
			param++;
		}
	}
	//system("leaks push_swap");
	return (0);
}

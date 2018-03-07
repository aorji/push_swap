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

void	ft_push(char **param)
{
	int i;
	int len;
	t_stack *stack_a;
	t_stack *stack_b;

	i = ft_count_param(param);
	len = i;
	stack_a = ft_make_stack(param, len);
	stack_b = NULL;
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_rrb(&stack_b);
	while (stack_a)
	{
		printf("a = %d\n", stack_a->data);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("b = %d\n", stack_b->data);
		stack_b = stack_b->next;
	}
}

int main(int argc, char **argv)
{
	char **param;

	if (argc < 2)
		return (0);
	if (argc == 2)
		param = ft_strsplit(argv[1], ' ');
	if (argc > 2)
		param = ++argv;
	ft_push(param);
	return 0;
}
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

void ft_pr_a(t_stack *stack_a)
{
	ft_printf("%s\n", "stack_a =");
	while (stack_a)
	{
		printf("a = %d		bl = %d\n", stack_a->data, stack_a->block);
		stack_a = stack_a->next;
	}
	printf("\n");
}

void ft_pr_b(t_stack *stack_a)
{
	ft_printf("%s\n", "stack_b =");
	while (stack_a)
	{
		printf("b = %d		bl = %d\n", stack_a->data, stack_a->block);
		stack_a = stack_a->next;
	}
	printf("\n");
}

void	ft_push(char **param)
{
	int len;
	int	mediana;
	t_stack *stack_a;
	t_stack *stack_b;

	len = ft_count_param(param);
	stack_a = ft_make_stack(param, len);
	stack_b = NULL;
	mediana = ft_mediana(stack_a, ft_st_len(stack_a));
	//printf("%d\n", mediana);
	// printf("med = %d\n", mediana);
	ft_sort(&stack_a, &stack_b, mediana, len/2);
	ft_pr_a(stack_a);
	ft_pr_b(stack_b);
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
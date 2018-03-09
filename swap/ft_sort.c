/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:16:11 by aorji             #+#    #+#             */
/*   Updated: 2018/03/09 20:16:13 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int mediana, int len)
{
	//ft_pr_a(stack_a);
	if (ft_st_len(stack_a) > 3)
	{
		if (stack_a->data > mediana)
		{
			ft_ra(&stack_a);
			ft_printf("%s\n", "ra");
			ft_sort(stack_a, stack_b, mediana, len);
		}
		if (stack_a->data < mediana)
		{
			ft_pb(&stack_a, &stack_b);
			ft_printf("%s\n", "pb");
			ft_sort(stack_a, stack_b, mediana, len);
		}

	}
	else{

		//ft_sort_3(stack_a, len);
		ft_pr_a(stack_a);
		ft_pr_b(stack_b);
	}
	
}
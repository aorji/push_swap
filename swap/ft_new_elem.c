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

static void	ft_er1(int n, int n1, char *str)
{
	while (n > 9)
		n /= 10;
	if (n != *str - 48 || (int)ft_strlen(str) != ft_digitsize(n1))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

static void	ft_er2(long n, long n1, char *str)
{
	n = -n;
	while (n > 9)
		n /= 10;
	if (n != *(str + 1) - 48 || (int)ft_strlen(str) != ft_digitsize(n1))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

static void	ft_error(char *str, t_stack *stack)
{
	long	n;
	long	n1;
	int		len;

	n = ft_atoi(str);
	n1 = n;
	if (n >= 0)
		ft_er1(n, n1, str);
	if (n < 0)
		ft_er2(n, n1, str);
	len = ft_st_len(stack);
	while (len - 1)
	{
		if (stack->data == n1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		stack = stack->next;
		len--;
	}
}

t_stack		*ft_stack_new(int h)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	new->block = h;
	new->next = NULL;
	return (new);
}

t_stack		*ft_make_stack(char **param, int len)
{
	int		i;
	t_stack	*new;
	t_stack	*head;

	if (len == 0)
		return (NULL);
	i = 0;
	new = ft_stack_new(len / 2);
	head = new;
	while (i < len)
	{
		ft_error(param[i], head);
		new->data = ft_atoi(param[i]);
		new->block = len / 2;
		if (i + 1 < len)
		{
			new->next = ft_stack_new(len / 2);
			new = new->next;
		}
		i++;
	}
	return (head);
}

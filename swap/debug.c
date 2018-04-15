/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:38:54 by aorji             #+#    #+#             */
/*   Updated: 2018/04/12 16:38:57 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug(t_stack *a, t_stack *b, const char *s)
{
	ft_printf("after \"%s\":\n", s);
	if (a)
		ft_pr_a(a);
	if (b)
		ft_pr_b(b);
}

t_flag	check_flags(char ***param, t_flag f)
{
	char	**p;
	int		i;

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

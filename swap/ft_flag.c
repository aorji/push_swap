/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:17:05 by aorji             #+#    #+#             */
/*   Updated: 2018/04/12 19:17:39 by aorji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_flag(char *str)
{
	if (!ft_strcmp(str, "-v") || !ft_strcmp(str, "-p") ||
		!ft_strcmp(str, "-c") || !ft_strcmp(str, "-o"))
		return (1);
	return (0);
}

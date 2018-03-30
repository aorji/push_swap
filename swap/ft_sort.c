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

static int smaller_that_m(t_stack *st, int med) // ест что-то меньше, чем медиана -> 1;
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->data < med)
			return(1);
		s = s->next;
	}
	return (0);
}

static int sm_eq_m(t_stack *st, int med) // ест что-то меньше, чем медиана -> 1;
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->data <= med)
			return(1);
		s = s->next;
	}
	return (0);
}

static int eq(t_stack *st, int med) // ест что-то меньше, чем медиана -> 1;
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->data == med)
			return(1);
		s = s->next;
	}
	return (0);
}

static int bg_eq_m(t_stack *st, int med) // ест что-то меньше, чем медиана -> 1;
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->data >= med)
			return(1);
		s = s->next;
	}
	return (0);
}

static int biger_that_m(t_stack *st, int med) // ест что-то больше, чем медиана -> 1;
{
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->data > med)
			return(1);
		s = s->next;
	}
	return (0);
}

static int block_len(t_stack *st, int h)
{
	int i;
	i = 0;
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->block == h)
			i++;
		s = s->next;
	}
	return (i);
}

static int t_block_len(t_stack *st)
{
	int i;
	i = 0;
	t_stack *s;

	s = st;
	while (s)
	{
		if (s->block)
			i++;
		s = s->next;
	}
	return (i);
}

static int count_rr(t_stack *b, int l)
{
	if (l == 0)
		return (0);
	while (b)
	{
		if (b->block > l)
			return(1);
		b = b->next;
	}
	return (0);
}

static int count_rr_zero(t_stack *a, int l)
{
	int i;

	i = 0;
	if (!l)
		return (0);
	while (a)
	{
		if (a->block == 0)
			return (1);
		a = a->next;
	}
	return (0);
}

static int last(t_stack *stack_a)
{
	while(stack_a->next)
		stack_a = stack_a->next;
	return (stack_a->block);
}

static int last_rr(int i, t_stack **stack_a, t_stack **stack_b)
{
	if (((*stack_a)->block == 0 || (*stack_a)->block == -1) && last(*stack_a) > 0)
		last_rr(ft_rra(stack_a, -1), stack_a, stack_b);
	return (1);
}

static void change_bl(t_stack **stack_a, int i)
{
	t_stack *tmp;

	tmp = *stack_a;
	while (tmp && tmp->block == -1)
	{
		tmp->block = i;
		tmp = tmp->next;
	}
}

static int char_f(t_stack *stack_a, t_stack *stack_b, int bl_len)
{
	t_stack *tmp;

	tmp = stack_b;
	while (bl_len)
	{
		tmp = stack_b;
		while (tmp)
		{
			if (stack_a->data < tmp->data)
				return (0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
		bl_len--;
	}
	return (1);
}

static int	ft_sort_b(int a, t_stack **stack_a, t_stack **stack_b, int mediana, int bl)
{
	int i;
	// printf("---> %s\n", "b");
	// printf("med = %d\n", mediana);
	// printf("bl = %d\n", bl);
	// ft_pr_a(*stack_a);
	// ft_pr_b(*stack_b);
	if (!bg_eq_m(*stack_b, mediana))
		return (1);
	if ((*stack_b)->data > mediana)
	{
		ft_pa(stack_a, stack_b, bl);
		if (!bg_eq_m(*stack_b, mediana))
		{
			if (*stack_b)
			{
				while (count_rr(*stack_b, last(*stack_b)))
					ft_rrb(stack_b, last(*stack_b));
			}
		}
		ft_sort_b(1, stack_a, stack_b, mediana, bl);
	}
	else if ((*stack_b)->data < mediana)
		ft_sort_b(ft_rb(stack_b, (*stack_b)->block), stack_a, stack_b, mediana, bl);
	else if ((*stack_b)->data == mediana && biger_that_m(*stack_b, mediana))
	{
		ft_pa(stack_a, stack_b, bl);
		ft_sort_b(1, stack_a, stack_b, mediana, bl);
	}
	else if ((*stack_b)->data == mediana && !biger_that_m(*stack_b, mediana))
	{
		ft_pa(stack_a, stack_b, bl);
		if (*stack_b)
		{
			while (count_rr(*stack_b, last(*stack_b)))
				ft_rrb(stack_b, last(*stack_b));
		}
	}
	return (1);
}

int	ft_sort(int a, t_stack **stack_a, t_stack **stack_b, int mediana, int half)
{
	static int d = 0;
	int m;
	int m1;
	int bl;
	int k;
	int bl_len;
	int i = 0;
	a = 0;

	// printf("---> %s\n", "a");
	// printf("med = %d\n", mediana);
	// printf("block = %d\n", half);
	// printf("in a %d elem\n", t_block_len(*stack_a));
	// printf("in b %d elem\n", t_block_len(*stack_b));
	// ft_pr_a(*stack_a);
	// ft_pr_b(*stack_b);
	// printf("g_count_moves = %d\n", g_count_moves);
	if (!(*stack_a)->block && !ft_st_len(*stack_b))
		return (1);
	else if (!t_block_len(*stack_a))
	{
		m = ft_mediana(*stack_b, block_len(*stack_b, (*stack_b)->block));
		ft_sort_b(1, stack_a, stack_b, ft_mediana(*stack_b, block_len(*stack_b, (*stack_b)->block)), (*stack_b)->block/2);
		m1 = ft_mediana_b(*stack_a, block_len(*stack_a, (*stack_a)->block));
		ft_sort(1, stack_a, stack_b, m1, (*stack_a)->block);
	}

	else if ((bl_len = t_block_len(*stack_a)) <= 3 && ((smaller_that_m(*stack_a, mediana) && eq(*stack_a, mediana)) || (!smaller_that_m(*stack_a, mediana))))
	{
		while (count_rr_zero(*stack_a, last(*stack_a)))
				ft_rra(stack_a, last(*stack_a));
		ft_sort(ft_sort_3(stack_a, bl_len), stack_a, stack_b, mediana, half);
	}
	else if ((*stack_a)->data > mediana && (*stack_a)->block)
		return (ft_sort(ft_ra(stack_a, half), stack_a, stack_b, mediana, half));
	else if ((*stack_a)->data < mediana && (*stack_a)->block)
	{
		ft_pb(stack_a, stack_b, half);
		if (!sm_eq_m(*stack_a, mediana))
		{
			while (count_rr_zero(*stack_a, last(*stack_a)))
				ft_rra(stack_a, last(*stack_a));
			return (ft_sort(1, stack_a, stack_b, ft_mediana_b(*stack_a, t_block_len(*stack_a)), ft_st_len_true(*stack_a)/2));
		}
		return (ft_sort(1, stack_a, stack_b, mediana, half));
	}
	else if ((*stack_a)->data == mediana && !(smaller_that_m(*stack_a, mediana)) && (*stack_a)->block)
	{
		ft_pb(stack_a, stack_b, half);
		while (count_rr_zero(*stack_a, last(*stack_a)))
				ft_rra(stack_a, last(*stack_a));
		return (ft_sort(1, stack_a, stack_b, ft_mediana_b(*stack_a, t_block_len(*stack_a)), ft_st_len_true(*stack_a)/2));
	}
	else if ((*stack_a)->data == mediana && smaller_that_m(*stack_a, mediana) && (*stack_a)->block)
	{
		ft_pb(stack_a, stack_b, half);
		return (ft_sort(1, stack_a, stack_b, mediana, half));
	}
	return (1);
}

// make re && ./push_swap 3 2 1 4 -9 0 77 -23 44 5 33 45 -12 34 100 -100 71
// make re && ./push_swap 3 2 1 4 -9 0 77 -23 44 5 33 45 -12 34 100 -100 71 17 -99 -101 || 20
// make re && ./push_swap 3 2 1 4 -9 0 77 -23 44 5 33 45 -12 34 100 -100 71 17 -99 12 10 || 21
// make re && ./push_swap 3 2 1 4 -9 0 77 -23 44 5 33 45 -12 34 100 -100 71 17 -99 12 10 81 11 -51 199 912 || 26
// make re && ./push_swap -1 3 2 1 4 -9 0 -16 77 -23 44 5 33 45 -12 34 115 -100 16 785983 -71 17 -99 12 10 81 11 -51 199 912 10239 
// make re && ./push_swap 2147483645 -2147483645 -1 3 2 1 4 -9 0 -16 77 -23 44 5 33 -11 513 45 -12 34 2147483646 -2147483646 115 -100 16 785983 -71 17 -99 12 10 81 11 -51 199 912 10239 -88 2147483647 -2147483647 
// make re && ./push_swap 2147483645 -65302 -2147483645 -1 3 2 1 4 -9 0 -16 77 -23 44 5 33 -11 513 45 -12 34 2147483646 -2147483646 115 -100 16 785983 -71 17 -99 12 10 81 11 -51 199 912 10239 -88 2147483647 -2147483647 448 449 440 -5401 1010101010 -341423 217 77777 -10 67 300 5758 74432 9856 -535 -6534 -1113 5611 -43234 -598411 87589 11111 -22212 3245 -13123 -42455 -997 -898765 459821 -9128 -444444444 71234 34631 653466 -35953
// make re && ./push_swap 2147483645 -65302 -2147483645 -1 3 2 1 4 -9 0 -16 77 -23 44 5 33 -11 513 45 -12 34 2147483646 -2147483646 115 -100 16 785983 -71 17 -99 12 10 81 11 -51 199 912 10239 -88 2147483647 -2147483647 448 449 440 -5401 1010101010 -341423 217 77777 -10 67 300 5758 74432 9856 -535 -6534 -1113 5611 -43234 -598411 87589 11111 -22212 3245 -13123 -42455 -997 -898765 459821 -9128 -444444444 71234 34631 653466 -35953 1091 91621 999999 9204885 7872728 -65433559 -13 -14 -15 -102 -120 -130 -200 400 10382 7728182 -483727 -2834 94748 -938473 -1111119 -372983 -98 -95
// make re && ./push_swap 2147483645 -65302 -2147483645 -1 3 2 1 4 -9 0 -16 77 -23 44 5 33 -11 513 45 -12 34 2147483646 -2147483646 115 -100 16 785983 -71 17 -99 12 10 81 11 -51 199 912 10239 -88 2147483647 -2147483647 448 449 440 -5401 1010101010 -341423 217 77777 -10 67 300 5758 74432 9856 -535 -6534 -1113 5611 -43234 -598411 87589 11111 -22212 3245 -13123 -42455 -997 -898765 459821 -9128 -444444444 71234 34631 653466 -35953 1091 91621 999999 9204885 7872728 -65433559 -13 -14 -15 -102 -120 -130 -200 400 10382 7728182 -483727 -2834 94748 -938473 -1111119 -372983 -98 -95 6

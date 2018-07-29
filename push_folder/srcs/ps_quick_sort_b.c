/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:25:19 by zweng             #+#    #+#             */
/*   Updated: 2018/07/20 13:03:53 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_need_push(t_array *stack, int len, int pivot)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (stack_at(stack, stack->current_size - 1 - i) > pivot)
			return (1);
		i++;
	}
	return (0);
}

void		ps_reverse_rotate_b(t_array *stack, int counter)
{
	if ((int)(stack->current_size >> 1) < counter)
	{
		while ((int)(stack->current_size) - counter++ > 0)
			stack_exec_rb();
	}
	else
	{
		while (counter-- > 0)
			stack_exec_rrb();
	}
}

void		ps_quick_sort_b(t_array *stack_a, t_array *stack_b, int len)
{
	int		pivot;
	int		i[3];

	ft_bzero((void *)i, sizeof(int) * 3);
	if (stack_is_reverse_sorted(stack_b, len))
		return ;
	if (len <= 3)
	{
		ps_reverse_sort_top(stack_b, len);
		return ;
	}
	pivot = ps_get_pivot(stack_b, len);
	while (ps_need_push(stack_b, len - i[0], pivot) && i[0]++ < len)
	{
		if (stack_peek(stack_b) > pivot && ++i[1])
			stack_exec_pa();
		else if (++i[2])
			stack_exec_rb();
	}
	ps_quick_sort_a(stack_a, stack_b, i[1]);
	ps_reverse_rotate_b(stack_b, i[2]);
	ps_quick_sort_b(stack_a, stack_b, len - i[1]);
	while (i[1]--)
		stack_exec_pb();
}

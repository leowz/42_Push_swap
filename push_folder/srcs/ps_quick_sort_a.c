/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:25:09 by zweng             #+#    #+#             */
/*   Updated: 2018/06/24 17:58:55 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_need_push(t_array *stack, int len, int pivot)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (stack_at(stack, stack->current_size - 1 - i) < pivot)
			return (1);
		i++;
	}
	return (0);
}

void	ps_reverse_rotate(t_array *stack, int counter)
{
	if ((int)(stack->current_size >> 1) < counter)
	{
		while (counter-- > 0)
			stack_exec_ra();
	}
	else
	{
		while (counter-- > 0)
			stack_exec_rra();
	}
}

void	ps_quick_sort_a(t_array *stack_a, t_array *stack_b, int len)
{
	int		pivot;
	int		push;
	int		rotate;
	int		i;

	i = 0;
	push = 0;
	rotate = 0;
	if (stack_is_sorted(stack_a))
		return ;
	else if (len <= 3)
	{
		ps_sort_top(stack_a, len);
		return ;
	}
	pivot = ps_get_pivot(stack_a, len);
	while (ps_need_push(stack_a, len - i, pivot) && i++ < len)
	{
		if (stack_peek(stack_a) < pivot && ++push)
		{
			stack_exec_pb();
		}
		else if (++rotate)
		{
			stack_exec_ra();	
		}
	}
	ps_reverse_rotate(stack_a, rotate);
	ps_quick_sort_a(stack_a, stack_b, len - push);
	ps_quick_sort_b(stack_a, stack_b, push);
	while (push--)
		stack_exec_pa();
}

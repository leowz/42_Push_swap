/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:25:19 by zweng             #+#    #+#             */
/*   Updated: 2018/06/24 17:58:33 by zweng            ###   ########.fr       */
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

void	ps_quick_sort_b(t_array *stack_a, t_array *stack_b, int len)
{
	int		pivot;
	int		push;
	int		rotate;
	int		i;

	i = 0;
	push = 0;
	rotate = 0;
	if (stack_is_reverse_sorted(stack_b, len))
		return ;
	if (len <= 3)
	{
		ps_reverse_sort_top(stack_b, len);
		return ;
	}
	pivot = ps_get_pivot(stack_b, len);
	while (ps_need_push(stack_b, len - i, pivot) && i++ < len)
	{
		if (stack_peek(stack_b) > pivot && push++)
			stack_exec_pa();
		else if (++rotate)
			stack_exec_rb();	
	}
	ps_reverse_rotate(stack_b, rotate);
	ps_quick_sort_a(stack_a, stack_b, push);
	ps_quick_sort_b(stack_a, stack_b, len - push);
	while (push--)
		stack_exec_pb();
}

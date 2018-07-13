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

void	ps_reverse_rotate_b(t_array *stack, int counter)
{
	if ((int)(stack->current_size >> 1) < counter)
	{
		while ((int)(stack->current_size) - counter++ > 0)
		{
//			ft_printf("reverse rotate rb\n");
			stack_exec_rb();
		}
	}
	else
	{
		while (counter-- > 0)
		{
//			ft_printf("reverse rotate rrb\n");
			stack_exec_rrb();
		}
	}
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
//	ft_printf("ps_quick_sort_b: len %d\n", len);
	if (stack_is_reverse_sorted(stack_b, len))
		return ;
	if (len <= 3)
	{
//		ft_printf("reverse sort top b\n");
		ps_reverse_sort_top(stack_b, len);
		return ;
	}
	pivot = ps_get_pivot(stack_b, len);
//	ft_printf("get pivot b %d\n", pivot);
	while (ps_need_push(stack_b, len - i, pivot) && i++ < len)
	{
		if (stack_peek(stack_b) > pivot && ++push)
		{
//			ft_printf("sort b push a: %d\n", stack_peek(stack_b));
			stack_exec_pa();
		}
		else if (++rotate)
		{
//			ft_printf("sort b rotate b: %d\n", stack_peek(stack_b));
			stack_exec_rb();
		}
	}
	ps_quick_sort_a(stack_a, stack_b, push);
	ps_reverse_rotate_b(stack_b, rotate);
	ps_quick_sort_b(stack_a, stack_b, len - push);
//	ft_printf("pb push back: left %d\n", push);
	while (push--)
	{
//		ft_printf("exec pb\n");
		stack_exec_pb();
	}
}

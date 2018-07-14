/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 14:54:42 by zweng             #+#    #+#             */
/*   Updated: 2018/06/24 16:48:16 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_top_is_sorted(t_array *ptr_a, int len)
{
	if (len < 2)
		return (FUN_SUCS);
	if (len == 2)
	{
		if (stack_at(ptr_a, ptr_a->current_size - 1) >
				stack_at(ptr_a, ptr_a->current_size - 2))
			stack_exec_sa();
		return (FUN_SUCS);
	}
	if (len == 3 && (stack_at(ptr_a, ptr_a->current_size - 1) <
			stack_at(ptr_a, ptr_a->current_size - 2)) &&
			(stack_at(ptr_a, ptr_a->current_size - 2) <
			 stack_at(ptr_a, ptr_a->current_size - 3)))
		return (FUN_SUCS);
	return (FUN_FAIL);
}

void	ps_sort_top(t_array *ptr_a, int len)
{
	if (ps_top_is_sorted(ptr_a, len))
		return ;
	while (len > 1)
	{
		if (stack_at(ptr_a, ptr_a->current_size - 1) >
				stack_at(ptr_a, ptr_a->current_size - 2))
			stack_exec_sa();
		if (len > 2)
			stack_exec_ra();
		len--;
	}
	while (++len < 3)
	{
		stack_exec_rra();
		if (stack_at(ptr_a, ptr_a->current_size - 1) >
				stack_at(ptr_a, ptr_a->current_size - 2))
			stack_exec_sa();
	}
}

int		ps_top_is_reverse_sorted(t_array *ptr_b, int len)
{
	if (len < 2)
		return (FUN_SUCS);
	if (len == 2)
	{
		if (stack_at(ptr_b, ptr_b->current_size - 1) <
				stack_at(ptr_b, ptr_b->current_size - 2))
			stack_exec_sb();
		return (FUN_SUCS);
	}
	if (len == 3 && (stack_at(ptr_b, ptr_b->current_size - 1) >
			stack_at(ptr_b, ptr_b->current_size - 2)) &&
			(stack_at(ptr_b, ptr_b->current_size - 2) >
			 stack_at(ptr_b, ptr_b->current_size - 3)))
		return (FUN_SUCS);
	return (FUN_FAIL);
}

void	ps_reverse_sort_top(t_array *ptr_b, int len)
{
	if (ps_top_is_reverse_sorted(ptr_b, len))
		return ;
	while (len > 1)
	{
		if (stack_at(ptr_b, ptr_b->current_size - 1) <
				stack_at(ptr_b, ptr_b->current_size - 2))
			stack_exec_sb();
		if (len > 2)
			stack_exec_rb();
		len--;
	}
	while (++len < 3)
	{
		stack_exec_rrb();
		if (stack_at(ptr_b, ptr_b->current_size - 1) <
				stack_at(ptr_b, ptr_b->current_size - 2))
			stack_exec_sb();
	}
}

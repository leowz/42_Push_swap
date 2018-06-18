/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 16:33:27 by zweng             #+#    #+#             */
/*   Updated: 2018/06/18 19:34:17 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_exec_ra(void)
{
	t_array	*ptr;
	t_array	*log;
	t_cmd	*cmd;

	if ((ptr = stack_a()) && ptr->current_size > 1 &&
			(cmd = malloc(sizeof(cmd))))
	{
		*cmd = ra;
		ft_arrinsert(ptr, ft_arrstack_pop(ptr), 0);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

void	stack_exec_rb(void)
{
	t_array	*ptr;
	t_array	*log;
	t_cmd	*cmd;

	if ((ptr = stack_b()) && ptr->current_size > 1 &&
			(cmd = malloc(sizeof(cmd))))
	{
		*cmd = rb;
		ft_arrinsert(ptr, ft_arrstack_pop(ptr), 0);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

void	stack_exec_rr(void)
{
	t_array	*ptr_a;
	t_array	*ptr_b;
	t_array	*log;
	t_cmd	*cmd;

	if ((ptr_a = stack_a()) && ptr_a->current_size > 1 &&
			(cmd = malloc(sizeof(cmd))) &&
			(ptr_b = stack_b()) && ptr_b->current_size > 1)
	{
		*cmd = rr;
		ft_arrinsert(ptr_a, ft_arrstack_pop(ptr_a), 0);
		ft_arrinsert(ptr_b, ft_arrstack_pop(ptr_b), 0);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

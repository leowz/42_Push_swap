/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 16:33:27 by zweng             #+#    #+#             */
/*   Updated: 2018/06/17 17:43:01 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_exec_ra(void)
{
	t_array	*ptr;
	t_array	*log;
	t_cmd	cmd;

	cmd = ra;
	if ((ptr = stack_a()) && ptr->current_size > 1)
	{
		ft_arrinsert(ptr, ft_arrstack_pop(ptr), 0);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

void	stack_exec_rb(void)
{
	t_array	*ptr;
	t_array	*log;
	t_cmd	cmd;

	cmd = rb;
	if ((ptr = stack_b()) && ptr->current_size > 1)
	{
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
	t_cmd	cmd;

	cmd = rr;
	if ((ptr_a = stack_a()) && ptr_a->current_size > 1 && 
			(ptr_b = stack_b()) && ptr_b->current_size > 1)
	{
		ft_arrinsert(ptr_a, ft_arrstack_pop(ptr_a), 0);
		ft_arrinsert(ptr_b, ft_arrstack_pop(ptr_b), 0);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

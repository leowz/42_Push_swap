/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 16:50:25 by zweng             #+#    #+#             */
/*   Updated: 2018/06/18 19:34:04 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_exec_rra(void)
{
	t_array		*ptr;
	t_array		*log;
	t_cmd		*cmd;

	if ((ptr = stack_a()) && ptr->current_size > 1 &&
			(cmd = malloc(sizeof(t_cmd))))
	{
		*cmd = rra;
		ft_arrstack_push(ptr, ft_arrqueue_pop(ptr));
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

void	stack_exec_rrb(void)
{
	t_array	*ptr;
	t_array	*log;
	t_cmd	*cmd;

	if ((ptr = stack_b()) && ptr->current_size > 1 &&
			(cmd = malloc(sizeof(t_cmd))))
	{
		*cmd = rrb;
		ft_arrstack_push(ptr, ft_arrqueue_pop(ptr));
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

void	stack_exec_rrr(void)
{
	t_array	*ptr_a;
	t_array	*ptr_b;
	t_array	*log;
	t_cmd	*cmd;

	if ((ptr_a = stack_a()) && ptr_a->current_size > 1 &&
			(cmd = malloc(sizeof(t_cmd))) &&
			(ptr_b = stack_b()) && ptr_b->current_size > 1)
	{
		*cmd = rrr;
		ft_arrstack_push(ptr_a, ft_arrqueue_pop(ptr_a));
		ft_arrstack_push(ptr_b, ft_arrqueue_pop(ptr_b));
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

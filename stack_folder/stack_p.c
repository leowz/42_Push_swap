/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 16:22:48 by zweng             #+#    #+#             */
/*   Updated: 2018/06/18 19:27:31 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_exec_pa(void)
{
	t_array	*ptr_a;
	t_array	*ptr_b;
	t_array	*log;
	t_cmd	*cmd;

	if ((ptr_a = stack_a()) && (ptr_b = stack_b()) && ptr_b->current_size > 0
			&& (cmd = malloc(sizeof(t_cmd))))
	{
		*cmd = pa;
		ft_arrstack_push(ptr_a, ft_arrstack_pop(ptr_b));
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

void	stack_exec_pb(void)
{
	t_array	*ptr_a;
	t_array	*ptr_b;
	t_array	*log;
	t_cmd	*cmd;

	if ((ptr_a = stack_a()) && (ptr_b = stack_b()) && ptr_a->current_size > 0
			&& (cmd = malloc(sizeof(t_cmd))))
	{
		*cmd = pb;
		ft_arrstack_push(ptr_b, ft_arrstack_pop(ptr_a));
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

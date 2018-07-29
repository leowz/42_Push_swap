/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 16:33:27 by zweng             #+#    #+#             */
/*   Updated: 2018/07/20 13:23:05 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_exec_ra(void)
{
	t_array		*ptr;
	t_array		*log;
	t_cmd		*cmd;
	t_arritem	tmp;

	if ((ptr = stack_a()) && ptr->current_size > 1 &&
			(cmd = malloc(sizeof(cmd))))
	{
		*cmd = ra;
		tmp = *ft_arrstack_pop(ptr);
		ft_arrinsert(ptr, &tmp, 0);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

void	stack_exec_rb(void)
{
	t_array		*ptr;
	t_array		*log;
	t_cmd		*cmd;
	t_arritem	tmp;

	if ((ptr = stack_b()) && ptr->current_size > 1 &&
			(cmd = malloc(sizeof(cmd))))
	{
		*cmd = rb;
		tmp = *ft_arrstack_pop(ptr);
		ft_arrinsert(ptr, &tmp, 0);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

void	stack_exec_rr(void)
{
	stack_exec_ra();
	stack_exec_rb();
}

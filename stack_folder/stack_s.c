/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:40:42 by zweng             #+#    #+#             */
/*   Updated: 2018/06/17 17:43:57 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_exec_sa(void)
{
	t_array	*ptr;
	t_array	*log;
	t_cmd	cmd;

	cmd = sa;
	if ((ptr = stack_a()) && ptr->current_size > 1)
	{
		ft_arrswap(ptr, 0, 1);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

void	stack_exec_sb(void)
{
	t_array	*ptr;
	t_array	*log;
	t_cmd	cmd;

	cmd = sb;
	if ((ptr = stack_b()) && ptr->current_size > 1)
	{
		ft_arrswap(ptr, 0, 1);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

void	stack_exec_ss(void)
{
	t_array	*ptr_a;
	t_array	*ptr_b;
	t_array	*log;
	t_cmd	cmd;

	cmd = ss;
	if ((ptr_a = stack_a()) && ptr_a->current_size > 1 &&
			(ptr_b = stack_b()) && ptr_b->current_size > 1)
	{
		ft_arrswap(ptr_a, 0, 1);
		ft_arrswap(ptr_b, 0, 1);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

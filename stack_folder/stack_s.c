/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:40:42 by zweng             #+#    #+#             */
/*   Updated: 2018/06/18 19:28:39 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_exec_sa(void)
{
	t_array	*ptr;
	t_array	*log;
	t_cmd	*cmd;

	if ((ptr = stack_a()) && ptr->current_size > 1 &&
			(cmd = malloc(sizeof(t_cmd))))
	{
		*cmd = sa;
		ft_arrswap(ptr, ptr->current_size - 1, ptr->current_size - 2);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

void	stack_exec_sb(void)
{
	t_array	*ptr;
	t_array	*log;
	t_cmd	*cmd;

	if ((ptr = stack_b()) && ptr->current_size > 1 &&
			(cmd = malloc(sizeof(t_cmd))))
	{
		*cmd = sb;
		ft_arrswap(ptr, ptr->current_size - 1, ptr->current_size - 2);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

void	stack_exec_ss(void)
{
	t_array	*ptr_a;
	t_array	*ptr_b;
	t_array	*log;
	t_cmd	*cmd;

	if ((ptr_a = stack_a()) && ptr_a->current_size > 1 &&
			(cmd = malloc(sizeof(cmd))) &&
			(ptr_b = stack_b()) && ptr_b->current_size > 1)
	{
		*cmd = ss;
		ft_arrswap(ptr_a, ptr_a->current_size - 1, ptr_a->current_size - 2);
		ft_arrswap(ptr_b, ptr_b->current_size - 1, ptr_b->current_size - 2);
		if ((log = stack_result()))
			ft_arrappend_raw(log, (void *)cmd, sizeof(t_cmd));
	}
}

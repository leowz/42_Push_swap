/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optim_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:06:13 by zweng             #+#    #+#             */
/*   Updated: 2018/07/20 13:06:51 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_optim_cmd(void)
{
	t_array *ptr;

	if ((ptr = stack_result()))
	{
		ps_optim_sasa(ptr);
		ps_optim_sbsb(ptr);
		ps_optim_pbpa(ptr);
		ps_optim_rrara(ptr);
		ps_optim_rrbrb(ptr);
	}
}

t_cmd	ps_get_cmd(t_array *stack, int index)
{
	t_arritem	*item;

	if (!stack)
		return (FUN_FAIL);
	if ((item = ft_arritem_at(stack, index)) && item->content)
		return (*(t_cmd *)(item->content));
	return (FUN_FAIL);
}

void	ps_del_cmd(t_array *stack, int index)
{
	t_arritem	*item;

	if (!stack)
		return ;
	if ((int)stack->current_size > index &&
		(item = ft_arrremove_at(stack, index)))
		ft_memdel((void **)&(item->content));
}

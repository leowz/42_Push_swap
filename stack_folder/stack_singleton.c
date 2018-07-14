/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_singleton.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:22:11 by zweng             #+#    #+#             */
/*   Updated: 2018/06/17 17:53:13 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_array	*stack_a(void)
{
	static t_array	*ptr = 0;

	if (!ptr && !(ptr = ft_arrnew()))
		return (FUN_FAIL);
	return (ptr);
}

t_array	*stack_b(void)
{
	static t_array	*ptr = 0;

	if (!ptr && !(ptr = ft_arrnew()))
		return (FUN_FAIL);
	return (ptr);
}

t_array	*stack_result(void)
{
	static t_array	*ptr = 0;

	if (!ptr && !(ptr = ft_arrnew()))
		return (FUN_FAIL);
	return (ptr);
}

void	delete_items(t_array *arr)
{
	int i;

	if (arr && (int)arr->current_size > 0)
	{
		while ((int)arr->current_size > 0)
		{
			i = (int)arr->current_size - 1;
			ft_arritem_del(ft_arrremove_at(arr, i));
		}
	}
}

void	delete_stack(void)
{
    t_array	*s1;
	t_array	*s2;
	t_array	*r;

	if ((s1 = stack_a()))
	{
		delete_items(s1);
		ft_arrdel(&s1);
	}
	if ((s2 = stack_b()))
	{
		delete_items(s2);
		ft_arrdel(&s2);
	}
	if ((r = stack_result()))
	{
		delete_items(r);
		ft_arrdel(&r);
	}
}

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

void	delete_stack(void)
{
	//ft_arrdel(stack_a());
	//ft_arrdel(stack_b());
	//ft_arrdel(stack_result());
}

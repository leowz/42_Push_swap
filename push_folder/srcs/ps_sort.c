/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:09:59 by zweng             #+#    #+#             */
/*   Updated: 2018/07/20 13:10:07 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort(void)
{
	t_array *ptr;

	if ((ptr = stack_a()))
	{
		if (stack_is_sorted(ptr))
			return ;
		if (ptr->current_size == 2)
		{
			if (stack_at(ptr, 0) < stack_at(ptr, 1))
				stack_exec_sa();
		}
		else if (ptr->current_size == 3)
			ps_sort_three_a();
		else if (ptr->current_size < 20)
			ps_quick_sort();
		else
			ps_quick_sort();
	}
	else
		ft_printf("stack a not exist");
}

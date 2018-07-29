/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:56:49 by zweng             #+#    #+#             */
/*   Updated: 2018/07/20 12:56:57 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *x, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (x[i] < x[j])
			{
				x[i] = x[i] ^ x[j];
				x[j] = x[j] ^ x[i];
				x[i] = x[i] ^ x[j];
			}
			j++;
		}
		i++;
	}
}

int		ps_get_pivot(t_array *stack, int length)
{
	int		*x;
	int		i;

	if ((x = malloc(sizeof(int) * length)))
	{
		i = 0;
		while (i < length)
		{
			x[i] = stack_at(stack, stack->current_size - 1 - i);
			i++;
		}
		bubble_sort(x, length);
		i = x[length / 2];
		ft_memdel((void **)&x);
		return (i);
	}
	else
		return (-1);
}

void	ps_quick_sort(void)
{
	t_array *ptr_a;
	t_array *ptr_b;
	t_array *ptr_cmd;

	if ((ptr_a = stack_a()) &&
			(ptr_b = stack_b()) &&
			(ptr_cmd = stack_result()))
		ps_quick_sort_a(ptr_a, ptr_b, (int)ptr_a->current_size);
	else
		ft_printf("quick_sort: stack_a is null\n");
}

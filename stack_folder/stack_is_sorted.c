/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:40:53 by zweng             #+#    #+#             */
/*   Updated: 2018/06/18 19:49:09 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int     stack_at(t_array *stack, int index)
{
    t_arritem   *item;

    if (!stack)
        return (FUN_FAIL);
    if ((item = ft_arritem_at(stack, index)) && item->content)
        return (*(int *)(item->content));
    return (FUN_FAIL);
}

int 	stack_is_sorted(t_array *stack)
{
    int index;

    if (!stack)
        return (FUN_FAIL);
    index = stack->current_size - 1;
    while (index > 0)
    {
        if (stack_at(stack, index) > stack_at(stack, index - 1)) {
           // ft_printf("not sorted\n");
            return (FUN_FAIL);
        }
        index--;
    }
    return (FUN_SUCS);
}

int 	stack_is_reverse_sorted(t_array *stack)
{
    int index;

    if (!stack)
        return (FUN_FAIL);
    index = stack->current_size - 1;
    while (index > 0)
    {
        if (stack_at(stack, index) < stack_at(stack, index - 1))
            return (FUN_FAIL);
        index--;
    }
    return (FUN_SUCS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:25:48 by zweng             #+#    #+#             */
/*   Updated: 2018/06/24 16:50:14 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ps_sort(void)
{
    t_array *ptr;

    if ((ptr = stack_a()))
    {
        if (stack_is_sorted(ptr)) {
            ft_printf("stack a is sorted\n");
            return;
        }
        if (ptr->current_size == 2)
        {
            ft_printf("stack size 2\n");
            if (stack_at(ptr, 0) < stack_at(ptr, 1)) {
                ft_printf("sort stack sa\n");
                stack_exec_sa();
            }
        }
        else if (ptr->current_size == 3) {
            ft_printf("sort three\n");
            //ps_sort_three_a();
            ps_quick_sort();
        }
        else if (ptr->current_size < 20) {
            ft_printf("sort insert\n");
            //ps_insert_sort();
            ps_quick_sort();
        }
        else {
            ft_printf("sort quick\n");
            //ps_insert_sort();
            ps_quick_sort();
        }
    }
    else
        ft_printf("stack a not exist");
}

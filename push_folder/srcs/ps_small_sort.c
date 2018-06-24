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

#include "push_swap.h"

int     judge_case(t_array *ptr)
{
    int     top;
    int     mid;
    int     bot;

    if (ptr)
    {
        top = stack_at(ptr, ptr->current_size - 1);
        mid = stack_at(ptr, ptr->current_size - 2);
        bot = stack_at(ptr, ptr->current_size - 3);
        if (top > mid && bot > top)
            return (CASE_1);
        else if (top > bot && bot > mid)
            return (CASE_2);
        else if (mid > bot && bot > top)
            return (CASE_3);
        else if (mid > top && top > bot)
            return (CASE_4);
        else
            return (CASE_5);
    }
    return (FUN_FAIL);
}

void    ps_sort_three_a(void)
{
    int     cas;
    t_array *stack;

    if ((stack = stack_a()) && (stack->current_size > 2) &&
            !stack_is_sorted(stack) && (cas = judge_case(stack)))
    {
        if (cas == CASE_1)
            stack_exec_sa();
        else if (cas == CASE_2)
            stack_exec_ra();
        else if (cas == CASE_3)
        {
            stack_exec_rra();
            stack_exec_sa();
        }
        else if (cas == CASE_4)
            stack_exec_rra();
        else if (cas == CASE_5)
        {
            stack_exec_ra();
            stack_exec_sa();
        }
    }
    else
        ft_printf("get judge case fails");
}

void    ps_reverse_sort_top_three_b(void)
{
    int     cas;
    t_array *stack;

    if ((stack = stack_b()) && (stack->current_size > 2) &&
        (cas = judge_case(stack)))
    {
        if (cas == CASE_1)
            stack_exec_sb();
        else if (cas == CASE_2)
            stack_exec_ra();
        else if (cas == CASE_3)
        {
            stack_exec_rra();
            stack_exec_sa();
        }
        else if (cas == CASE_4)
            stack_exec_rra();
        else if (cas == CASE_5)
        {
            stack_exec_ra();
            stack_exec_sa();
        }
    }
    else
        ft_printf("get judge case fails");
}

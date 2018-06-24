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

void    ps_push_b_upside(int insert_index)
{
    t_array *ptr_a;
    int     count;
    int     i;

    if ((ptr_a = stack_a()))
    {
        count = ptr_a->current_size - insert_index - 1;
        i = count;
        while (i-- > 0) {
            //ft_printf("push upside 1\n");
            stack_exec_ra();
        }
        stack_exec_pa();
        stack_exec_sa();
        i = count;
        while (i-- > 0) {
            //ft_printf("push upside 2\n");
            stack_exec_rra();
        }
    }
}

void    ps_push_b_downside(int insert_index)
{
    t_array *ptr_a;
    int     i;

    if ((ptr_a = stack_a()))
    {
        i = insert_index;
        //ft_printf("push downside insert index %d\n", insert_index);
        while (i-- > 0) {
            //ft_printf("push downside 1\n");
            stack_exec_rra();
        }
        stack_exec_pa();
        i = insert_index + 1;
        while (i-- > 0) {
            //ft_printf("push downside 2\n");
            stack_exec_ra();
        }
    }
}

int    ps_find_insert_index(t_array *stack, const int ref)
{
    int     data;
    int     index;

    if (stack)
    {
        index = stack->current_size - 1;
        data = stack_at(stack, index);
        while (ref > data && index >= 0) {
            index--;
            if (index < 0)
                return (0);
            data = stack_at(stack, index);
            //ft_printf("find insert index update data = %d\n", data);
        }
        //ft_printf("inset index find is : %d\n", index);
        return (index + 1);
    }
    else
    {
        ft_printf("find insert index error\n");
        return (-1);
    }
}

void    ps_push_b_to_a(void)
{
    t_array *ptr_a;
    t_array *ptr_b;
    int     data_b;
    int     insert_index;

    if ((ptr_a = stack_a()) && (ptr_b = stack_b()) && stack_is_sorted(ptr_a))
    {
        data_b = stack_at(ptr_b, ptr_b->current_size - 1);
        insert_index = ps_find_insert_index(ptr_a, data_b);
        if (insert_index == (int)ptr_a->current_size)
            stack_exec_pa();
        else if (insert_index >= (int)(ptr_a->current_size >> 1))
            ps_push_b_upside(insert_index);
        else
            ps_push_b_downside(insert_index);
    }
    else
        ft_printf("push b to a error \n");
}

void    ps_insert_sort(void)
{
    t_array *ptr_a;
    t_array *ptr_b;

    if ((ptr_a = stack_a()) && (ptr_b = stack_b()))
    {
        while (ptr_a->current_size > 3 && (!stack_is_sorted(ptr_a))) {
            //ft_printf("push a to b\n");
            stack_exec_pb();
        }
        ps_sort_three_a();
        while (ptr_b->current_size > 0) {
            //ft_printf("push b to a\n");
            ps_push_b_to_a();
            ps_push_b_to_a();
        }
    }
}


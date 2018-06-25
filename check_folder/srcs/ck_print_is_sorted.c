/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_print_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 18:55:06 by zweng             #+#    #+#             */
/*   Updated: 2018/06/24 18:55:09 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    ck_print_is_sorted(void)
{
    t_array *ptr_a;
    t_array *ptr_b;

    if ((ptr_a = stack_a()) && (ptr_b = stack_b()))
    {
        if (ptr_b->current_size == 0 && stack_is_sorted(ptr_a))
            ft_printf("OK\n");
        else
            ft_printf("KO\n");
    }
    else
        ft_printf("ck print: array error\n");
}

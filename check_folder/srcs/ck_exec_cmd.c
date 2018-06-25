/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_push_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 18:53:38 by zweng             #+#    #+#             */
/*   Updated: 2018/06/24 18:53:58 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    ck_exec_cmd(const char *line)
{
    if (ft_strcmp(line, "pa") == 0)
        stack_exec_pa();
    if (ft_strcmp(line, "pb") == 0)
        stack_exec_pb();
    if (ft_strcmp(line, "sa") == 0)
        stack_exec_sa();
    if (ft_strcmp(line, "sb") == 0)
        stack_exec_sb();
    if (ft_strcmp(line, "ss") == 0)
        stack_exec_ss();
    if (ft_strcmp(line, "ra") == 0)
        stack_exec_ra();
    if (ft_strcmp(line, "rb") == 0)
        stack_exec_rb();
    if (ft_strcmp(line, "rr") == 0)
        stack_exec_rr();
    if (ft_strcmp(line, "rra") == 0)
        stack_exec_rra();
    if (ft_strcmp(line, "rrb") == 0)
        stack_exec_rrb();
    if (ft_strcmp(line, "rrr") == 0)
        stack_exec_rrr();
}

//
// Created by WENGzhang on 12/07/2018.
//

#include "push_swap.h"

void	ps_optim_rarb(t_array *ptr)
{
    int i;

    if (ptr && (int)ptr->current_size > 2)
    {
        i = 0;
        while (i + 1 < (int)ptr->current_size)
        {
            if (ps_get_cmd(ptr, i) == ra && ps_get_cmd(ptr, i + 1) == rb)
            {
                ps_del_cmd(ptr, i + 1);
                ps_del_cmd(ptr, i);
                i = 0;
            }
            else if (ps_get_cmd(ptr, i) == rb && ps_get_cmd(ptr, i + 1) == ra)
            {
                ps_del_cmd(ptr, i + 1);
                ps_del_cmd(ptr, i);
                i = 0;
            }
            else
                i++;
        }
    }
}

void	ps_optim_sasb(t_array *ptr)
{
    int i;

    if (ptr && (int)ptr->current_size > 2)
    {
        i = 0;
        while (i + 1 < (int)ptr->current_size)
        {
            if (ps_get_cmd(ptr, i) == sa && ps_get_cmd(ptr, i + 1) == sb)
            {
                ps_del_cmd(ptr, i + 1);
                ps_del_cmd(ptr, i);
                i = 0;
            }
            else if (ps_get_cmd(ptr, i) == sb && ps_get_cmd(ptr, i + 1) == sa)
            {
                ps_del_cmd(ptr, i + 1);
                ps_del_cmd(ptr, i);
                i = 0;
            }
            else
                i++;
        }
    }
}

void	ps_optim_rrarrb(t_array *ptr)
{
    int i;

    if (ptr && (int)ptr->current_size > 2)
    {
        i = 0;
        while (i + 1 < (int)ptr->current_size)
        {
            if (ps_get_cmd(ptr, i) == rrb && ps_get_cmd(ptr, i + 1) == rra)
            {
                ps_del_cmd(ptr, i + 1);
                ps_del_cmd(ptr, i);
                i = 0;
            }
            else if (ps_get_cmd(ptr, i) == rra && ps_get_cmd(ptr, i + 1) == rrb)
            {
                ps_del_cmd(ptr, i + 1);
                ps_del_cmd(ptr, i);
                i = 0;
            }
            else
                i++;
        }
    }
}
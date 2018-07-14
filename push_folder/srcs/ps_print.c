/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:24:53 by zweng             #+#    #+#             */
/*   Updated: 2018/06/25 19:24:39 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_cmd_to_str(const t_cmd cmd)
{
	if (cmd == sa)
		return ("sa");
	if (cmd == sb)
		return ("sb");
	if (cmd == ss)
		return ("ss");
	if (cmd == pa)
		return ("pa");
	if (cmd == pb)
		return ("pb");
	if (cmd == ra)
		return ("ra");
	if (cmd == rb)
		return ("rb");
	if (cmd == rr)
		return ("rr");
	if (cmd == rra)
		return ("rra");
	if (cmd == rrb)
		return ("rrb");
	if (cmd == rrr)
		return ("rrr");
	ft_printf("ps cmd to str error\n");
	return (NULL);
}

void    ps_print(void)
{
    t_array 	*queue;
	t_arritem	*item;
	int			index;

	index = 0;
    if ((queue = stack_result()) && queue->current_size > 0)
    {
		while (index < (int)queue->current_size)
		{
			if ((item = ft_arritem_at(queue, index)))
			{
				ft_printf("%s\n", ps_cmd_to_str(*(t_cmd *)(item->content)));
			}
			index++;
		}
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:25:41 by zweng             #+#    #+#             */
/*   Updated: 2018/06/18 19:46:46 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

char	*stack_cmd_to_string(t_cmd *cmd)
{
	if (*cmd == sa)
		return ("sa");
	if (*cmd == sb)
		return ("sb");
	if (*cmd == ss)
		return ("ss");
	if (*cmd == pa)
		return ("pa");
	if (*cmd == pb)
		return ("pb");
	if (*cmd == ra)
		return ("ra");
	if (*cmd == rb)
		return ("rb");
	if (*cmd == rr)
		return ("rr");
	if (*cmd == rra)
		return ("rra");
	if (*cmd == rrb)
		return ("rrb");
	if (*cmd == rra)
		return ("rrr");
	else
		return ("nothing");
}

void	stack_print_a(void)
{
	t_array		*ptr;
	int			index;
	t_arritem	*data;

	if ((ptr = stack_a()))
	{
		index = ptr->current_size - 1;
		ft_printf("%%-----------stack a-------%%\n");
		while (index >= 0)
		{
			if ((data = ft_arritem_at(ptr, index)))
			{
				ft_printf("index %d -> %d\n", index, *(int *)(data->content));
				index--;
			}
		}
		ft_printf("%%-----------stack a-------%%\n");
	}
	else
		ft_printf("stack a not exist");
}

void	stack_print_b(void)
{
	t_array		*ptr;
	int			index;
	t_arritem	*data;

	if ((ptr = stack_b()))
	{
		index = ptr->current_size - 1;
		ft_printf("%%-----------stack b-------%%\n");
		while (index >= 0)
		{
			if ((data = ft_arritem_at(ptr, index)))
			{
				ft_printf("index %d -> %d\n", index, *(int *)(data->content));
				index--;
			}
		}
		ft_printf("%%-----------stack b-------%%\n");
	}
	else
		ft_printf("stack b not exist");
}

void	stack_print_cmd(void)
{
	t_array		*ptr;
	int			index;
	t_arritem	*data;

	if ((ptr = stack_result()))
	{
		index = ptr->current_size - 1;
		ft_printf("%%-----------stack result-------%%\n");
		while (index >= 0)
		{
			if ((data = ft_arritem_at(ptr, index)) && data->content)
			{
				ft_printf("index %d -> %s\n", index, 
						stack_cmd_to_string((t_cmd *)(data->content)));
				index--;
			}
		}
		ft_printf("%%-----------stack result-------%%\n");
	}
	else
		ft_printf("stack result not exist");
}

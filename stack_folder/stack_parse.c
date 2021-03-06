/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:22:08 by zweng             #+#    #+#             */
/*   Updated: 2018/07/29 11:46:30 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		is_not_dup(int nbr)
{
	t_array	*stack;
	int		index;

	if (!(stack = stack_a()))
		return (FUN_FAIL);
	index = stack->current_size - 1;
	while (index >= 0)
	{
		if (nbr == stack_at(stack, index))
			return (FUN_FAIL);
		index--;
	}
	return (FUN_SUCS);
}

int		is_valid_number(const char *str)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	if (!str || ft_strlen(str) > 11)
		return (FUN_FAIL);
	while (*str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	if (!ft_isdigit(*str))
		return (FUN_FAIL);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FUN_FAIL);
		nb = (nb << 3) + (nb << 1) + *str++ - '0';
		if ((nb > 2147483647) || ((nb > 2147483648) && (sign == -1)))
			return (FUN_FAIL);
	}
	return (FUN_SUCS);
}

int		tab_last_index(char **table)
{
	int ret;

	ret = 0;
	if (!table || !*table)
		return (-1);
	while (table[ret] && table[ret + 1])
		ret++;
	return (ret);
}

int		push_split(const char *str)
{
	char	**table;
	int		i;
	int		nbr;

	if ((table = ft_strsplit(str, ' ')))
	{
		i = tab_last_index(table);
		while (i >= 0)
		{
			if (is_valid_number(table[i]) &&
					is_not_dup((nbr = ft_atoi(table[i]))))
				stack_exec_push(nbr);
			else
				return (FUN_FAIL);
			ft_strdel(table + i);
			i--;
		}
		free(table);
		table = NULL;
	}
	return (FUN_SUCS);
}

int		stack_exec_parse(int ac, char **av)
{
	int		nbr;
	t_array	*stack;

	while (ac > 1)
	{
		ac--;
		if (ft_strchr(av[ac], ' ') && push_split(av[ac]))
			;
		else if (is_valid_number(av[ac]) && is_not_dup((nbr = ft_atoi(av[ac]))))
		{
			stack_exec_push(nbr);
		}
		else
		{
			stack_exit();
			return (FUN_FAIL);
		}
	}
	if ((stack = stack_a()) && (int)stack->current_size > 0)
		return (FUN_SUCS);
	else
		return (FUN_FAIL);
}

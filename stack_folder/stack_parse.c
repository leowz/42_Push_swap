/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:16:51 by zweng             #+#    #+#             */
/*   Updated: 2018/06/18 19:16:34 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		is_not_dup(int nbr)
{
    t_array	*stack;
	int 	index;

	if (!(stack = stack_a()))
		return (FUN_FAIL);
	index = stack->current_size - 1;
	while (index > 0)
	{
		if (nbr == stack_at(stack, index))
			return (FUN_FAIL);
		index--;
	}
	return (FUN_SUCS);
}

void	stack_exec_push(int	nbr)
{
	t_array	*ptr;
	int		*data;

	if ((ptr = stack_a()) && (data = malloc(sizeof(int))))
	{
		*data = nbr;
		ft_arrappend_raw(ptr, data, sizeof(int));
	}
	else
		ft_printf("push %d error\n", nbr);
}

int 	is_valid_number(const char *str)
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

int		stack_exec_parse(int ac, char **av)
{
    int 	nbr;

	while (ac > 1)
	{
		ac--;
		if (is_valid_number(av[ac]) && is_not_dup((nbr = ft_atoi(av[ac]))))
		{
			stack_exec_push(nbr);
		}
		else
		{
			ft_printf("not valid av %s\n", av[ac]);
			stack_exit();
			return (FUN_FAIL);
		}
	}
	return (FUN_SUCS);
}

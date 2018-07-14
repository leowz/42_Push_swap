/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:50:53 by zweng             #+#    #+#             */
/*   Updated: 2018/06/18 17:54:39 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_exit(void)
{
	ft_dprintf(STDOUT_FILENO, "Error\n");
	exit(-1);
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
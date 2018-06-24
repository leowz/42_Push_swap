/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:40:53 by zweng             #+#    #+#             */
/*   Updated: 2018/06/24 18:53:08 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ck_check_cmd_valid(const char *str)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0 ||
		ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "pa") == 0 ||
		ft_strcmp(str, "pb") == 0 || ft_strcmp(str, "ra") == 0 ||
		ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0 ||
		ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0 ||
		ft_strcmp(str, "rrr") == 0)"
		return (FUN_SUCS);
	return (FUN_FAIL);
}

void	ck_get_input(t_array *queue)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ck_check_cmd_valid(line))
			ck_push_queue(queue, line);
		else
			ck_die("cmd not valid\n");
		ft_strdel(&line);
	}
	ft_strdel(&line);
}


int		main(int ac, char **av)
{
	t_array	*queue;

	if (ac > 1)
	{
		stack_exec_parse(ac, av);
		ft_printf("\n\n");
		if ((queue = ft_arrnew()))
		{
			ck_get_input(queue);
			ck_exec_input(queue);
			ck_print_is_sorted();
		}
		else
			ck_die("queue err\n");
	}
	return (0);
}

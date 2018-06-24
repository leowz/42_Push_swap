/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:17:28 by zweng             #+#    #+#             */
/*   Updated: 2018/06/24 17:36:48 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "ft_array.h"
# include "ft_printf.h"

typedef enum		e_cmd
{
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	pa,
	pb
}					t_cmd;

# define   CASE_1 (1)
# define   CASE_2 (2)
# define   CASE_3 (3)
# define   CASE_4 (4)
# define   CASE_5 (5)

t_array	*stack_a(void);
t_array	*stack_b(void);
t_array	*stack_result(void);
void	delete_stack(void);
void	stack_exit(void);

void	stack_exec_sa(void);
void	stack_exec_sb(void);
void	stack_exec_ss(void);
void	stack_exec_pa(void);
void	stack_exec_pb(void);
void	stack_exec_ra(void);
void	stack_exec_rb(void);
void	stack_exec_rr(void);
void	stack_exec_rra(void);
void	stack_exec_rrb(void);
void	stack_exec_rrr(void);

int		stack_exec_parse(int ac, char **av);
int 	stack_is_sorted(t_array *stack);
int 	stack_is_reverse_sorted(t_array *stack, int len);
int     stack_at(t_array *stack, int index);
int     stack_peek(t_array *stack);

void	stack_print_a(void);
void	stack_print_b(void);
void	stack_print_cmd(void);
#endif

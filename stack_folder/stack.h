/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 13:17:28 by zweng             #+#    #+#             */
/*   Updated: 2018/06/17 17:40:34 by zweng            ###   ########.fr       */
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

t_array	*stack_a(void);
t_array	*stack_b(void);
t_array	*stack_result(void);
void	delete_stack(void);

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

#endif

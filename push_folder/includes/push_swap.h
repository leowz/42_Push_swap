/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:29:58 by zweng             #+#    #+#             */
/*   Updated: 2018/06/24 17:27:16 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"


void    ps_sort(void);
void    ps_print(void);
void    ps_sort_three_a(void);
void    ps_sort_seven(void);
void    ps_insert_sort(void);
void    ps_quick_sort(void);


void	ps_quick_sort_a(t_array *stack_a, t_array *stack_b, int len);
void	ps_quick_sort_b(t_array *stack_a, t_array *stack_b, int len);
void	ps_sort_top(t_array *ptr_a, int len);
void	ps_reverse_sort_top(t_array *ptr_b, int len);
int     ps_get_pivot(t_array *stack, int length);
void	ps_reverse_rotate(t_array *stack, int counter);
int		ps_top_is_sorted(t_array *ptr_a, int len);
int		ps_top_is_reverse_sorted(t_array *ptr_b, int len);
#endif

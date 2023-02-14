/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:24:41 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/14 12:47:57 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	func_pb(s_variables *var)
{
	ft_printf("pb\n");
	var->lst_a_len--;
	var->lst_b_len++;
	push_front(&var->lst_a, &var->lst_b, var->lst_a);
}

void	func_pa(s_variables *var)
{
	ft_printf("pa\n");
	var->lst_a_len++;
	var->lst_b_len--;
	push_front(&var->lst_b, &var->lst_a, var->lst_b);
}

void	func_ra(s_variables *var)
{
	ft_printf("ra\n");
	rotate_up(&var->lst_a);
}

void	func_rb(s_variables *var)
{
	ft_printf("ra\n");
	rotate_up(&var->lst_b);
}

void	func_rr(s_variables *var)
{
	ft_printf("rr\n");
	rotate_up(&var->lst_a);
	rotate_up(&var->lst_b);
}

void	func_rra(s_variables *var)
{
	ft_printf("rra\n");
	rotate_down(&var->lst_a);
}

void	func_rrb(s_variables *var)
{
	ft_printf("rrb\n");
	rotate_down(&var->lst_b);
}

void	func_rrr(s_variables *var)
{
	ft_printf("rrr\n");
	rotate_down(&var->lst_a);
	rotate_down(&var->lst_b);
}

void	func_sa(s_variables *var)
{
	ft_printf("sa\n");
	swap_nodes(var->lst_a, var->lst_a, var->lst_a->next);
}
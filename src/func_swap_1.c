/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:24:41 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/27 08:58:18 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	func_pb(t_variables *var)
{
	ft_putstr_fd("pb\n", 1);
	var->lst_a_len--;
	var->lst_b_len++;
	push_front(&var->lst_a, &var->lst_b, var->lst_a);
}

void	func_pa(t_variables *var)
{
	ft_putstr_fd("pa\n", 1);
	var->lst_a_len++;
	var->lst_b_len--;
	push_front(&var->lst_b, &var->lst_a, var->lst_b);
}

void	func_ra(t_variables *var)
{
	ft_putstr_fd("ra\n", 1);
	rotate_up(&var->lst_a);
}

void	func_rb(t_variables *var)
{
	ft_putstr_fd("rb\n", 1);
	rotate_up(&var->lst_b);
}

void	func_rr(t_variables *var)
{
	ft_putstr_fd("rr\n", 1);
	rotate_up(&var->lst_a);
	rotate_up(&var->lst_b);
}

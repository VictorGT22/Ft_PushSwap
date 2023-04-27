/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:24:41 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/26 16:24:28 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	func_pb(s_variables *var)
{
	ft_putstr_fd("pb\n", 1);
	var->lst_a_len--;
	var->lst_b_len++;
	push_front(&var->lst_a, &var->lst_b, var->lst_a);
}

void	func_pa(s_variables *var)
{
	ft_putstr_fd("pa\n", 1);
	var->lst_a_len++;
	var->lst_b_len--;
	push_front(&var->lst_b, &var->lst_a, var->lst_b);
}

void	func_ra(s_variables *var)
{
	ft_putstr_fd("ra\n", 1);
	rotate_up(&var->lst_a);

}

void	func_rb(s_variables *var)
{
	ft_putstr_fd("rb\n", 1);
	rotate_up(&var->lst_b);
}

void	func_rr(s_variables *var)
{
	ft_putstr_fd("rr\n", 1);
	rotate_up(&var->lst_a);
	rotate_up(&var->lst_b);
}

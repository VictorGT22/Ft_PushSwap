/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:24:41 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/26 16:23:53 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	func_rra(s_variables *var)
{
	ft_putstr_fd("rra\n", 1);
	rotate_down(&var->lst_a);
}

void	func_rrb(s_variables *var)
{
	ft_putstr_fd("rrb\n", 1);
	rotate_down(&var->lst_b);
}

void	func_rrr(s_variables *var)
{
	ft_putstr_fd("rrr\n", 1);
	rotate_down(&var->lst_a);
	rotate_down(&var->lst_b);
}

void	func_sa(s_variables *var)
{
	ft_putstr_fd("sa\n", 1);
	swap_nodes(var->lst_a, var->lst_a, var->lst_a->next);
}

void	func_sb(s_variables *var)
{
	ft_putstr_fd("sb\n", 1);
	swap_nodes(var->lst_b, var->lst_b, var->lst_b->next);
}
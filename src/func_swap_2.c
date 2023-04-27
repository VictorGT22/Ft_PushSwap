/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:24:41 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/27 08:58:43 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	func_rra(t_variables *var)
{
	ft_putstr_fd("rra\n", 1);
	rotate_down(&var->lst_a);
}

void	func_rrb(t_variables *var)
{
	ft_putstr_fd("rrb\n", 1);
	rotate_down(&var->lst_b);
}

void	func_rrr(t_variables *var)
{
	ft_putstr_fd("rrr\n", 1);
	rotate_down(&var->lst_a);
	rotate_down(&var->lst_b);
}

void	func_sa(t_variables *var)
{
	ft_putstr_fd("sa\n", 1);
	swap_nodes(var->lst_a, var->lst_a, var->lst_a->next);
}

void	func_sb(t_variables *var)
{
	ft_putstr_fd("sb\n", 1);
	swap_nodes(var->lst_b, var->lst_b, var->lst_b->next);
}

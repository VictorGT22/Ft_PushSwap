/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:02:19 by vics              #+#    #+#             */
/*   Updated: 2023/05/24 10:03:56 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	external_midpoint_a(t_variables *var, int pos)
{
	int	i;

	if (pos >= var->lst_a_len / 2)
	{
		i = 0;
		while (i < var->lst_a_len - pos)
		{
			func_rra(var);
			i++;
		}
	}
	else
	{
		i = pos;
		while (i > 0)
		{
			func_ra(var);
			i--;
		}
	}
}

int	mid_point_a(t_variables *var, int mid_point, int chunk)
{
	int				pos;
	int				dir;
	int				mid;
	t_linked_lst	*closer;
	t_linked_lst	*last;
	

	closer = lst_closer(&var->lst_a, mid_point);
	pos = lst_pos(&var->lst_a, closer);
	last = ft_lstlast(var->lst_b);
	if (var->lst_b_len > 1 && var->lst_b->num < last->num)
		func_rb(var);
	//else if (var->lst_b_len > 1 && var->lst_b->num < var->lst_b->next->num)
	//	func_rb(var);
	//else if (var->lst_b_len > 1 && var->lst_b->num < var->lst_b->next->num)
	//	func_sb(var);
	if (pos == 0)
	{
		func_pb(var);
		var->lst_b->chunk = chunk;
	}
	else if (pos != -1)
		external_midpoint_a(var, pos);
	return (pos);
}

void	algorithm_1(t_variables *var, int chunk)
{
	int	big;
	int	low;
	int	midpoint;
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (pos != -1)
	{
		if (i == 0)
		{
			big = lst_bigger(&var->lst_a)->num;
			low = lst_lower(&var->lst_a)->num;
			midpoint = (big + low) / 2;
		}
		pos = mid_point_a(var, midpoint, chunk);
		i++;
	}
	//printf("MIDPOINT %d\n", mid_point);
	//if (!lst_in_order(&var->lst_a))
	//	func_sa(var);
}

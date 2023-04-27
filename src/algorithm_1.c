/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:02:19 by vics              #+#    #+#             */
/*   Updated: 2023/04/26 16:20:01 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	mid_point_a(s_variables *var, int mid_point, int chunk)
{
	int pos;
	int dir;
	int mid;
	linked_lst *closer;

	closer = lst_closer(&var->lst_a, mid_point);
	pos = lst_pos(&var->lst_a, closer);
	if (pos == 0)
	{
		func_pb(var);
		var->lst_b->chunk = chunk;
	}
	else if (pos != -1)
	{
		if (pos >= var->lst_a_len / 2)
			for(int i = 0; i < var->lst_a_len - pos; i++)
				func_rra(var);
		else
			for(int i = pos; i > 0; i--)
				func_ra(var);

	}
	return (pos);
}

void	algorithm_1(s_variables *var, int chunk)
{
	int	big;
	int	low;
	int mid_point;
	int i = 0;
	int	pos;

	pos = 0;
	while (pos != -1)
	{
		if (i == 0)
		{
			big = lst_bigger(&var->lst_a)->num;
			low = lst_lower(&var->lst_a)->num;
			mid_point = (big + low) / 2;
		}
		pos = mid_point_a(var, mid_point, chunk);
		i++;
	}
	if (!lst_in_order(&var->lst_a))
		func_sa(var);
}
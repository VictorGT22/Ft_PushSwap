/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:06:25 by vics              #+#    #+#             */
/*   Updated: 2023/04/26 16:08:22 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	mid_point_chunk(s_variables *var, int chunk)
{
	linked_lst *temp;
	int lower;
	int bigger;
	int len;

	temp = var->lst_b;
	bigger = temp->num;
	lower = temp->num;
	len = 0;
	while (temp && temp->chunk == chunk)
	{
		if (lower > temp->num)
			lower = temp->num;
		else if (bigger < temp->num)
			bigger = temp->num;
		temp = temp->next;
		len++;
	}
	if (len == 0)
		return (-1);
	return ((bigger + lower) / 2);
}

int	lst_closer_chunk(linked_lst *lst, int midpoint, int chunk)
{
	int i;
	int value;
	int pos;
	linked_lst *temp;

	i = 0;
	pos = -1;
	temp = lst;
	value = temp->num;
	while (temp)
	{
		if (temp->num >= midpoint && value <= temp->num)
		{
			value = temp->num;
			pos = i;
		}
		i++;
		temp = temp->next;
	}
	return (pos);
}

int	mid_point_bigger(s_variables *var, int mid_point, int chunk)
{
	int pos;
	int restore;

	pos = 0;
	while (var->lst_b && var->lst_b->chunk == chunk && pos != -1)
	{
		pos = lst_closer_chunk(var->lst_b, mid_point, chunk);
		if (pos == 0 || pos == 1)
		{
			if (pos == 1)
				func_sb(var);
			func_pa(var);
			var->lst_a->chunk = 0;
		}
		else if (pos != -1)
		{
			if (chunk != 0)
				restore += pos;
			for(int i = 0; i < pos; i++)
				func_rb(var);
			func_pa(var);
			var->lst_a->chunk = 0;
		}
	}
	for (int i = 0; i < restore, i++;)
		func_rrb(var);
}

void	algorithm_2(s_variables *var, int chunk)
{
	int mid_point;

	while (var->lst_b && var->lst_b->chunk == chunk)
	{
		mid_point = mid_point_chunk(var, chunk);
		mid_point_bigger(var, mid_point, chunk);
	}
}

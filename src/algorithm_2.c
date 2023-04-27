/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:06:25 by vics              #+#    #+#             */
/*   Updated: 2023/04/27 10:40:19 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	mid_point_chunk(t_variables *var, int chunk)
{
	t_linked_lst	*temp;
	int				lower;
	int				bigger;
	int				len;

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

int	lst_closer_chunk(t_linked_lst *lst, int midpoint, int chunk)
{
	int				i;
	int				value;
	int				pos;
	t_linked_lst	*temp;

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

int	ext_mid_point_bigger(t_variables *var, int pos, int chunk)
{
	int	i;
	int	restore;

	i = 0;
	restore = 0;
	if (pos != -1)
	{
		if (chunk != 0)
			restore += pos;
		while (i < pos)
		{
			func_rb(var);
			i++;
		}
		func_pa(var);
		var->lst_a->chunk = 0;
	}
	return (restore);
}

void	mid_point_bigger(t_variables *var, int mid_point, int chunk)
{
	int	i;
	int	pos;
	int	restore;

	i = 0;
	pos = 0;
	restore = 0;
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
		else
			restore = ext_mid_point_bigger(var, pos, chunk);
	}
	while (i < pos)
	{
		func_rrb(var);
		i++;
	}
}

void	algorithm_2(t_variables *var, int chunk)
{
	int	mid_point;

	while (var->lst_b && var->lst_b->chunk == chunk)
	{
		mid_point = mid_point_chunk(var, chunk);
		mid_point_bigger(var, mid_point, chunk);
	}
}

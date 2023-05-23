/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:06:25 by vics              #+#    #+#             */
/*   Updated: 2023/05/23 23:34:30 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

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

int	lst_closer_chunk(t_variables *var, t_linked_lst *lst, int midpoint, int chunk)
{
	int				i;
	int				pos;
	int				value;
	t_linked_lst	*temp;
	
	i = 0;
	temp = lst;
	pos = -1;
	value = temp->num;
	while (temp)
	{
		//printf("EEEEntra\n");
		if (temp->num >= value && temp->chunk == chunk)
		{
			value = temp->num;
			pos = i;
		}
		i++;
		temp = temp->next;
	}
	if (var->lst_b_len / 2 >= pos)
		return (pos);
	//printf("INFERIOR long: %d, pos: %d mov: %d\n", var->lst_b_len, pos, (var->lst_b_len - pos + 1) * -1);
	return ((var->lst_b_len - pos) * -1);
	
}

void	ext_mid_point_bigger(t_variables *var, int pos, int chunk)
{
	int	i;
	int	restore;

	i = 0;
	if (pos > 0)
	{
		while (i < pos)
		{
			func_rb(var);
			i++;
		}
	}
	else
	{
		while (pos < 0)
		{
			func_rrb(var);
			pos++;
		}
	}
	func_pa(var);
	var->lst_a->chunk = 0;
}

int	check_chunk(t_linked_lst *lst, int chunk, int midpoint)
{
	t_linked_lst	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->chunk == chunk && temp->num >= midpoint)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	mid_point_bigger(t_variables *var, int mid_point, int chunk)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (var->lst_b && var->lst_b->chunk == chunk && pos != -1)
	{
		pos = -1;
		if (check_chunk(var->lst_b, chunk, mid_point))
		{	
			pos = lst_closer_chunk(var, var->lst_b, mid_point, chunk);
			if (pos == 0 || pos == 1)
			{
				if (pos == 1)
					func_sb(var);
				func_pa(var);
				var->lst_a->chunk = 0;
			}
			else
				ext_mid_point_bigger(var, pos, chunk);
		}
		//print_information(var);
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
		if (var->lst_a_len > 1 && var->lst_a->num > var->lst_a->next->num)
			func_ra(var);
	}
}

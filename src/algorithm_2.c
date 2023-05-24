/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:06:25 by vics              #+#    #+#             */
/*   Updated: 2023/05/24 10:53:30 by vics             ###   ########.fr       */
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

// int	lst_closer_chunk(t_variables *var, t_linked_lst *lst, int midpoint, int chunk)
// {
	// int				i;
	// int				pos;
	// int				value;
	// t_linked_lst	*temp;
	// 
	// i = 0;
	// temp = lst;
	// pos = -1;
	// value = temp->num;
	//print_information(var);
	// while (temp)
	// {
		// if (temp->num >= value && temp->chunk == chunk)
		// {
			// value = temp->num;
			// pos = i;
			//printf("MAX VALUE = %d->pos: %d, chunk %d, midpoint: %d\n", value, i, chunk, midpoint);
		// }
		// i++;
		// temp = temp->next;
	// }
	//printf("pos: %d, mitad: %d,  valor: %d\n", pos, var->lst_b_len / 2, value);
	// if (var->lst_b_len / 2 >= pos)
		// return (pos);
	//printf("INFERIOR long: %d, pos: %d mov: %d\n", var->lst_b_len, pos, (var->lst_b_len - pos + 1) * -1);
	// return ((var->lst_b_len - pos) * -1);
	// 
// }


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
	printf("POS %d value: %d\n", pos, value);
	if (var->lst_b_len / 2 >= pos)
		return (pos);
	printf("INFERIOR long: %d, pos: %d mov: %d\n", var->lst_b_len, pos, (var->lst_b_len - pos + 1) * -1);
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

int	check_chunk(t_linked_lst *lst, int chunk)
{
	t_linked_lst	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->chunk == chunk)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	check_chunk_midpoint(t_linked_lst *lst, int chunk, int midpoint)
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


void	mid_point_closer(t_variables *var, int chunk, int midpoint)
{
	int pos;

	while (var->lst_b && check_chunk_midpoint(var->lst_b, chunk, midpoint)) // buscar el mas proximo moverlo a la stack a
	{
		pos = lst_closer_chunk(var, var->lst_b, midpoint, chunk);
		printf("EL CLOSER: %d\n", pos);
		if (pos == 0 || pos == 1)
		{
			if (pos == 1)
				func_sb(var);
			func_pa(var);
			if (var->lst_a_len > 1 && var->lst_a->num > var->lst_a->next->num)
				func_ra(var);
			var->lst_a->chunk = 0;
		}
		else
			ext_mid_point_bigger(var, pos, chunk);
	}
}

void	algorithm_2(t_variables *var, int chunk)
{
	int	midpoint;

	chunk -= 1;
	printf("Entra\n");
	print_information(var);
	while (var->lst_b && check_chunk(var->lst_b, chunk))
	{
		printf("entra\n");
		midpoint = mid_point_chunk(var, chunk); // obtengo punto medio
		mid_point_closer(var, chunk, midpoint);
		printf("MIDPOINT %d\n", midpoint);
		print_information(var);
		//sleep(1);
	}
	//exit(0);
}
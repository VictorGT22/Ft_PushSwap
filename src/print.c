/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:52:56 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/14 12:47:12 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_linkeds(linked_lst *lst)
{
	linked_lst *temp;

	while (lst)
	{
		temp = lst;
		//free(temp);
		lst = lst->next;
	}
}

void	free_info(s_variables *var)
{
	free_linkeds(var->lst_a);
	free_linkeds(var->lst_b);
	free(var);
}

linked_lst *init_list()
{
	linked_lst *lst = malloc(sizeof(linked_lst) * 1);
	lst->next = malloc(sizeof(linked_lst) * 1);
	lst->next = NULL;
}


void	swap_data_node(linked_lst *first, linked_lst *node, linked_lst *temp_prev, linked_lst *temp_next)
{
	if (temp_prev)
	{
		node->prev = temp_prev;
		node->prev->next = node;
	}
	else
	{
		first = node;
		node->prev = NULL;
	}
	node->next = temp_next;
}

void	swap_nodes(linked_lst *first, linked_lst *a, linked_lst *b)
{
	linked_lst	*temp_prev_a;
	linked_lst	*temp_prev_b;
	linked_lst	*temp_next_a;
	linked_lst	*temp_next_b;
	linked_lst	temp;

	temp = *a;
	if (!first || !a || !b)
		return ;
	if (a->prev)
		temp_prev_a = a->prev;
	else
		temp_prev_a = NULL;
	if (b->prev)
		temp_prev_b = b->prev;
	else
		temp_prev_b = NULL;
	temp_next_a = a->next;
	temp_next_b = b->next;

	*a = *b;
	*b = temp;
	swap_data_node(first, b, temp_prev_b, temp_next_b);
	swap_data_node(first, a, temp_prev_a, temp_next_a);
}

void	print_linked(linked_lst *lst)
{
	linked_lst *temp = lst;
	while (temp)
	{
		printf("numero b: %d\n", temp->num);
		if (temp->prev)
			printf("\tPrevious: %d\n\n", temp->prev->num);
		else
			printf("\tPrevious: (NULL)\n");
		if (temp->next)
			printf("\tNext: %d\n\n", temp->next->num);
		else
			printf("\tNext: (NULL)\n");
		temp = temp->next;
	}
}


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
		print_information(var);
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
	while (var->lst_a_len >= 2 && pos != -1)
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

	while ( var->lst_b && var->lst_b->chunk == chunk && pos != -1)
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

	while ( var->lst_b && var->lst_b->chunk == chunk)
	{
		mid_point = mid_point_chunk(var, chunk);
		mid_point_bigger(var, mid_point, chunk);
	}
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	int i;
	s_variables *var;
	linked_lst *temp_a;
	linked_lst *temp_b;

	i = 1;
	var = malloc(sizeof(s_variables) * 1);
	var->lst_a = init_list();
	var->lst_b = init_list();
	temp_a = var->lst_a;
	temp_b = var->lst_b;
	while (i < argc)
	{
		temp_a->num = atoi(argv[i]);
		temp_a->next = ft_calloc(sizeof(linked_lst), 1);
		temp_a->next->prev = temp_a;
		temp_a = temp_a->next;
		temp_a->next = NULL;
		i++;
	}
	temp_a->prev->next = NULL;
	temp_a = var->lst_a;
	var->lst_b = NULL;
	//print_information(var);
	
	var->lst_a_len = i - 1;
	var->lst_b_len = 0;

	i = 0;
	while (!lst_in_order(&var->lst_a))
	{
		algorithm_1(var, i);
		i++;
	}
	while (i >= 0)
	{
		algorithm_2(var, i);
		i--;
	}
	print_information(var);
	return 0;
}
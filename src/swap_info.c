/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:52:56 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/26 16:12:28 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
/*
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
}*/

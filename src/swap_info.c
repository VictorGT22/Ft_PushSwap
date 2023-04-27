/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:52:56 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/27 08:57:32 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_data_node(t_linked_lst *first, t_linked_lst *node,
t_linked_lst *temp_prev, t_linked_lst *temp_next)
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

void	swap_nodes(t_linked_lst *first, t_linked_lst *a, t_linked_lst *b)
{
	t_linked_lst	*temp_prev_a;
	t_linked_lst	*temp_prev_b;
	t_linked_lst	*temp_next_a;
	t_linked_lst	*temp_next_b;
	t_linked_lst	temp;

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

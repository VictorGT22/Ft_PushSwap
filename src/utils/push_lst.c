/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:35:08 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/27 08:55:52 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_add_front(t_linked_lst **lst, t_linked_lst *new)
{
	if (*lst && new)
	{
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}
	else if (!*lst)
	{
		*lst = new;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
	}
}

void	push_front(t_linked_lst **first_src,
t_linked_lst **first_dest, t_linked_lst *ptr)
{
	t_linked_lst	*temp_prev_src;
	t_linked_lst	*temp_next_src;

	if (ptr->prev)
	{
		temp_prev_src = ptr->prev;
		temp_next_src = ptr->next;
		ptr->prev->next = temp_next_src;
		if (ptr->next != NULL)
			ptr->next->prev = temp_prev_src;
	}
	else
	{
		temp_next_src = ptr->next;
		*first_src = temp_next_src;
		if (temp_next_src != NULL)
			(*first_src)->prev = NULL;
	}
	ft_add_front(first_dest, ptr);
}

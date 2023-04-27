/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:58:29 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/27 09:13:00 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	lst_in_order(t_linked_lst **lst)
{
	t_linked_lst	*temp;

	temp = *lst;
	while (temp)
	{
		if (temp->prev && temp->prev->num > temp->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

t_linked_lst	*lst_lower(t_linked_lst **lst)
{
	t_linked_lst	*temp;
	t_linked_lst	*lower;

	temp = *lst;
	lower = *lst;
	while (temp)
	{
		if (lower->num > temp->num)
			lower = temp;
		temp = temp->next;
	}
	return (lower);
}

t_linked_lst	*lst_bigger(t_linked_lst **lst)
{
	t_linked_lst	*temp;
	t_linked_lst	*bigger;

	temp = *lst;
	bigger = *lst;
	while (temp)
	{
		if (bigger->num < temp->num)
			bigger = temp;
		temp = temp->next;
	}
	return (bigger);
}

int	lst_pos(t_linked_lst **lst, t_linked_lst *node)
{
	t_linked_lst	*temp;
	int				i;

	i = 0;
	temp = *lst;
	if (!node)
		return (-1);
	while (temp)
	{
		if (temp == node)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}

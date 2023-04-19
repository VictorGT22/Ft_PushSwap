/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:00:05 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/14 09:25:16 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

linked_lst	*ft_lstlast(linked_lst *lst)
{
	linked_lst	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_lstadd_back(linked_lst **lst, linked_lst *new)
{
	linked_lst	*temp;

	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			temp = ft_lstlast(*lst);
			new->prev = temp;
			temp->next = new;
		}
	}
}

void	rotate_up(linked_lst **lst)
{
	linked_lst	*temp;

	temp = *lst;
	if ((*lst)->next)
	{
		*lst = (*lst)->next;
		temp->next = NULL;
		ft_lstadd_back(lst, temp);
		(*lst)->prev = NULL;
	}
}

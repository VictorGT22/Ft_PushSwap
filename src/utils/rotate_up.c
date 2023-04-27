/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:00:05 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/27 08:55:52 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_linked_lst	*ft_lstlast(t_linked_lst *lst)
{
	t_linked_lst	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_lstadd_back(t_linked_lst **lst, t_linked_lst *new)
{
	t_linked_lst	*temp;

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

void	rotate_up(t_linked_lst **lst)
{
	t_linked_lst	*temp;

	temp = *lst;
	if ((*lst)->next)
	{
		*lst = (*lst)->next;
		temp->next = NULL;
		ft_lstadd_back(lst, temp);
		(*lst)->prev = NULL;
	}
}

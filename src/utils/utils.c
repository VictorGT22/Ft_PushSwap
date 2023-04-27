/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:58:29 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/26 13:58:39 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (temp)
	{
		i++;
		temp = temp->next;
	}	
	return (i);
}

int	lst_in_order(linked_lst **lst)
{
	linked_lst *temp;

	temp = *lst;
	while (temp)
	{
		if(temp->prev && temp->prev->num > temp->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

linked_lst *lst_lower(linked_lst **lst)
{
	linked_lst *temp;
	linked_lst *lower;

	temp = *lst;
	lower = *lst;
	while (temp)
	{
		if(lower->num > temp->num)
			lower = temp;
		temp = temp->next;
	}
	return (lower);
}

linked_lst *lst_bigger(linked_lst **lst)
{
	linked_lst *temp;
	linked_lst *bigger;

	temp = *lst;
	bigger = *lst;
	while (temp)
	{
		if(bigger->num < temp->num)
			bigger = temp;
		temp = temp->next;
	}
	return (bigger);
}

int	lst_pos(linked_lst **lst, linked_lst *node)
{
	linked_lst *temp;
	int i;

	i = 0;
	temp = *lst;
	if (!node)
		return (-1);
	while (temp)
	{
		if(temp == node)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}

linked_lst *lst_closer(linked_lst **lst, int mid_point)
{
	linked_lst *temp;
	linked_lst *pos;
	int	i;
	int j;

	temp = *lst;
	pos = NULL;
	i = 0;
	j = 1;
	while (temp)
	{
		if (temp->num <= mid_point)
		{
			pos = temp;
			break;
		}
		i++;
		temp = temp->next;
	}
	temp = ft_lstlast(*lst);
	while (temp)
	{
		if (temp->num <= mid_point && j <= i && temp->num < pos->num)
		{
			pos = temp;
			break;
		}
		j++;
		temp = temp->prev;
	}
	return (pos);
}


linked_lst *lst_closer_bigger(linked_lst **lst, int mid_point)
{
	linked_lst *temp;
	linked_lst *pos;
	int	i;
	int j;

	temp = *lst;
	pos = NULL;
	i = 0;
	j = 1;
	while (temp)
	{
		if (temp->num >= mid_point)
		{
			pos = temp;
			break;
		}
		i++;
		temp = temp->next;
	}
	temp = ft_lstlast(*lst);
	while (temp)
	{
		if (temp->num <= mid_point && j <= i && temp->num < pos->num)
		{
			pos = temp;
			break;
		}
		j++;
		temp = temp->prev;
	}
	return (pos);
}


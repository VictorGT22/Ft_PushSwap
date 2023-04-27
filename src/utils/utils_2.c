/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:58:29 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/27 09:22:54 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_linked_lst	*ext_lst_closer(t_linked_lst **lst,
t_linked_lst *pos, int mid_point, int i)
{
	t_linked_lst	*temp;
	int				j;

	j = 1;
	temp = ft_lstlast(*lst);
	while (temp)
	{
		if (temp->num <= mid_point && j <= i && temp->num < pos->num)
		{
			pos = temp;
			break ;
		}
		j++;
		temp = temp->prev;
	}
	return (pos);
}

t_linked_lst	*lst_closer(t_linked_lst **lst, int mid_point)
{
	t_linked_lst	*temp;
	t_linked_lst	*pos;
	int				i;

	i = 0;
	temp = *lst;
	pos = NULL;
	while (temp)
	{
		if (temp->num <= mid_point)
		{
			pos = temp;
			break ;
		}
		i++;
		temp = temp->next;
	}
	return (ext_lst_closer(lst, pos, mid_point, i));
}

t_linked_lst	*lst_closer_bigger(t_linked_lst **lst, int mid_point)
{
	t_linked_lst	*temp;
	t_linked_lst	*pos;
	int				i;

	temp = *lst;
	pos = NULL;
	i = 0;
	while (temp)
	{
		if (temp->num >= mid_point)
		{
			pos = temp;
			break ;
		}
		i++;
		temp = temp->next;
	}
	return (ext_lst_closer(lst, pos, mid_point, i));
}

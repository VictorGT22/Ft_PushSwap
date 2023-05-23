/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:53:23 by vics              #+#    #+#             */
/*   Updated: 2023/05/23 11:19:50 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

t_linked_lst	*new_node(int num)
{
	t_linked_lst	*node;

	node = malloc(sizeof(t_linked_lst) * 1);
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	return (node);
}

void	lstadd_back(t_linked_lst **lst, t_linked_lst *new)
{
	t_linked_lst	*temp;

	if (lst)
	{
		if (!(*lst))
		{
			*lst = new;
			(*lst)->prev = NULL;
		}
		else
		{
			temp = ft_lstlast(*lst);
			temp->next = new;
			temp->next->prev = temp;
		}
	}
}

t_linked_lst	*lstlast(t_linked_lst *lst)
{
	t_linked_lst	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	add_info_linked(t_variables *var, int argc, char **argv)
{
	int				i;
	t_linked_lst	*node;

	i = 1;
	if (argc == 1)
	{
		printf(ERROR_MSG);
		return (-1);
	}
	while (i < argc)
	{
		if (!ft_str_isdigit(argv[i]))
			return (-1);
		node = new_node(ft_atoi(argv[i]));
		if (!node)
			return (-1);
		lstadd_back(&var->lst_a, node);
		i++;
	}
	var->lst_a_len = i - 1;
	var->lst_b_len = 0;
	//printf("no error\n");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:53:23 by vics              #+#    #+#             */
/*   Updated: 2023/04/26 16:00:09 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

linked_lst *init_list()
{
	linked_lst *lst = malloc(sizeof(linked_lst) * 1);
	if (!lst)
		return (NULL);
	lst->next = NULL;
}

linked_lst *new_node(int num)
{
	linked_lst *node;

	node = malloc(sizeof(linked_lst) * 1);
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	return (node);
}

void	lstadd_back(linked_lst **lst, linked_lst *new)
{
	linked_lst	*temp;

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

linked_lst	*lstlast(linked_lst *lst)
{
	linked_lst	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int add_info_linked(s_variables *var, int argc, char **argv)
{
	int i;
	linked_lst *node;

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
	return 1;
}
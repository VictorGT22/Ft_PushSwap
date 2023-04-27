/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:45:15 by vics              #+#    #+#             */
/*   Updated: 2023/04/26 15:51:52 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_linkeds(linked_lst *lst)
{
	linked_lst *temp;
	linked_lst *node;

	lst;
	while (lst)
	{
		node = lst;
		lst = lst->next;
		free(node);
	}
	free(lst);
}

void	free_info(s_variables *var)
{
	if (var->lst_a)
		free_linkeds(var->lst_a);
	if (var->lst_b)	
		free_linkeds(var->lst_b);
	free(var);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:45:15 by vics              #+#    #+#             */
/*   Updated: 2023/04/27 08:58:32 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_linkeds(t_linked_lst *lst)
{
	t_linked_lst	*temp;
	t_linked_lst	*node;

	while (lst)
	{
		node = lst;
		lst = lst->next;
		free(node);
	}
	free(lst);
}

void	free_info(t_variables *var)
{
	if (var->lst_a)
		free_linkeds(var->lst_a);
	if (var->lst_b)
		free_linkeds(var->lst_b);
	free(var);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 02:08:47 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/14 02:39:17 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_down(linked_lst **lst)
{
	linked_lst *last;

	last = ft_lstlast(*lst);
	push_front(lst, lst, last);
	(*lst)->prev = NULL;
}

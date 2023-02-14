/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:32:04 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/14 11:16:40 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_information(s_variables *var)
{
	int i;
	linked_lst *temp_a;
	linked_lst *temp_b;

	i = 0;
	temp_a = var->lst_a;
	temp_b = var->lst_b;
	while (temp_a || temp_b)
	{
		if (temp_a)
		{
			ft_printf("%d ", temp_a->num);
			temp_a = temp_a->next;
		}
		else
			ft_printf("  ");
		if (temp_b)
		{
			ft_printf("%d", temp_b->num);
			temp_b = temp_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("_ _\na b\n");
	while (i < 10)
	{
		ft_printf("_");
		i++;
	}
	ft_printf("\n\n");	
}
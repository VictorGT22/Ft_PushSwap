/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:44:40 by vics              #+#    #+#             */
/*   Updated: 2023/04/26 16:19:42 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void push_swap(s_variables *var, int argc, char **argv)
{
	int i;

	i = 1;
	if (add_info_linked(var, argc, argv) == -1)
		return ;
	lst_in_order(&var->lst_a);
	while(!lst_in_order(&var->lst_a))
	{
		i = 0;
		while (var->lst_a_len >= 2 && !lst_in_order(&var->lst_a))
			algorithm_1(var, i++);
		while (i >= 0)
			algorithm_2(var, i--);
	}
}

int	main(int argc, char **argv)
{
	s_variables *var;

	var = malloc(sizeof(s_variables) * 1);
	var->lst_a = NULL;
	var->lst_b = NULL;
	if (!var)
		return (0);
	push_swap(var, argc, argv);
	free_info(var);
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:44:40 by vics              #+#    #+#             */
/*   Updated: 2023/04/27 08:56:34 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_swap(t_variables *var, int argc, char **argv)
{
	int	i;

	i = 1;
	if (add_info_linked(var, argc, argv) == -1)
		return ;
	lst_in_order(&var->lst_a);
	while (!lst_in_order(&var->lst_a))
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
	t_variables	*var;

	var = malloc(sizeof(t_variables) * 1);
	var->lst_a = NULL;
	var->lst_b = NULL;
	if (!var)
		return (0);
	push_swap(var, argc, argv);
	free_info(var);
	return (0);
}

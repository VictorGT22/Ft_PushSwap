/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:44:40 by vics              #+#    #+#             */
/*   Updated: 2023/05/23 23:35:41 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	print_information(t_variables *var)
{
	t_linked_lst	*lst_1;
	t_linked_lst	*lst_2;
	
	lst_1 = var->lst_a;
	lst_2 = var->lst_b;
	printf("\n\n\n");
	while (lst_1 || lst_2)
	{
		if (lst_1)
		{
			printf("%d", lst_1->num);
			printf("->");
			printf("%-8d", lst_1->chunk);
			lst_1 = lst_1->next;
		}
		else
		{
			printf("\t\t");
		}
		if (lst_2)
		{
			printf("%d", lst_2->num);
			printf("->");
			printf("%d", lst_2->chunk);
			lst_2 = lst_2->next;
		}
		printf("\n");
	}
	printf("________________________\n    a              b    \n");
}

int	no_bigger_num(t_variables *var)
{
	int min_a;
	t_linked_lst	*lst;

	lst = var->lst_a;
	min_a = lst->num;
	while (lst)
	{
		if (lst->num < min_a)
			min_a = lst->num;
		lst = lst->next;
	}
	if (var->lst_b_len == 0)
		return (0);
	lst = var->lst_b;
	while (lst)
	{
		if (lst->num > min_a)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	push_swap(t_variables *var, int argc, char **argv)
{
	int	i;

	i = 1;
	if (add_info_linked(var, argc, argv) == -1)
		return ;
	//lst_in_order(&var->lst_a);
	//print_information(var);
	while (!lst_in_order(&var->lst_a))
	{
		if (var->lst_a_len >= 2 && var->lst_a->num > var->lst_a->next->num)
			func_sa(var);
		i = 0;
		while (var->lst_a_len >= 2)
			algorithm_1(var, i++);
		while (i >= 0)
		{
			algorithm_2(var, i--);
			//exit(0);
		}
		//printf("ENTRA\n");
		//sleep(1);
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

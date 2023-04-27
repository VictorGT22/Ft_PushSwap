/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vics <vics@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:43:48 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/26 16:05:00 by vics             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_h
# define PUSHSWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "pushswap_struct.h"
# include <stdbool.h>
# include <limits.h>

//MACROS
# define ERROR_MSG "Error\n" 

//DISPLAY INFO
void	print_information(s_variables *var);

//STANDARD
linked_lst	*ft_lstlast(linked_lst *lst);

//FUNCTIONS PUSHSWAP
void	func_pa(s_variables *var);
void	func_pb(s_variables *var);
void	func_rra(s_variables *var);
void	func_rrr(s_variables *var);
void	func_rrb(s_variables *var);
void	func_rr(s_variables *var);
void	func_rb(s_variables *var);
void	func_ra(s_variables *var);
void	func_sa(s_variables *var);
void	func_sb(s_variables *var);

//LINKEDS
linked_lst *init_list();
linked_lst 	*new_node(int num);
void		lstadd_back(linked_lst **lst, linked_lst *new);
linked_lst	*lstlast(linked_lst *lst);
int 		add_info_linked(s_variables *var, int argc, char **argv);

//PUSHSWAP
void 	push_swap(s_variables *var, int argc, char **argv);

//ALGORITHM 1
int		mid_point_a(s_variables *var, int mid_point, int chunk);
void	algorithm_1(s_variables *var, int chunk);

//FREE INFO
void	free_linkeds(linked_lst *lst);
void	free_info(s_variables *var);

//UTILS
	
	//UTILS
	int	many_sorted(linked_lst *lst, bool incr);
	int	ft_lstsize(t_list *lst);
	int	lst_in_order(linked_lst **lst);
	linked_lst *lst_lower(linked_lst **lst);
	linked_lst *lst_bigger(linked_lst **lst);
	int	lst_pos(linked_lst **lst, linked_lst *node);
	linked_lst *lst_closer(linked_lst **lst, int mid_point);
	void	swap_nodes(linked_lst *first, linked_lst *a, linked_lst *b);
	
	//PUSH LST
	void	push_front(linked_lst **first_src, linked_lst **first_dest, linked_lst *ptr);

	//ROTATE
	void	rotate_up(linked_lst **lst);
	void	rotate_down(linked_lst **lst);

void	print_linked(linked_lst *temp);

#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:43:48 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/27 09:04:17 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include "pushswap_struct.h"
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>

//MACROS
# define ERROR_MSG "Error\n" 

//DISPLAY INFO
void			print_information(t_variables *var);

//STANDARD
t_linked_lst	*ft_lstlast(t_linked_lst *lst);

//FUNCTIONS PUSHSWAP
void			func_pa(t_variables *var);
void			func_pb(t_variables *var);
void			func_rra(t_variables *var);
void			func_rrr(t_variables *var);
void			func_rrb(t_variables *var);
void			func_rr(t_variables *var);
void			func_rb(t_variables *var);
void			func_ra(t_variables *var);
void			func_sa(t_variables *var);
void			func_sb(t_variables *var);

//LINKEDS
t_linked_lst	*new_node(int num);
void			lstadd_back(t_linked_lst **lst, t_linked_lst *new);
t_linked_lst	*lstlast(t_linked_lst *lst);
int				add_info_linked(t_variables *var, int argc, char **argv);

//PUSHSWAP
void			push_swap(t_variables *var, int argc, char **argv);

//ALGORITHM 1
int				mid_point_a(t_variables *var, int mid_point, int chunk);
void			algorithm_1(t_variables *var, int chunk);

//ALGORITHM 2
void			algorithm_2(t_variables *var, int chunk);

//FREE INFO
void			free_linkeds(t_linked_lst *lst);
void			free_info(t_variables *var);

//UTILS
int				many_sorted(t_linked_lst *lst, bool incr);
int				lst_in_order(t_linked_lst **lst);
t_linked_lst	*lst_lower(t_linked_lst **lst);
t_linked_lst	*lst_bigger(t_linked_lst **lst);
int				lst_pos(t_linked_lst **lst, t_linked_lst *node);
t_linked_lst	*lst_closer(t_linked_lst **lst, int mid_point);
void			swap_nodes(t_linked_lst *first, t_linked_lst *a,
					t_linked_lst *b);

//PUSH LST
void			push_front(t_linked_lst **first_src, t_linked_lst **first_dest,
					t_linked_lst *ptr);

//ROTATE
void			rotate_up(t_linked_lst **lst);
void			rotate_down(t_linked_lst **lst);

void			print_linked(t_linked_lst *temp);

#endif

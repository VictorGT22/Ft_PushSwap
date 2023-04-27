/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 08:38:54 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/27 08:56:51 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSHSWAP_STRUCT_H
# define PUSHSWAP_STRUCT_H

typedef struct linked_lst
{
	int					num;
	int					chunk;
	struct linked_lst	*next;
	struct linked_lst	*prev;
}	t_linked_lst;

typedef struct t_variables
{
	t_linked_lst	*lst_a;
	t_linked_lst	*lst_b;
	int				lst_a_len;
	int				lst_b_len;
}	t_variables;

#endif
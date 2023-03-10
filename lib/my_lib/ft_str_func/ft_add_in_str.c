/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_in_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:46:51 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/10 08:14:16 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	str[i] = c;
}

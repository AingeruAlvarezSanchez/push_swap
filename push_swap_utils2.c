/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:08:31 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/19 18:08:49 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_biggest_pos(t_list *lst)
{
	int		biggest;

	biggest = lst->pos;
	while (lst)
	{
		if (biggest < lst->pos)
			biggest = lst->pos;
		lst = lst->next;
	}
	return (biggest);
}

int	ft_big_binary(t_list *head_a)
{
	int	iteration;
	int	biggest;

	biggest = ft_biggest_pos(head_a);
	iteration = 0;
	while (biggest)
	{
		biggest >>= 1;
		iteration++;
	}
	return (iteration);
}

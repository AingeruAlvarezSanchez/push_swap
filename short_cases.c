/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:55:29 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/12 17:24:01 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_four_or_less(t_list **head_a, t_list **head_b, int c, int small)
{
	if (c == 3)
		ft_three_cases(head_a);
	else if (c == 4)
	{
		while ((*head_a)->content != small)
			ft_rotate_a(head_a, 0);
		ft_push_b(head_a, head_b);
		ft_three_cases(head_a);
		ft_push_a(head_a, head_b);
	}
}

void	ft_five_numbers(t_list **head_a, t_list **head_b, int c, int small)
{
	while (c != 3)
	{
		if (ft_check_best_option(*head_a, c, small) == 0)
			ft_rotate_a(head_a, 0);
		else if (ft_check_best_option(*head_a, c, small) == 1)
			ft_rrotate_a(head_a, 0);
		if ((*head_a)->content == small)
			ft_push_b(head_a, head_b);
		small = ft_lstsmallest(*head_a);
		c = ft_lstlast_count(*head_a);
	}
	ft_three_cases(head_a);
	ft_push_a(head_a, head_b);
	ft_push_a(head_a, head_b);
}

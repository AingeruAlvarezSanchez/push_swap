/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:43:58 by aalvarez          #+#    #+#             */
/*   Updated: 2021/10/01 18:38:57 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate_a(t_list **head_a, int check)
{
	t_list	*pivot;
	t_list	*pivot2;

	pivot = ft_lstlast(*head_a);
	pivot2 = *head_a;
	while (pivot2->next->next)
		pivot2 = pivot2->next;
	ft_lstadd_front(head_a, pivot);
	pivot2->next = NULL;
	if (check == 0)
		write(1, "rra\n", 4);
}

void	ft_rrotate_b(t_list **head_b, int check)
{
	t_list	*pivot;
	t_list	*pivot2;

	pivot = ft_lstlast(*head_b);
	pivot2 = *head_b;
	while (pivot2->next->next)
		pivot2 = pivot2->next;
	ft_lstadd_front(head_b, pivot);
	pivot2->next = NULL;
	if (check == 0)
		write(1, "rra\n", 4);
}

void	ft_rrotate_ab(t_list **head_a, t_list **head_b)
{
	ft_rrotate_a(head_a, 1);
	ft_rrotate_b(head_b, 1);
	write(1, "rrr\n", 4);
}

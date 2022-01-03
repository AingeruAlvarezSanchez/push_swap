/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:19:11 by aalvarez          #+#    #+#             */
/*   Updated: 2021/09/30 18:30:57 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **head_a, int check)
{
	t_list	*new_tail;

	new_tail = (ft_lstlast(*head_a));
	new_tail->next = *head_a;
	*head_a = (*head_a)->next;
	new_tail->next->next = NULL;
	if (check == 0)
		write(1, "ra\n", 3);
}

void	ft_rotate_b(t_list **head_b, int check)
{
	t_list	*new_tail;

	new_tail = (ft_lstlast(*head_b));
	new_tail->next = *head_b;
	*head_b = (*head_b)->next;
	new_tail->next->next = NULL;
	if (check == 0)
		write(1, "rb\n", 3);
}

void	ft_rotate_ab(t_list **head_a, t_list **head_b)
{
	ft_rotate_a(head_a, 1);
	ft_rotate_b(head_b, 1);
	write(1, "rr\n", 3);
}

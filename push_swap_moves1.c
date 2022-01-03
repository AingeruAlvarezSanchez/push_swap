/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:20:43 by aalvarez          #+#    #+#             */
/*   Updated: 2021/10/01 14:39:19 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **head_a, int check)
{
	t_list	*pivot;

	pivot = (*head_a)->next;
	if (!(*head_a)->content || !pivot->content)
		return ;
	(*head_a)->next = pivot->next;
	ft_lstadd_front(head_a, pivot);
	if (check == 0)
		write(1, "sa\n", 3);
}

void	ft_swap_b(t_list **head_b, int check)
{
	t_list	*pivot;

	pivot = (*head_b)->next;
	if (!(*head_b)->content || !pivot->content)
		return ;
	(*head_b)->next = pivot->next;
	ft_lstadd_front(head_b, pivot);
	if (check == 0)
		write(1, "sb\n", 3);
}

void	ft_swap_ab(t_list **head_a, t_list **head_b)
{
	ft_swap_a(head_a, 1);
	ft_swap_b(head_b, 1);
	write(1, "ss\n", 3);
}

void	ft_push_a(t_list **head_a, t_list **head_b)
{
	t_list	*pivot;
	t_list	*new_b;

	pivot = *head_b;
	new_b = NULL;
	if (!pivot->content)
		return ;
	new_b = pivot->next;
	ft_lstadd_front(head_a, pivot);
	*head_b = new_b;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_list **head_a, t_list **head_b)
{
	t_list	*pivot;
	t_list	*new_a;

	pivot = *head_a;
	if (!pivot->content)
		return ;
	new_a = pivot->next;
	ft_lstadd_front(head_b, pivot);
	*head_a = new_a;
	write(1, "pb\n", 3);
}
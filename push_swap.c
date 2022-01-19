/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:52:46 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/19 16:31:21 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstfind_pos(t_list *lst, int number)
{
	t_list	*aux;
	int		i;

	aux = lst;
	i = 0;
	while (aux)
	{
		if (aux->content == number)
			return (i);
		i++;
		aux = aux->next;
	}
	return (i);
}

void	ft_check_bits(t_list **head_a, t_list **head_b, int bitpos)
{
	t_list	*aux;
	int		iterations;
	int		i;

	iterations = ft_lstlast_count(*head_a);
	i = 0;
	aux = *head_a;
	while (i < iterations)
	{
		if (aux->pos & (1 << bitpos))
			ft_rotate_a(head_a, 0);
		else
			ft_push_b(head_a, head_b);
		aux = *head_a;
		i++;
	}
}

void	ft_back_to_a(t_list **head_a, t_list **head_b)
{
	t_list	*aux;
	int		i;
	int		iterations;

	iterations = ft_lstlast_count(*head_b);
	i = 0;
	aux = *head_b;
	while (i < iterations)
	{
		ft_push_a(head_a, head_b);
		aux = *head_b;
		i++;
	}
}

void	ft_radix(t_list **head_a, t_list **head_b, int small, int c)
{
	int	count;
	int	i;
	int	iterations;
	int	bitpos;

	ft_give_pos(*head_a, small);
	count = ft_big_binary(count, *head_a);
	bitpos = 0;
	iterations = ft_lstlast_count(*head_a);
	i = 0;
	while (count--)
	{
		ft_check_bits(head_a, head_b, bitpos);
		ft_back_to_a(head_a, head_b);
		bitpos++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	int		smallest;
	int		count;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		exit (1);
	head_a = ft_get_args(argc, argv, head_a);
	ft_norepeat(head_a);
	ft_already_sorted(head_a);
	smallest = ft_lstsmallest(head_a);
	count = ft_lstlast_count(head_a);
	ft_five_or_less(&head_a, &head_b, smallest, count);
	///////////////////////ft_radix(&head_a, &head_b, smallest, count);
	free (head_b);
	return (0);
}

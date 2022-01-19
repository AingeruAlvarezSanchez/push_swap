/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:07:50 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/19 18:08:16 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_list	*ft_newnode(t_list *head_a, intptr_t num)
{
	t_list	*new;

	new = NULL;
	new = ft_lstnew(num);
	ft_lstadd_back(&head_a, new);
	return (head_a);
}

t_list	*ft_get_args(int argc, char **argv, t_list *head_a)
{
	int		i;
	char	**str;

	i = 1;
	if (argc != 2)
	{
		ft_nonum(argv);
		while (i < argc)
			head_a = ft_newnode(head_a, ft_atoi(argv[i++]));
	}
	else
	{
		str = ft_split(argv[i], 32);
		ft_nonum(str);
		i = 0;
		while (str[i])
		{
			head_a = ft_newnode(head_a, ft_atoi(str[i++]));
		}
		while (i != 0)
			free (str[--i]);
		free (str);
	}
	return (head_a);
}

int	ft_refind_small(t_list *head_a, int small)
{
	t_list	*aux2;

	aux2 = head_a;
	small = INT_MAX;
	while (aux2)
	{
		if (small > aux2->content && aux2->checked != 1)
			small = aux2->content;
		aux2 = aux2->next;
	}
	return (small);
}

void	ft_initialize_checked(t_list *head_a)
{
	t_list	*aux;

	aux = head_a;
	while (aux)
	{
		aux->checked = 0;
		aux = aux->next;
	}
}

void	ft_give_pos(t_list *head_a, int small)
{
	int		i;
	t_list	*aux;

	aux = head_a;
	i = 0;
	ft_initialize_checked(head_a);
	while (aux)
	{
		if (aux->content == small && aux->checked == 0)
		{
			aux->checked = 1;
			aux->pos = i++;
			small = ft_refind_small(head_a, small);
			aux = head_a;
			continue ;
		}
		aux = aux->next;
	}
}

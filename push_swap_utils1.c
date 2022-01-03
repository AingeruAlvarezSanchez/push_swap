/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:11:16 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/03 13:22:46 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_newnode(t_list *head_a, intptr_t num)
{
	t_list	*new;

	new = NULL;
	new = ft_lstnew((void *)num);
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
			head_a = ft_newnode(head_a, ft_atoi(str[i++]));
		while (i != 0)
			free (str[--i]);
		free (str);
	}
	return (head_a);
}
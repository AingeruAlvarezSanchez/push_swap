/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:14:21 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/10 18:36:22 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	ft_nonum(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i][j] == '.')
		i++;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == '-' || str[i][j] == '+')
				j++;
			if (!ft_isdigit(str[i][j]))
			{
				write(1, "Error\n", 6);
				exit (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_norepeat(t_list *head_a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = head_a->next;
	tmp2 = head_a;
	while (tmp1)
	{
		while (tmp2 != tmp1)
		{
			if (tmp2->content == tmp1->content)
			{
				write(1, "Error\n", 6);
				exit (1);
			}
			tmp2 = tmp2->next;
		}
		tmp2 = head_a;
		tmp1 = tmp1->next;
	}
}

void	ft_already_sorted(t_list *head_a)
{
	t_list	*temp;

	temp = head_a;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return ;
		temp = temp->next;
	}
	exit (0);
}

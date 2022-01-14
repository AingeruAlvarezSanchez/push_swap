/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_best_option.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:50:47 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/12 17:11:48 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_best_option(t_list *lst, int count, int smallest)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->content == smallest)
		{
			if (i < (count / 2))
				return (0);
			else
				return (1);
		}
		lst = lst->next;
		i++;
	}
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:22:18 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/15 12:22:56 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstbiggest(t_list *lst)
{
	int	smallest;

	smallest = lst->content;
	if (!lst)
		return (0);
	while (lst)
	{
		if (smallest < lst->content)
			smallest = lst->content;
		lst = lst->next;
	}
	return (smallest);
}
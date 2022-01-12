/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsmallest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:07:10 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/12 16:46:50 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsmallest(t_list *lst)
{
	int	smallest;

	smallest = lst->content;
	if (!lst)
		return (0);
	while (lst)
	{
		if (smallest > lst->content)
			smallest = lst->content;
		lst = lst->next;
	}
	return (smallest);
}

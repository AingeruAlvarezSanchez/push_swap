/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbiggest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:22:18 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/19 15:26:46 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstbiggest(t_list *lst)
{
	int	biggest;

	biggest = lst->content;
	if (!lst)
		return (0);
	while (lst)
	{
		if (biggest < lst->content)
			biggest = lst->content;
		lst = lst->next;
	}
	return (biggest);
}

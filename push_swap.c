/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:48:19 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/10 18:06:46by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/*void ft_imprimir(t_list *head_a, t_list *head_b)
{
    int i;

    i = 1;
    printf("\n\n            ///////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t       A       \t       B       \n");
    printf("\t|-------------|\t|-------------|\n");
    while (head_a || head_b)
    {
        if ( head_b && !head_a)
            printf("%d   \t|             |\t| %11d |\n", i, (int)head_b->content);
        else if (head_a && !head_b)
            printf("%d   \t| %11d |\t|             |\n", i, (int)head_a->content);
        else
            printf("%d   \t| %11d |\t| %11d |\n", i, (int)head_a->content, (int)head_b->content);
        if ( head_a != NULL)
            head_a = head_a->next;
        if (head_b != NULL)
            head_b = head_b->next;
        i++;
    }
    printf("\t|-------------|\t|-------------|\n");
}*/

int	ft_efficiency(t_list **head_a, int pivot)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = *head_a;
	while (temp)
	{
		if ((int)temp->content == pivot)
			return (count);
		temp = temp->next;
		count++;
	}
	return (0);
}

int	ft_smallest(t_list **head_a)
{
	t_list	*tmp;
	int		num;

	tmp = *head_a;
	num = INT_MAX;
	while (tmp)
	{
		if ((int)tmp->content < num)
			num = (int)tmp->content;
		tmp = tmp->next;
	}
	return (num);
}

void	ft_less_short(t_list **head_a, t_list **head_b)
{
	t_list	*check;
	int		pivot;
	int		count;

	check = *head_a;
	pivot = ft_smallest(head_a);
	count = ft_efficiency(head_a, pivot) + 1;
	if ((ft_lstsize(*head_a) / 2) < count)
	{
		while ((int)(*head_a)->content != pivot)
		{
			ft_rrotate_a(head_a, 0/*, head_b*/);
		}
	}
	else if ((ft_lstsize(*head_a) / 2) >= count)
	{
		while ((int)(*head_a)->content != pivot)
		{
			ft_rotate_a(head_a, 0/*, head_b*/);
		}
	}
	ft_push_b(head_a, head_b);
	if (ft_lstsize(*head_a) > 3)
		ft_less_short(head_a, head_b);
}

void	ft_short_cases(t_list **head_a/*, t_list **head_b*/)
{
	if (((*head_a)->content < (*head_a)->next->content)
		&& ((*head_a)->next->content > (*head_a)->next->next->content)
		&& ((*head_a)->content > (*head_a)->next->next->content))
			ft_rrotate_a(head_a, 0/*, head_b*/);
	else if (((*head_a)->content > (*head_a)->next->content)
		&& ((*head_a)->next->content < (*head_a)->next->next->content))
		{		
			if (((*head_a)->content) > ((*head_a)->next->next->content))
				ft_rotate_a(head_a, 0/*, head_b*/);
			else
				ft_swap_a(head_a, 0/*, head_b*/);
		}
	else if (((*head_a)->content > (*head_a)->next->content)
		&& ((*head_a)->next->content > (*head_a)->next->next->content)
		&& (*head_a)->content > (*head_a)->next->next->content)
		{
			ft_swap_a(head_a, 0/*, head_b*/);
			ft_rrotate_a(head_a, 0/*, head_b*/);
		}
	else if (((*head_a)->content < (*head_a)->next->content)
		&& ((*head_a)->next->content > (*head_a)->next->next->content)
		&& (*head_a)->content < (*head_a)->next->next->content)
		{
			ft_rrotate_a(head_a, 0/*, head_b*/);
			ft_swap_a(head_a, 0/*, head_b*/);
		}
}

void	ft_find_pivot(t_list **head_a, t_list **head_b)
{
	t_list	*pivot;
	int		center;
	int		count;

	count = -1;
	center = ft_lstsize(*head_a);
	pivot = *head_a;
	if (center == 3)
		ft_short_cases(head_a/*, head_b*/);
	if (center % 2 != 0)
		center++;
	center /= 2;
	while (++count < center - 1)
		pivot = pivot->next;
	if (center > 2 && center < 5)
	{
		ft_less_short(head_a, head_b);
		ft_short_cases(head_a/*, head_b*/);
		while (ft_lstsize(*head_b))
			ft_push_a(head_a, head_b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		exit (1);
	head_a = ft_get_args(argc, argv, head_a);
	ft_norepeat(head_a);
	ft_already_sorted(head_a);
	ft_find_pivot(&head_a, &head_b);
	free (head_b);
	//system("leaks push_swap");
	return (0);
}

//ft_swap_a(&head_a, 0);
//ft_swap_b(&head_b, 0);
//ft_swap_ab(&head_a, &head_b);
//ft_push_a(&head_a, &head_b);
//ft_push_b(&head_a, &head_b);
//ft_rotate_a(&head_a, 0);
//ft_rotate_b(&head_b, 0);
//ft_rotate_ab(&head_a, &head_b);
//ft_rrotate_a(&head_a, 0);
//ft_rrotate_b(&head_b, 0);
//ft_rrotate_ab(&head_a, &head_b);

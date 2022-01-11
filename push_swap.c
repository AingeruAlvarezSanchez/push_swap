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

void	ft_five_short(t_list **head_a, t_list **head_b)
{
	int	smallest;
	int	count;
	t_list	*aux;

	count = ft_lstlast_count(*head_a);
	smallest = ft_lstsmallest(*head_a);
	aux = *head_a;
	if (count == 3)
		ft_short_cases(head_a);
	else if (count == 4)
	{
		while ((*head_a)->content != smallest)
			ft_rotate_a(head_a, 0);
		ft_push_b(head_a, head_b);
		ft_short_cases(head_a);
		ft_push_a(head_a, head_b);
	}
	else if (count == 5)
	{
		while (count != 3)
		{
			ft_rotate_a(head_a, 0);
			if ((*head_a)->content == smallest)
				ft_push_b(head_a, head_b);
			smallest = ft_lstsmallest(*head_a);
			count = ft_lstlast_count(*head_a);
		}
		ft_short_cases(head_a);
		ft_push_a(head_a, head_b);
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
	ft_five_short(&head_a, &head_b);
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

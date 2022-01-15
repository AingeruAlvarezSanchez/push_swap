/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:52:46 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/13 16:10:12 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
void	ft_radix(t_list **head_a, t_list **head_b, int small, int c)
{
	t_list	*aux;

	aux = *head_a;
	ft_give_pos(*head_a, small);
	while (aux)
	{
		aux->pos = ft_num_to_binary(aux->pos);
		aux = aux->next;
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
	ft_radix(&head_a, &head_b, smallest, count);
	free (head_b);
	//system("leaks push_swap");
	return (0);
}

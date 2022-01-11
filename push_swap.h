/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:29:57 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/11 16:22:05 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdio.h>
# include	"./libft/libft.h"

t_list	*ft_get_args(int argc, char **argv, t_list *head_a);
t_list	*ft_newnode(t_list *head_a, intptr_t num);
void	ft_nonum(char **str);
void	ft_norepeat(t_list *head_a);
void	ft_already_sorted(t_list *head_a);
void	ft_limits(t_list *head_a);
void	ft_swap_a(t_list **head_a, int check/*, t_list **head_b*/);
void	ft_swap_b(t_list **head_b, int check/*, t_list **head_a*/);
void	ft_swap_ab(t_list **head_a, t_list **head_b);
void	ft_push_a(t_list **head_a, t_list **head_b);
void	ft_push_b(t_list **head_a, t_list **head_b);
void	ft_rotate_a(t_list **head_a, int check/*, t_list **head_b*/);
void	ft_rotate_b(t_list **head_b, int check/*, t_list **head_a*/);
void	ft_rotate_ab(t_list **head_a, t_list **head_b);
void	ft_rrotate_a(t_list **head_a, int check/*, t_list **head_b*/);
void	ft_rrotate_b(t_list **head_b, int check/*, t_list **head_a*/);
void	ft_rrotate_ab(t_list **head_a, t_list **head_b);
void ft_imprimir(t_list *head_a, t_list *head_b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:07:09 by aalvarez          #+#    #+#             */
/*   Updated: 2022/01/19 11:29:45 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list {
	int				content;
	int				pos;
	int				checked;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstlast_count(t_list *lst);
int		ft_lstsmallest(t_list *lst);
int		ft_lstbiggest(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_check_best_option(t_list *lst, int count, int smallest);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_num_to_binary(int num);

#endif

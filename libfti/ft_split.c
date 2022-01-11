/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42Urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:42:00 by aalvarez          #+#    #+#             */
/*   Updated: 2021/06/10 12:56:12 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **result)
{
	unsigned int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static unsigned int	ft_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	words;

	if (!s[0])
		return (0);
	i = 0;
	words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		words++;
	return (words);
}

static void	ft_chopchop(char **n_str, unsigned int *str_len, char c)
{
	unsigned int	i;

	*n_str += *str_len;
	*str_len = 0;
	i = 0;
	while (**n_str && **n_str == c)
		(*n_str)++;
	while ((*n_str)[i])
	{
		if ((*n_str)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	char			*n_str;
	unsigned int	str_len;
	unsigned int	i;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	n_str = (char *)s;
	str_len = 0;
	while (i < ft_words(s, c))
	{
		ft_chopchop(&n_str, &str_len, c);
		result[i] = (char *)malloc(sizeof(char) * (str_len + 1));
		if (!result[i])
			return (ft_free(result));
		ft_strlcpy(result[i], n_str, str_len + 1);
		i++;
	}
	result[i] = NULL;
	return (result);
}

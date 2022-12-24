/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:05:10 by hrinka            #+#    #+#             */
/*   Updated: 2022/12/01 18:35:58 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_words(char	const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] != c)
				i++;
			n++;
		}
	}
	return (n);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

void	*ft_freeall(char **list, size_t len)
{
	size_t	j;

	j = 0;
	while (j < len)
	{
		free(list[j]);
		j++;
	}
	free(list);
	return (NULL);
}

size_t	ft_setchar(char *dst, const char **src, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = word_len(*src, c);
	while ((*src)[i] != '\0' && (*src)[i] != c)
	{
		*dst = (*src)[i];
		dst++;
		i++;
	}
	*dst = '\0';
	*src += (len);
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	size_t		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc((num_words(s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s != '\0' && *s != c)
		{
			tab[j] = (char *)malloc((word_len(s, c) + 1) * sizeof(char));
			if (tab[j] == NULL)
				return (ft_freeall(tab, j));
			ft_setchar(tab[j], &s, c);
			j++;
		}
		else
			s++;
	}
	tab[j] = NULL;
	return (tab);
}

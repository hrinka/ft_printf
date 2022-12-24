/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:53:02 by hrinka            #+#    #+#             */
/*   Updated: 2022/12/01 15:41:30 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	rear;
	char	*str;

	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	front = 0;
	rear = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (s1[rear - 1] && ft_strchr(set, s1[rear - 1]) && rear > front)
		rear--;
	str = (char *) malloc (sizeof(char) *(rear - front + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s1[front], rear - front + 1);
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strtrim("abqbc","abc"));
// 	printf("%s\n", ft_strtrim("xgshegdhayz", "xyz"));
// }

// {
// 	size_t	i;
// 	size_t	len;
// 	char	*str;

// 	if (!s1 || !set)
// 		return (NULL);

// 	i = 0;
// 	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
// 		i++;
// 	len = ft_strlen(s1 + 1);
// 	while (ft_strchr(set, s1 [i + len]))
// 		len--;
// 	if (!(str = ft_substr (s1, i, len +1)))
// 		return (NULL);
// 	return (str);
// }

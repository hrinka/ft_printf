/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:44:05 by hrinka            #+#    #+#             */
/*   Updated: 2022/11/10 17:20:10 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*((unsigned char *)s1) != *((unsigned char *)s2))
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1++;
		s2++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*str1 = "abcyefgh";
// 	char	*str2 = "abcdefgj";
// 	int	n;

// 	n = 10;
// 	printf("%d\n", memcmp(str1, str2, n));
// 	printf("%d\n", ft_memcmp(str1, str2, n));
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:40:21 by hrinka            #+#    #+#             */
/*   Updated: 2022/12/01 21:49:35 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i])
		i++;
	while ((i + j + 1) < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j + 1 < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

// #include <string.h>
// #include <stdio.h>
// int    main()
// {
//     char    dest[30] = "abcde";
//     char    ft_dest[30] = "abcde";
//     char    *src;

//     src = "1234567890123456";
//     printf("  strlcat: %s,%lu\n", dest, strlcat(dest, src,20));
//     printf("ft_strlcat: %s,%zu\n", ft_dest, ft_strlcat(ft_dest, src, 20));
// }

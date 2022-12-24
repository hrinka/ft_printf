/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:18:37 by hrinka            #+#    #+#             */
/*   Updated: 2022/12/01 21:41:50 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	if (dst == src)
		return (dst);
	if (d > s)
		while (len--)
			d[len] = s[len];
	else
		while (len--)
			*d++ = *s++;
	return (dst);
}

// #include <stdio.h>
// int main (void)
// {
// 	char src[] = "hogehoge";
// 	char *dst = NULL;
// 	char *ret = ft_memmove(dst, src, 4);
// 	printf ("%p\n", ret);
//  }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:52:31 by hrinka            #+#    #+#             */
/*   Updated: 2022/12/24 22:07:55 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			i;

	i = ft_digit_count(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		if (n > 0)
			str[i--] = n % 10 + '0';
		else
			str[i--] = (n % 10) * -1 + '0';
		n = n / 10;
	}
	return (str);
}
// static int	ft_digit_count(int n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (n <= 0)
// 		i++;
// 	while (n != 0)
// 	{
// 		n /= 10;
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_itoa(int n)
// {
// 	char			*str;
// 	size_t			i;
// 	unsigned int	nb;

// 	nb = n;
// 	i = ft_digit_count(nb);
// 	str = (char *)malloc(sizeof(char) * (i + 1));
// 	if (!str)
// 		return (NULL);
// 	str[i] = '\0';
// 	i--;
// 	if (nb < 0)
// 	{
// 		str[0] = '-';
// 		nb = nb * -1;
// 	}
// 	else if (nb == 0)
// 		str[0] = '0';
// 	while (nb > 0)
// 	{
// 		str[i--] = nb % 10 + '0';
// 		nb = nb / 10;
// 	}
// 	return (str);
// }

// #include <stdio.h>
// int	main(void)
// {
// 	int n1 = 0;
// 	int n2 = 2147483647;
// 	int n3 = -2147483648;
// 	int n4 = 2147483646;
// 	int n5 = -2147483647;
// 	/* 1 */ printf("%s\n", ft_itoa(n1));
// 	/* 13. INT_MAX */ printf("%s\n", ft_itoa(n2));
// 	/* 14. INT_MIN */ printf("%s\n", ft_itoa(n3));
// 	/* 15. INT_MAX - 1 */ printf("%s\n", ft_itoa(n4));
// 	/* 16. INT_MIN + 1 */ printf("%s\n", ft_itoa(n5));
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:57:21 by hrinka            #+#    #+#             */
/*   Updated: 2022/12/24 14:18:23 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u;

	u = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		u = -n;
	}
	if (u >= 10)
		ft_putnbr_fd(u / 10, fd);
	ft_putchar_fd(u % 10 + '0', fd);
}

// #include <fcntl.h>
// #include <limits.h>
// #include <stdio.h>
// #include <sys/stat.h>
// #include <sys/types.h>

// int  main(void)
// {
//     int fd;
//     int i = -2147483648;
//     //  fd = 1;
//     fd = 1;
//     ft_putnbr_fd(i, fd);
//     return (0);
// }

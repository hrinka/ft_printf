/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:25:22 by hrinka            #+#    #+#             */
/*   Updated: 2022/12/20 12:39:31 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char fmt)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, fmt);
		ft_put_hex(num % 16, fmt);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (fmt == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (fmt == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char fmt)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, fmt);
	return (ft_hex_len(num));
}

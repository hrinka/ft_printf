/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:25:44 by hrinka            #+#    #+#             */
/*   Updated: 2022/12/24 20:01:19 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_fmts(va_list args, const char fmt)
{
	int	print_length;

	print_length = 0;
	if (fmt == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (fmt == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (fmt == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (fmt == 'd' || fmt == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (fmt == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), fmt);
	else if (fmt == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_fmts(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

#include "stdio.h"

int	main(void)
{
	printf(" %c %c %c ", '0', 0, '1');
	ft_printf(" %c %c %c ", '0', 0, '1');
}

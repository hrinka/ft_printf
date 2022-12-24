/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrinka <hrinka@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:25:44 by hrinka            #+#    #+#             */
/*   Updated: 2022/12/24 22:09:33 by hrinka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_fmts(va_list *args, const char fmt)
{
	int	print_length;

	print_length = 0;
	if (fmt == 'c')
		print_length += ft_printchar(va_arg(*args, int));
	else if (fmt == 's')
		print_length += ft_printstr(va_arg(*args, char *));
	else if (fmt == 'p')
		print_length += ft_print_ptr(va_arg(*args, unsigned long long));
	else if (fmt == 'd' || fmt == 'i')
		print_length += ft_printnbr(va_arg(*args, int));
	else if (fmt == 'u')
		print_length += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		print_length += ft_print_hex(va_arg(*args, unsigned int), fmt);
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
			print_length += ft_fmts(&args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
		if (print_length >= INT_MAX)
		{
			va_end(args);
			return (-1);
		}
	}
	va_end(args);
	return (print_length);
}

// #include "stdio.h"
// int	main(void)
// {
// 	int	i;
// 	i = 0;
// 	printf("#c\n");
// 	ft_printf("%c\t%c\n", 'c', '%');
// 	printf("%c\t%c\n\n", 'c', '%');

// 	printf("#str\n");
// 	ft_printf("%s\t%s\t%s\n", "42Tokyo", "", NULL);
// 	printf("%s\t%s\n\n", "42Tokyo", "");

// 	printf("#int\n");
// 	ft_printf("%d\t%d\t%d\t%d\n", i, 100, INT_MAX, INT_MIN);
// 	printf("%d\t%d\t%d\t%d\n\n", i, 100, INT_MAX, INT_MIN);

// 	printf("#uint\n");
// 	ft_printf("%u\t%u\t%u\n", i, 100, UINT_MAX);
// 	printf("%u\t%u\t%u\n\n", i, 100, UINT_MAX);

// 	printf("#hex\n");
// 	printf("%x\t%x\t%x\n", i, 255, UINT_MAX);
// 	printf("%x\t%x\t%x\n\n", i, 255, UINT_MAX);

// 	printf("#HEX\n");
// 	printf("%x\t%X\t%X\n", i, 255, UINT_MAX);
// 	printf("%x\t%X\t%X\n\n", i, 255, UINT_MAX);

// 	printf("#ptr\n");
// 	ft_printf("%p\t%p\t%p\t%p\n", &i, SIZE_MAX, NULL, 0);
// 	printf("%p\t%p\n\n", &i, NULL);

// 	printf("#percent\n");
// 	ft_printf("%%\n");
// 	printf("%%\n\n");

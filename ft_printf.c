/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbustos- <jbustos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 12:51:47 by jbustos-          #+#    #+#             */
/*   Updated: 2026/10/05 16:35:58 by jbustos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	print_int(int value)
{
	char	*valuenum;
	int		t;

	if (!value)
	{
		ft_putchar_return('0');
		return (1);
	}
	valuenum = ft_itoa((int)(uintptr_t)value);
	t = ft_strlen(valuenum);
	putstrcount(valuenum);
	free(valuenum);
	return (t);
}

static int	print_char(int value)
{
	char	valuec;

	valuec = (char)(uintptr_t)value;
	ft_putchar_return(valuec);
	return (1);
}

static int	print_ptr(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (putstrcount("(nil)"));
	count = ft_putchar_return('0');
	count += ft_putchar_return('x');
	count += print_hex('x', ptr);
	return (count);
}

static int	condition(va_list arg, char format)
{
	int	t;

	t = 0;
	if (format == 'c')
		t += print_char(va_arg(arg, int));
	else if (format == 's')
		t += putstrcount(va_arg(arg, char *));
	else if (format == 'p')
		t += print_ptr(va_arg(arg, unsigned long long));
	else if (format == 'd' || format == 'i')
		t += print_int(va_arg(arg, int));
	else if (format == 'u')
		t += print_unsigned(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		t += print_hex(format, va_arg(arg, unsigned int));
	else if (format == '%')
		t += write(1, "%", 1);
	return (t);
}

int	ft_printf(char const *format, ...)
{
	va_list	arg;
	int		count;
	int		t;

	t = 0;
	count = 0;
	va_start(arg, format);
	while (format[count] != '\0')
	{
		if (format[count] == '%')
		{
			count++;
			t += condition(arg, format[count]);
		}
		else
		{
			write(1, &format[count], 1);
			t++;
		}
		count++;
	}
	va_end(arg);
	return (t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbustos- <jbustos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 15:11:07 by jbustos-          #+#    #+#             */
/*   Updated: 2026/10/05 16:41:57 by jbustos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(char format, unsigned long value)
{
	int		count;
	char	*hex;

	count = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (value >= 16)
		count += print_hex(format, value / 16);
	count += write(1, &hex[value % 16], 1);
	return (count);
}

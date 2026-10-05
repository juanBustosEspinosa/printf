/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbustos- <jbustos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 15:06:01 by jbustos-          #+#    #+#             */
/*   Updated: 2026/10/05 16:36:27 by jbustos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int value)
{
	int		count;
	char	c;

	count = 0;
	if (value >= 10)
		count += print_unsigned(value / 10);
	c = (value % 10) + '0';
	count += ft_putchar_return(c);
	return (count);
}

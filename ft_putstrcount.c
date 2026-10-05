/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbustos- <jbustos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 15:08:09 by jbustos-          #+#    #+#             */
/*   Updated: 2026/10/05 16:35:03 by jbustos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstrcount(char *str)
{
	int		count;
	char	*null;

	null = "(null)";
	count = 0;
	if (!str)
	{
		while (null[count] != '\0')
		{
			ft_putchar_return(null[count]);
			count++;
		}
		return (6);
	}
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

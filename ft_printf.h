/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbustos- <jbustos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 12:49:40 by jbustos-          #+#    #+#             */
/*   Updated: 2026/10/05 16:41:26 by jbustos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_printf(char const *format, ...);
int		ft_strlen(const char *c);
char	*ft_itoa(int n);
int		putstrcount(char *str);
int		print_unsigned(unsigned int value);
int		print_hex(char format, unsigned long value);
int		ft_putcharReturn(char numero);

#endif
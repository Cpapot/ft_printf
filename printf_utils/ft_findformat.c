/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:44:54 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/23 19:02:10 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

ssize_t	ft_skipword(char const *format, int index)
{
	int		wordsize;
	ssize_t	len;
	char	*word;

	wordsize = 0;
	while (format[index] != '%' && format[index] != '\0')
	{
		index++;
		wordsize++;
	}
	if (wordsize != 0)
	{
		word = ft_substr(format, index - wordsize, wordsize);
		if (!word)
			return (-1);
		len = ft_putstr_len(word);
		free (word);
		return (len);
	}
	return (0);
}

static ssize_t	ft_findformat(char const *format, int index, va_list variadic)
{
	ssize_t	len;

	len = 0;
	index++;
	if (format[index] == 'c')
		return (ft_putchar_len(va_arg(variadic, int)));
	if (format[index] == 's')
		return (ft_putstr_len(va_arg(variadic, char *)));
	if (format[index] == 'p')
		return (ft_puthexavoid_len(va_arg(variadic, void *)));
	if (format[index] == 'd')
		return (ft_putint_len(va_arg(variadic, int)));
	if (format[index] == 'i')
		return (ft_putint_len(va_arg(variadic, int)));
	if (format[index] == 'u')
		return (ft_putunsint_len(va_arg(variadic, unsigned int)));
	if (format[index] == 'x')
		return (ft_puthexamin_len(va_arg(variadic, unsigned int)));
	if (format[index] == 'X')
		return (ft_puthexamaj_len(va_arg(variadic, unsigned int)));
	if (format[index] == '%')
		return (ft_putpercent_len());
	len = ft_skipword(format, index);
	return (len);
}

ssize_t	ft_callformat(char const *format, va_list variadic)
{
	ssize_t		tmp;
	ssize_t		len;
	static int	index = 0;

	len = 0;
	index = 0;
	while (format[index] != '\0')
	{
		tmp = 0;
		tmp = ft_skipword(format, index);
		if (tmp == -1)
			return (-1);
		len = len + tmp;
		tmp = 0;
		tmp = ft_findformat(format, index, variadic);
		if (tmp == -1)
			return (-1);
		index++;
		len = len + tmp;
		index++;
	}
	return (len);
}

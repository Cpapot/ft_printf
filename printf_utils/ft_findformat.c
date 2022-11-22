/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:44:54 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/22 17:23:46 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

ssize_t	ft_callformat(char const *format)
{
	ssize_t		tmp;
	ssize_t		len;
	static int	index = 0;

	len = 0;
	while (format[index] != '\0')
	{
		tmp = 0;
		tmp = ft_skipword(format, index);
		if (tmp == -1)
			return (-1);
		len = len + tmp;
		tmp = 0;
		tmp = ft_findformat(format, index);
		if (tmp == -1)
			return (-1);
		len = len + tmp;
	}
	return (len);
}

static ssize_t	ft_findformat(char const *format, int index)
{
	ssize_t	tmp;

	tmp = 0;
	index++;
	if (format[index] == 'c')
	tmp =
	if (format[index] == 's')
	;
	if (format[index] == 'p')
	;
	if (format[index] == 'd')
	;
	if (format[index] == 'i')
	;
	if (format[index] == 'u')
	;
	if (format[index] == 'x')
	;
	if (format[index] == 'X')
	;
	if (format[index] == '%')
	;
	index++;
	return (tmp);
}

static ssize_t	ft_skipword(char const *format, int index)
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

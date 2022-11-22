/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexamaj_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:42:54 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/22 15:27:46 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_convert_hexa(long nbrl)
{
	long	buff;
	char	*base;
	ssize_t	len;

	len = 0;
	base = "0123456789ABCDEF";
	if (nbrl / ft_strlen(base) != 0)
		ft_convert_hexa(nbrl / ft_strlen(base));
	buff = nbrl % ft_strlen(base);
	len = write(1, base[buff], 1);
	if (len == -1)
		return (0);
	return (len);
}

ssize_t	ft_puthexamaj_len(int nbr)
{
	ssize_t	len;


}

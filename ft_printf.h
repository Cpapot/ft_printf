/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:49:21 by cpapot            #+#    #+#             */
/*   Updated: 2022/11/22 17:23:08 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include "libft/libft.h"

ssize_t	ft_putchar_len(char c);
ssize_t	ft_putint_len(int nbr);
ssize_t	ft_putpercent_len(void);
ssize_t	ft_putstr_len(char *str);
ssize_t	ft_putunsint_len(unsigned int nbr);
ssize_t	ft_callformat(char const *format);

#endif

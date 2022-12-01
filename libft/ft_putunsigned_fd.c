/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:44:21 by bdemetz           #+#    #+#             */
/*   Updated: 2022/11/23 13:22:49 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rcrsv_unsigned_print(unsigned int n, int fd)
{
	int		i;
	char	c;

	i = n % 10;
	c = i + 48;
	if (n < 10)
	{
		write (fd, &c, 1);
		return ;
	}
	rcrsv_unsigned_print(n / 10, fd);
	write (fd, &c, 1);
}

void	ft_putunsigned_fd(unsigned int n, int fd)
{
    rcrsv_unsigned_print(n, fd);
}

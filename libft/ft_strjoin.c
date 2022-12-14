/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:17:59 by bdemetz           #+#    #+#             */
/*   Updated: 2022/11/24 16:15:32 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	size1;
	unsigned int	size2;

	if (!s2)
		return ((char *)s1);
	if (!s1)
		return ((char *)s2);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	str = malloc ((size1 + size2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < size1)
		str[i] = s1[i];
	i--;
	while (++i - size1 < size2)
		str[i] = s2[i - size1];
	str[i] = 0;
	return (str);
}

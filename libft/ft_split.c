/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:29:13 by bdemetz           #+#    #+#             */
/*   Updated: 2022/11/22 20:32:20 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_string(char *s, int start, int end)
{
	int		i;
	char	*str;

	str = ft_calloc(end - start + 1, sizeof(char));
	if (!str)
		return (str);
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

void	create_strings(char *s, char c, char **matrix)
{
	int	i;
	int	j;
	int	k;

	j = -1;
	i = -1;
	k = 0;
	while (++i <= (int) ft_strlen(s))
	{
		if (s[i] != c && j < 0)
			j = i;
		else if ((s[i] == c || (i == (int) ft_strlen(s)
					&& s[i - 1] != c)) && j >= 0)
		{
			matrix[k++] = fill_string(s, j, i);
			j = -1;
		}
	}
	matrix[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		l;
	char	**matrix;

	if (!s)
		return (0);
	i = -1;
	l = 0;
	while (++i <= (int) ft_strlen(s))
	{
		if (i > 0 && (s[i] == c || !s[i]) && s[i - 1] != c)
			l++;
	}
	matrix = ft_calloc(l + 1, sizeof(char *));
	if (!matrix)
		return (0);
	create_strings((char *) s, c, matrix);
	return (matrix);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdemetz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:35:40 by bdemetz           #+#    #+#             */
/*   Updated: 2022/11/23 17:51:28 by bdemetz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_start(char *s1, char *set)
{
	int	i;

	i = -1;
	while (s1[++i])
		if (!ft_strchr(set, s1[i]))
			return (i);
	return (ft_strlen(s1));
}

int	get_end(char *s1, char *set)
{
	int	i;

	i = ft_strlen(s1);
	while (--i > 0)
		if (!ft_strchr(set, s1[i]))
			return (++i);
	return (0);
}

void	fill_str(char *s1, char *nstr, int start, int end)
{
	int	i;

	i = 0;
	if (end - start != 0)
		while (start < end)
			nstr[i++] = s1[start++];
	nstr[i] = 0;
}

char	*empty_str(char *str)
{
	str = ft_calloc (1, sizeof(char));
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;
	char	*new_str;
	char	*str;
	char	*sett;

	str = (char *)s1;
	sett = (char *)set;
	if (str == NULL || str[0] == 0)
		return (empty_str(str));
	if (set == NULL || set[0] == 0)
		return (ft_strdup(s1));
	start = get_start(str, sett);
	end = get_end(str, sett);
	if (end < start)
		return (empty_str(str));
	new_str = malloc (sizeof(char) * (end - start + 1));
	if (new_str == NULL)
		return (NULL);
	fill_str(str, new_str, start, end);
	return (new_str);
}

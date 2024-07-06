/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:21:37 by lteng             #+#    #+#             */
/*   Updated: 2023/09/09 13:21:40 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		i;
	int		start;
	int		end;

	start = 0;
	while (s1[start] != '\0' && char_in_set(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && char_in_set(s1[end], set) == 1)
		end--;
	new_str = malloc(sizeof(char) * (end - start + 2));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		new_str[i] = s1[start];
		start++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

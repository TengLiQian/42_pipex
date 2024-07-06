/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:37:16 by lteng             #+#    #+#             */
/*   Updated: 2024/01/11 13:57:35 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	ft_wordcount(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			s += (ft_wordlen(s, c));
			words++;
		}
		else
			s++;
	}
	return (words);
}

static void	*ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**strings;
	size_t		i;
	size_t		words;

	words = ft_wordcount(s, c);
	strings = (char **)malloc(sizeof(char *) * (words + 1));
	if (!strings || !s)
		return (NULL);
	strings[words] = NULL;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			strings[i] = ft_substr(s, 0, ft_wordlen(s, c));
			if (!strings[i])
				return (ft_free(strings));
			i++;
			s += ft_wordlen(s, c);
		}
		else
			s++;
	}
	return (strings);
}

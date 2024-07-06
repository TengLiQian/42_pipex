/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:06:15 by lteng             #+#    #+#             */
/*   Updated: 2023/09/09 11:06:18 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	i = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(i + 1);
	if (ptr == NULL)
		return (NULL);
	j = 0;
	k = 0;
	while (j < i && s1[j] != '\0')
	{
		ptr[j] = s1[j];
		j++;
	}
	while (j < i && s2[k] != '\0')
	{
		ptr[j] = s2[k];
		j++;
		k++;
	}
	ptr[j] = '\0';
	return (ptr);
}

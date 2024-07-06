/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:39:03 by lteng             #+#    #+#             */
/*   Updated: 2023/09/07 21:39:05 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	a;
	int		i;

	i = 0;
	a = (char)c;
	ptr = (char *)s;
	while (ptr[i] != '\0')
		i++;
	if (a == '\0')
		return ((char *)&ptr[i]);
	while (i > 0)
	{
		i--;
		if (ptr[i] == a)
			return ((char *)&ptr[i]);
	}
	return (NULL);
}

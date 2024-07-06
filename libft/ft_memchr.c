/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:29:41 by lteng             #+#    #+#             */
/*   Updated: 2023/09/08 11:30:08 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	value;
	size_t			i;

	ptr = (unsigned char *)s;
	value = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == value)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}

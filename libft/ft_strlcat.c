/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:11:56 by lteng             #+#    #+#             */
/*   Updated: 2023/09/07 21:11:18 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = 0;
	s_len = 0;
	while (dst[d_len] != '\0')
		d_len++;
	while (src[s_len] != '\0')
		s_len++;
	if (size <= d_len)
		return (size + s_len);
	i = 0;
	if (size > 0 && d_len < (size - 1))
	{
		while (i < (size - 1 - d_len) && src[i] != '\0')
		{
			dst[d_len + i] = src[i];
			i++;
		}
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

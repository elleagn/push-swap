/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:55:45 by gozon             #+#    #+#             */
/*   Updated: 2024/08/13 11:21:19 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Concatenate two strings. Appends src to string dst of size siz (unlike
// strncat(), siz is the full size of dst, not space left). At most siz-1
// characters will be copied. Always NULL terminates (unless siz <= strlen(dst))
// Returns
// The strlcat() function returns strlen(src) + MIN(siz, strlen(initial dst)).
// If retval >= siz, truncation occurred.
size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	dest_length;
	size_t	src_length;
	size_t	i;

	dest_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dest_length >= siz)
		return (siz + src_length);
	i = 0;
	while (i < siz - dest_length - 1 && src[i])
	{
		dst[dest_length + i] = src[i];
		i++;
	}
	dst[dest_length + i] = '\0';
	return (dest_length + src_length);
}

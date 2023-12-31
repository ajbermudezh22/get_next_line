/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albermud <albermud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:50:55 by albermud          #+#    #+#             */
/*   Updated: 2023/05/26 09:56:16 by albermud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	result;

	result = 0;
	if (s == NULL)
		return (0);
	while (s[result] != '\0')
		result++;
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
		if (s[i++] == (unsigned char)c)
			return ((char *)(s + (i - 1)));
	return ((void *)0);
}

char	*ft_strjoin(char *s1, const char *s2, size_t size)
{
	char	*result;

	result = malloc((ft_strlen(s1) + ft_strlen(s2))
			* sizeof(char) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcpy(result + ft_strlen(s1), s2, size);
	free(s1);
	return (result);
}

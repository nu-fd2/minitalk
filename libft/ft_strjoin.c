/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:47:37 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/09 12:34:18 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(sizeof(char), i);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)s1, i);
	ft_strlcat(str, (char *)s2, i);
	return (str);
}

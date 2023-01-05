/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:26:41 by fhihi             #+#    #+#             */
/*   Updated: 2022/10/09 16:45:10 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	size_t	j2;
	char	*s;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc((size) * sizeof(char ) + 1);
	if (!s)
		return (0);
	i = 0;
	j = 0;
	j2 = 0;
	while (s1[j])
		s[i++] = s1[j++];
	while (s2[j2])
		s[i++] = s2[j2++];
	s[i] = '\0';
	return (s);
}

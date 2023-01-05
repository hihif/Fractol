/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:51:50 by fhihi             #+#    #+#             */
/*   Updated: 2022/10/17 10:13:17 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*m;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (0);
	m = (void *)malloc(count * size);
	if (!m)
		return (0);
	return (ft_memset(m, 0, count * size));
}

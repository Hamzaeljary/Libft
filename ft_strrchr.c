/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:53:30 by heljary           #+#    #+#             */
/*   Updated: 2024/10/23 15:54:32 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*last;
	unsigned char	chr;

	last = NULL;
	chr = (unsigned char)c;
	while (*s)
	{
		if (*s == chr)
			last = s;
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return ((char *)last);
}

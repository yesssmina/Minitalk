/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:00:35 by sanaggar          #+#    #+#             */
/*   Updated: 2022/12/02 16:24:07 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	*((char *)ptr) = 0;
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*int	main()
{
	printf("%s\n", calloc(SIZE_MAX, SIZE_MAX));
	perror("true calloc says");
	printf("%s\n", ft_calloc(SIZE_MAX, SIZE_MAX));
}*/

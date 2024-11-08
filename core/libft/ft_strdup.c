/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:53:42 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/08 13:17:10 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *copy, const char *src)
{
	int	i;

	if (!src)
		return ;
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
}

char	*ft_strdup(const char *s)
{
	int		size;
	char	*copy;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	copy = malloc((size + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_strcpy(copy, s);
	return (copy);
}

/* int	main(int ac, char **av)
{
	char *result;

	if (ac != 2)
		return (-1);
	result = ft_strdup(av[1]);
	printf("%s \n", result);
} */
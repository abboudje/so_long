/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:05:04 by abboudje          #+#    #+#             */
/*   Updated: 2024/11/06 02:31:32 by abboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_with_error(char **map, char *error_message)
{
	free_map(map);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

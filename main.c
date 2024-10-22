/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:46:39 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/22 20:21:26 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_lib.h"
#include "struct.h"
#include <stdlib.h>
#include <unistd.h>

t_params	return_params(char *plateau);

int	main(int ac, char *av[])
{
	int			i;
	char		*plateau;
	t_params	params;
	int			c;
	int			is_vid;

	i = 1;
	if (ac < 2)
	{
		write (1, "map error ac\n", 12);
		return (0);
	}
	while (i < ac)
	{	
		plateau = ft_files_to_plateau(av[i]);
		//printf("%s\n", plateau);
		if (!is_plateau_valid(plateau))
		{
			write (1, "map error\n", 10);
			return (0);
		}
		i ++;
	}
	c = 4;
	params = return_params(plateau);
	while (c < ft_strlen(plateau))
	{
		is_vid = is_vide(plateau[c], plateau);
		if (is_vid == 1)
		{
			plateau[c] = 'x';
		}
		else if (is_vid == 0)
		{
			plateau[c] = 'O';
		}
		else if (is_vid == -1)
		{
			plateau[c] = '\n';
		}
		c++;
	}
	printf("%s\n", plateau);
	free(plateau);
	return (0);
}

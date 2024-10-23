/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:46:39 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/23 03:07:00 by bvelonja         ###   ########.fr       */
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
	// t_params	params;
	// int			c;
	char		**tab_plateau;

	i = 1;
	if (ac < 2)
	{
		write (1, "map error\n", 10);
		return (0);
	}
	while (i < ac)
	{
		plateau = ft_files_to_plateau(av[i]);
		if (!is_plateau_valid(plateau))
		{
			write (1, "map error\n", 10);
			return (0);
		}
		tab_plateau = plateau_to_tab(av[i]);
		for (int i = 0; tab_plateau[i]; i++)
		{
			for (int j = 0; tab_plateau[i][j]; j++)
			{
				printf("%c", tab_plateau[i][j]);
			}
			printf("\n");
		}
		i ++;
	}
	// c = 4;
	// params = return_params(plateau);
	free(plateau);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:46:39 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/23 11:52:17 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_lib.h"
#include "struct.h"
#include <stdlib.h>
#include <unistd.h>

t_params	return_params(char *plateau);
t_square	find_bsq(t_params params, char **plateau, char *str_plateau);
int			is_square_valid(int x, int y, int gen, t_params p, char **plat);
int			is_vide(char c, t_params params);

int	main(int ac, char *av[])
{
	int			i;
	char		*plateau;
	char		**tab_plateau;
	t_params	params;
	t_square	square;

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
		params = return_params(plateau);
		square = find_bsq(params, tab_plateau, plateau);
		printf(" depart = %i\n", square.generator);
		printf(" x_max = %i\n", square.x_max);
		printf("y_max = %i\n", square.y_max);
	}
	free(plateau);
	return (0);
}

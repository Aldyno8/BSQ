/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 04:13:33 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/23 20:00:19 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_lib.h"
#include <unistd.h>

int			is_vide(char c, t_params params);

int	is_square_valid(int gen, int y, int size, t_params p, char **plat)
{
	int	i;
	int	j;

	j = y;
	while (j < y + size)
	{
		i = gen;
		while (i < gen + size)
		{
			if (!(is_vide(plat[j][i], p)))
				return (0);
			i ++;
		}
		j++;
	}
	return (1);
}

t_square	initialise(int i, int j, int counter)
{
	t_square	square;

	square.x = i ;
	square.y = j;
	square.size = counter;
	return (square);
}

t_square	find_bsq(t_params params, char **plateau)
{
	t_square	square;
	int			i;
	int			j;
	int			counter;

	square.size = 1;
	square.x = 0;
	square.y = 0;
	counter = 0;
	j = 0;
	i = 0;
	while (plateau[j])
	{
		i = 0;
		while (plateau[j][++i])
		{
			while (is_square_valid(i, j, counter, params, plateau))
				counter ++;
			if (counter > square.size)
				square = initialise(i, j, counter);
			counter = 0;
		}
		j ++;
	}
	return (square);
}

void	print_result(t_params params, char **plateau)
{
	int			i;
	int			j;
	t_square	square;

	i = 0;
	square = find_bsq(params, plateau);
	while (plateau[i])
	{
		j = 0;
		while (plateau[i][j])
		{
			if (j >= square.x && i >= square.y
				&& j < square.x + square.size - 1
				&& i < square.y + square.size - 1)
			{
				plateau[i][j] = params.plein;
			}
			write(1, &plateau[i][j], 1);
			j ++;
		}
		write(1, "\n", 1);
		i ++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 04:13:33 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/23 21:20:39 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_lib.h"
#include <unistd.h>

int	is_vide(char c, t_params params)
{
	if (c == params.obstacle)
		return (0);
	if (c == params.vide)
		return (1);
	else
		return (0);
}

int	is_square_valid(t_scare_test sqare, t_params p, char **plat)
{
	int	i;
	int	j;

	j = sqare.y;
	while (j < sqare.y + sqare.size)
	{
		i = sqare.x;
		while (i < sqare.x + sqare.size)
		{
			if (!(is_vide(plat[j][i], p)))
				return (0);
			i ++;
		}
		j++;
	}
	return (1);
}

t_square	init(int i, int j, int counter)
{
	t_square	square;

	square.x = i ;
	square.y = j;
	square.size = counter;
	return (square);
}

t_square	find_bsq(t_params params, char **plateau)
{
	t_square		square;
	t_scare_test	square_test;

	square.size = 1;
	square.x = 0;
	square.y = 0;
	square_test.size = 0;
	square_test.y = 0;
	square_test.x = 0;
	while (plateau[square_test.y])
	{
		square_test.x = 0;
		while (plateau[square_test.y][++ square_test.x])
		{
			while (is_square_valid(square_test, params, plateau))
				square_test.size ++;
			if (square_test.size > square.size)
				square = init(square_test.x, square_test.y, square_test.size);
			square_test.size = 0;
		}
		square_test.y ++;
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

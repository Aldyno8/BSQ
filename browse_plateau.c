/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_plateau.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:33:11 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/22 20:20:09 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>

t_params	return_params(char *plateau)
{
	t_params	params;

	params.len = plateau[0];
	params.vide = plateau[1];
	params.obstacle = plateau[2];
	params.plein = plateau[3];
	return (params);
}

int	is_params_valid(char *plateau)
{
	int	i;
	int	j;

	i = 0;
	while (plateau[i] != '\n')
	{
		j = i +1;
		while (plateau[j] != '\n')
		{
			if (plateau[i] == plateau [j])
				return (0);
			j ++;
		}
		i ++;
	}
	if (i != 4)
		return (0);
	return (1);
}

int	is_plateau_valid(char *plateau)
{
	int			i;
	t_params	params;

	i = 5;
	params = return_params(plateau);
	if (!is_params_valid(plateau))
	{
		return (0);
	}
	while (plateau[i])
	{
		if (plateau[i] != params.obstacle && plateau[i] != params.plein
			&& plateau[i] != params.vide && plateau[i] != '\n')
		{
			return (0);
		}
		i ++;
	}
	return (1);
}

int	is_vide(char c, char *plateau)
{
	t_params	params;

	params = return_params(plateau);
	if (c == params.obstacle)
		return (0);
	if (c == params.vide)
		return (1);
	if (c == '\n')
		return (-1);
	return (1);
}

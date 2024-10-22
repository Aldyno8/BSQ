/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_plateau.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:33:11 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/22 16:11:05 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_params	return_params(char *plateau)
{
	t_params	params;

	params.len = plateau[0];
	params.vide = plateau[1];
	params.obstacle = plateau[2];
	params.plein = plateau[3];
	return (params);
}

int	is_vide(char c, char *plateau)
{
	t_params	params;

	params = return_params(plateau);
	if (c == params.obstacle)
		return (0);
	if (c == params.vide)
		return (1);
	return (1);
}

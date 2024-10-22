/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:46:39 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/22 16:20:20 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_lib.h"
#include "struct.h"

t_params	return_params(char *plateau);

int	main(int ac, char *av[])
{
	int			i;
	char		*plateau;
	t_params	params;
	int			c;

	i = 1;
	if (ac < 1)
	{
		return (0);
	}
	while (i < ac)
	{
		plateau = ft_files_to_plateau(av[i]);
		printf("%s\n", plateau);
		i ++;
	}
	params = return_params(plateau);
	c = 0;
	/*while (c < ft_strlen(plateau))
	{
		if (is_vide(plateau[c]))
		{
			plateau[c] = 'v';
		}
		printf("%s\n", plateau);
	}*/
	
	return (0);
}

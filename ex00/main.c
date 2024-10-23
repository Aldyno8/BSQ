/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:46:39 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/23 23:39:14 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
#include "struct.h"
#include <stdlib.h>
#include <unistd.h>

t_params	return_params(char *plateau);
t_square	find_bsq(t_params params, char **plateau);
void		print_result( t_params params, char **plateau);
int			is_square_valid(t_scare_test sqare, t_params p, char **plat);
int			is_vide(char c, t_params params);

int	main(int ac, char *av[])
{
	int			i;
	char		*plateau;
	char		**tab_plateau;
	t_params	params;

	i = 1;
	(void)ac;
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
		print_result(params, tab_plateau);
		i ++;
	}
	free(plateau);
	return (0);
}

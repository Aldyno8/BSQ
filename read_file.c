/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:08:11 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/23 18:56:26 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_lib.h"

int	ft_files_size(char *plateau)
{
	int		files;
	int		size;
	int		char_read;
	char	buffer[2];

	files = open(plateau, O_RDONLY);
	size = 0;
	char_read = -1;
	if (files == -1)
		return (0);
	while (char_read != 0)
	{
		char_read = read(files, buffer, 1);
		if (char_read == -1)
			return (0);
		size = size + char_read;
	}
	close (files);
	return (size);
}

char	*ft_files_to_plateau(char *plateau)
{
	int		size;
	int		char_read;
	int		files;
	char	*str;
	char	buffer[2];

	size = ft_files_size(plateau);
	str = malloc (sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	str[0] = '\0';
	files = open(plateau, O_RDONLY);
	if (files == 0)
		return (0);
	char_read = -1;
	while (char_read != 0)
	{
		char_read = read(files, buffer, 1);
		if (char_read == -1)
			return (0);
		buffer[char_read] = '\0';
		ft_strcat(str, buffer);
	}
	close (files);
	return (str);
}

void	*alloc_memory(char **tab, int size, char *plateau)
{
	int	i;
	int	len_line;

	i = 0;
	len_line = 5;
	while (plateau[len_line] != '\n')
	{
		len_line ++;
	}
	while (i < size)
	{
		tab[i] = malloc(sizeof(char) * len_line);
		i ++;
	}
	tab[i] = NULL;
	if (tab == NULL)
		return (NULL);
	return (tab);
}

char	**plateau_to_tab(char *plateau)
{
	int		i;
	int		j;
	int		c;
	char	*str_plateau;
	char	**tab_plateau;

	i = 0;
	j = 0;
	c = 5;
	str_plateau = ft_files_to_plateau(plateau);
	tab_plateau = malloc(sizeof(char) * ft_strlen(str_plateau));
	alloc_memory(tab_plateau, ft_strlen(plateau), str_plateau);
	while (str_plateau[c])
	{
		if (str_plateau[c] == '\n')
		{
			i ++;
			j = 0;
			c ++;
		}
		tab_plateau[i][j] = str_plateau[c++];
		j ++;
	}
	free(str_plateau);
	return (tab_plateau);
}

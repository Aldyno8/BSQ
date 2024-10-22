/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:08:11 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/22 16:05:54 by bvelonja         ###   ########.fr       */
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

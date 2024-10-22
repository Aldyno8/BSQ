/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:05:50 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/22 16:16:39 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

char	*ft_strcat(char *dest, char *src);
int		ft_files_size(char *plateau);
char	*ft_files_to_plateau(char *plateau);
int		is_vide(char *plateau);
int	ft_strlen(char *str);

#endif
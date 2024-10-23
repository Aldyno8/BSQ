/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:05:50 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/23 02:26:36 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

char		*ft_strcat(char *dest, char *src);
int			ft_files_size(char *plateau);
char		*ft_files_to_plateau(char *plateau);
int			is_vide(char c, char *plateau);
int			ft_strlen(char *str);
int			is_plateau_valid(char *plateau);
char		**plateau_to_tab(char *plateau);

#endif
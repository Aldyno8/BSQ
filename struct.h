/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:09:28 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/23 14:52:52 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct t_params
{
	char	obstacle;
	char	vide;
	char	plein;
	char	len;
}	t_params;

typedef struct t_square
{
	int	x;
	int	y;
	int	size;
}	t_square;

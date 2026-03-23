/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:20:52 by jonamart          #+#    #+#             */
/*   Updated: 2026/03/19 17:15:40 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	aux_mouse_move(int delta, int x)
{
	if (delta < 0)
	{
		if (x > 1040)
			delta = -1;
		else
			delta = -2;
	}
	else
	{
		if (x < 40)
			delta = 1;
		else
			delta = 2;
	}
	return (delta);
}

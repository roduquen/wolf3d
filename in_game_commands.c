/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:47:47 by roduquen          #+#    #+#             */
/*   Updated: 2019/07/15 21:15:12 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

static void	door_opening_system(t_wolf *data, t_vec2d pos)
{
	if (pos.x - 1 > 0 && data->board[(int)pos.x - 1][(int)pos.y] == '0')
		doors_move(data, (int)pos.x - 1, (int)pos.y);
	if (pos.x + 1 < data->map_height && data->board[(int)pos.x + 1][(int)pos.y]
		== '0')
		doors_move(data, (int)pos.x + 1, (int)pos.y);
	if (pos.y - 1 > 0 && data->board[(int)pos.x][(int)pos.y - 1] == '0')
		doors_move(data, (int)pos.x, (int)pos.y - 1);
	if (pos.y + 1 < data->map_width && data->board[(int)pos.x][(int)pos.y + 1]
		== '0')
		doors_move(data, (int)pos.x, (int)pos.y + 1);
}

void		active_commands(t_wolf *data, t_vec2d pos)
{
	if (pos.x - 1 > 0 && ft_memchr("123456789"
			, data->board[(int)pos.x - 1][(int)pos.y], 9))
	{
		data->actual_floor = data->board[(int)pos.x - 1][(int)pos.y] - 47;
		init_floor_change(data);
	}
	if (pos.x + 1 < data->map_width && ft_memchr("123456789"
			, data->board[(int)pos.x + 1][(int)pos.y], 9))
	{
		data->actual_floor = data->board[(int)pos.x + 1][(int)pos.y] - 47;
		init_floor_change(data);
	}
	if (pos.y - 1 > 0 && ft_memchr("123456789"
			, data->board[(int)pos.x][(int)pos.y - 1], 9))
	{
		data->actual_floor = data->board[(int)pos.x][(int)pos.y - 1] - 47;
		init_floor_change(data);
	}
	if (pos.y + 1 < data->map_height
		&& ft_memchr("123456789", data->board[(int)pos.x][(int)pos.y + 1], 9))
	{
		data->actual_floor = data->board[(int)pos.x][(int)pos.y + 1] - 47;
		init_floor_change(data);
	}
	door_opening_system(data, pos);
}

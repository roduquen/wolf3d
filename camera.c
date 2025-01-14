/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:12:58 by roduquen          #+#    #+#             */
/*   Updated: 2019/07/15 21:14:33 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "libft.h"

static void	camera_carry_event_2(t_wolf *data, t_vec2d tmp)
{
	tmp = vec2d_rotate(data->camera.direction, to_radian(90.0));
	if (data->camera.key & CAMERA_RIGHT)
	{
		if (!ft_memchr(WALLS, data->board[(int)(data->camera.position.x - tmp.x
				* data->camera.move_speed)][(int)data->camera.position.y]
				, sizeof(WALLS)))
			data->camera.position.x -= tmp.x * data->camera.move_speed;
		if (!ft_memchr(WALLS, data->board[(int)(data->camera.position.x)]
			[(int)(data->camera.position.y - tmp.y * data->camera.move_speed)]
			, sizeof(WALLS)))
			data->camera.position.y -= tmp.y * data->camera.move_speed;
	}
	if (data->camera.key & CAMERA_LEFT)
	{
		if (!ft_memchr(WALLS, data->board[(int)(data->camera.position.x + tmp.x
				* data->camera.move_speed)][(int)data->camera.position.y]
				, sizeof(WALLS)))
			data->camera.position.x += tmp.x * data->camera.move_speed;
		if (!ft_memchr(WALLS, data->board[(int)(data->camera.position.x)]
			[(int)(data->camera.position.y + tmp.y * data->camera.move_speed)]
			, sizeof(WALLS)))
			data->camera.position.y += tmp.y * data->camera.move_speed;
	}
}

void		camera_carry_event(t_wolf *data, t_vec2d tmp)
{
	if (data->camera.key & CAMERA_FRONT)
	{
		if (!ft_memchr(WALLS, data->board[(int)(data->camera.position.x
					+ data->camera.direction.x
					* data->camera.move_speed)][(int)data->camera.position.y]
					, sizeof(WALLS)))
			data->camera.position.x += tmp.x * data->camera.move_speed;
		if (!ft_memchr(WALLS, data->board[(int)(data->camera.position.x)]
			[(int)(data->camera.position.y + data->camera.direction.y
				* data->camera.move_speed)], sizeof(WALLS)))
			data->camera.position.y += tmp.y * data->camera.move_speed;
	}
	if (data->camera.key & CAMERA_BACK)
	{
		if (!ft_memchr(WALLS, data->board[(int)(data->camera.position.x
					- data->camera.direction.x
					* data->camera.move_speed)][(int)data->camera.position.y]
					, sizeof(WALLS)))
			data->camera.position.x -= tmp.x * data->camera.move_speed;
		if (!ft_memchr(WALLS, data->board[(int)(data->camera.position.x)]
			[(int)(data->camera.position.y - data->camera.direction.y
				* data->camera.move_speed)], sizeof(WALLS)))
			data->camera.position.y -= tmp.y * data->camera.move_speed;
	}
	camera_carry_event_2(data, tmp);
}

void		camera_downkey_event(t_wolf *data)
{
	if (data->event.key.keysym.sym == SDLK_d)
		data->camera.key |= CAMERA_RIGHT;
	else if (data->event.key.keysym.sym == SDLK_a)
		data->camera.key |= CAMERA_LEFT;
	else if (data->event.key.keysym.sym == SDLK_w)
		data->camera.key |= CAMERA_FRONT;
	else if (data->event.key.keysym.sym == SDLK_s)
		data->camera.key |= CAMERA_BACK;
}

void		camera_upkey_event(t_wolf *data)
{
	if (data->event.key.keysym.sym == SDLK_d)
		data->camera.key &= ~CAMERA_RIGHT;
	else if (data->event.key.keysym.sym == SDLK_a)
		data->camera.key &= ~CAMERA_LEFT;
	else if (data->event.key.keysym.sym == SDLK_w)
		data->camera.key &= ~CAMERA_FRONT;
	else if (data->event.key.keysym.sym == SDLK_s)
		data->camera.key &= ~CAMERA_BACK;
}

void		camera_mouse_event(t_wolf *data)
{
	data->camera.direction = vec2d_rotate(data->camera.direction
			, to_radian(360 - data->camera.angle_speed
				* data->event.motion.xrel));
	data->camera.plane = vec2d_rotate(data->camera.plane
			, to_radian(360 - data->camera.angle_speed
				* data->event.motion.xrel));
}

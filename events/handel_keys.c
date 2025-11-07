/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:18:24 by imatouil          #+#    #+#             */
/*   Updated: 2025/11/06 21:27:22 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	close_window(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	clean_up(cub);
	exit(0);
}

void	handel_key(mlx_key_data_t key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (key.key == MLX_KEY_ESCAPE)
		close_window(cub);
	if (key.key == MLX_KEY_W)
		cub->player->y -= MOVE_SPEED;
	if (key.key == MLX_KEY_S)
		cub->player->y += MOVE_SPEED;
	if (key.key == MLX_KEY_A)
		cub->player->x -= MOVE_SPEED;
	if (key.key == MLX_KEY_D)
		cub->player->x += MOVE_SPEED;
	draw_map(cub);
}

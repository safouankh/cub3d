#include "../includes/cub3d.h"

#define TILE_SIZE 16
#define PLAYER_SIZE 8

#define WALL_COLOR 0xAAAAAAFF
#define FLOOR_COLOR 0xFFFFFFFF
#define PLAYER_COLOR 0xFF0000FF

static void	draw_tile(mlx_image_t *image, int x, int y, int size, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_put_pixel(image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (cub->map->grid[y])
	{
		x = 0;
		while (cub->map->grid[y][x])
		{
			if (cub->map->grid[y][x] == '1')
				draw_tile(cub->g_img, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE,
					WALL_COLOR);
			else if (cub->map->grid[y][x] == '0' || ft_strchr("NSEW",
					cub->map->grid[y][x]))
				draw_tile(cub->g_img, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE,
					FLOOR_COLOR);
			x++;
		}
		y++;
	}
	draw_tile(cub->g_img, cub->player->x * TILE_SIZE, cub->player->y * TILE_SIZE,
		PLAYER_SIZE, PLAYER_COLOR);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:36:26 by ooussaad          #+#    #+#             */
/*   Updated: 2023/08/06 22:15:09 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_init(t_game *ptr)
{
	ptr->cub_map.counter = 0;
	ptr->rows = 0;
	ptr->coloumes = 0;
	ptr->cub_map.floor_clr.red = 0;
	ptr->cub_map.floor_clr.bleu = 0;
	ptr->cub_map.floor_clr.green = 0;
	ptr->cub_map.ceill_clr.red = 0;
	ptr->cub_map.ceill_clr.bleu = 0;
	ptr->cub_map.ceill_clr.green = 0;
}

void free_array2(char **array, int size)
{
    if (array == NULL)
        return;

    for (int i = 0; i < size; i++)
    {
        free(array[i]);
    }
    free(array);
}

void	start_game(t_game *ptr,char *holder)
{
	int x = 0;
	int y = 0;
	ptr->map = ft_split(holder,'\n');
	ft_init(ptr);
	check_content(ptr->map, ptr->map_path_cl);
	fill_textures(ptr);
	fill_colors(ptr);
	
	int copied_length;
    ptr->temp_work = copy_array(ptr->map, 6, &copied_length);
	ptr->correct_map = copy_array(ptr->map, 6, &copied_length);
    ptr->temp_work_two = copy_array(ptr->map, 6, &copied_length);

	dprintf (2, "Check >>>>>>>>>>>>> %p\n", ptr->temp_work);
	dprintf (2, "Check >>>>>>>>>>>>> %p\n", ptr->correct_map);
	dprintf (2, "Check >>>>>>>>>>>>> %p\n", ptr->temp_work_two);
	free_array(ptr->temp_work_two);
	check_walls(ptr->temp_work,ptr);
	int maxIndex;
	int h = 0;
    int maxLineLength = find_max_map(ptr->temp_work, &maxIndex, &h);
	ptr->temp_work_two = cpy_map(ptr->temp_work, maxLineLength, h);
	check_all(ptr->temp_work_two);
	if (!check_map(ptr->temp_work))
	{
		ft_putstr_err("error char\n");
		exit(1);
	}
	check_doubles(ptr->temp_work,ptr);
	// y = position(ptr->temp_work).player_y;
	// x = position(ptr->temp_work).player_x;
	// free_array2(ptr->temp_work_two, h);
	// free(ptr->cub_map.north_texture);
    // free(ptr->cub_map.south_texture);
    // free(ptr->cub_map.west_texture);
    // free(ptr->cub_map.east_texture);
	// free(ptr->temp_work);
}

int	main(int argc, char **argv)
{
    int			fd;
	char		*holder;
    t_game      *ptr;
	
    if (argc == 2)
    {
		ptr = malloc(sizeof(t_game ));
		check_file(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1) {
			perror(argv[1]);
			exit(1);
		}
		holder = get_next_line(fd);
		if (!holder)
			exit(0);
		start_game(ptr, holder);
		free(holder);
		position(ptr);	
		int i =0;
		while(ptr->correct_map[i]) {
			printf("%s\n",ptr->correct_map[i]);
			i++;
		}
		ft_cub(ptr);
    }
    else
	{
		write(2, "argv error", 11);
		return (0);
	}
	while(1);
}

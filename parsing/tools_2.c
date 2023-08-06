/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:02:02 by ooussaad          #+#    #+#             */
/*   Updated: 2023/08/06 21:57:54 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char** fix_line_size(char **map, int numLines) 
{
    char **dst = (char **)ft_calloc((numLines + 1) * sizeof(char *), 1);
    int i = 0;
    while (i < numLines && map[i] != NULL) {
        dst[i] = ft_strdup(map[i]);
        i++;
    }
    return dst;
}

int hasDuplicate(char** map)
{
    int i = 0;
    char **dst = (char **)malloc((6 + 1) * sizeof(char *));
    while (i < 6 && map[i] != NULL) {
        dst[i] = map[i];
        i++;
    }
    dst[i] = NULL;
	i = 0;
    while (dst[i] != NULL) 
	{
        int j = i + 1;
        while (dst[j] != NULL) {
            int k = 0;
            while (dst[i][k] != ' ' && dst[i][k] != '\0' && dst[i][k] != '\n') {
                if (dst[i][k] != dst[j][k]) {
                    break;
                }
                k++;
            }
            if (dst[i][k] == dst[j][k]) {
                return 1;
            }
            j++;
        }
        i++;
    }
    free (dst);
    return 0;
}

void check_rgb(t_rgb_color *ptr)
{
    if (ptr->red > 255 || ptr->red < 0)
    {
        ft_putstr_err("rgb error");
        exit(0);
    }
    else if (ptr->green > 255 || ptr->green < 0)
    {
        ft_putstr_err("rgb error");
        exit(0);
    }
    else if (ptr->bleu > 255 || ptr->bleu < 0)
    {
        ft_putstr_err("rgb error");
        exit(0);
    }
}

int is_alphabet(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int ft_atoi_rgb(char *str)
{
    size_t i = 0;
    unsigned long result = 0;
    int signe = 1;

    while (str[i])
    {
        if ((str[i] >= 'a' && str[i]<= 'z') || (str[i] >= 'A' && str[i]<= 'Z'))
        {
            printf("error");
            exit(0);
        }
        i++;
    }
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            signe = signe * -1;
        i++;
    }
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
    return (int)(result * signe);
}

void fill_rgb(t_rgb_color *ptr,char **holder)
{
	int i = len(holder);
	if (i != 3)
	{
		ft_putstr_err("error number of rgb");
		exit(1);
	}
	else
	{
		ptr->red = ft_atoi_rgb(holder[0]);
		ptr->green = ft_atoi_rgb(holder[1]);
		ptr->bleu = ft_atoi_rgb(holder[2]);
	}
    check_rgb(ptr);
}
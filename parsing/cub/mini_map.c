/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:55:28 by aerraoui          #+#    #+#             */
/*   Updated: 2023/08/06 23:26:07 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"../cub3d.h"

// void creat_player(t_game *data)
// {
//    double x = 10 + 180;
//    double y = 10 +180;
//    
//    x -=20;
//    y-=20;
//    while(x < x + 40)
//    {
    //    y = 10 + 40 -20;
    //    while(y <y+40)
    //    {
        //    my_mlx_pixel_put(data,x,y,0x00FC2A);
        //    y++;
    //    }
    //    x++;
//    }
// }

void pixal_to_squar(t_game *data ,int x ,  int y)
{
    int i;
    int j;

    i = x -6;
    j = y - 6;

    while(i< x +6)
    {
        j  = y - 6;
        while(j < y+6)
        {
             my_mlx_pixel_put(data,i/2,j/2,0x00FC2A);
             j++;
        }
        i++;
    }
}
void    mini_map(t_game *home)
{
  
    double i ,j ,px,py;
  
    i = 10;
    px = home->pl_x - 500;
    printf("main_mp : %f %f   \n ",home->pl_x ,home->pl_y);
    while (i < 510)
    {
        j = 10;
        py = home->pl_y -500;
        while (j < 510)
        {
            if(px < 0 || px > home->WHITE_rays || py < 0 || py > home->HIEGHT_rays)
                my_mlx_pixel_put(home, i/2, j/2, 0xFF0000);
            else if(home->correct_map[(int)py / 50][(int)px / 50] == '1')
              my_mlx_pixel_put(home, i/2, j/2, 0x000000);
            else
                my_mlx_pixel_put(home, i/2, j/2, 0xFDFDFD);
            j++;
            py += 2;
        }
        px += 2;
        i++;
    }
    pixal_to_squar(home,255 ,255);

}
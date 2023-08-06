/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:28:15 by aerraoui          #+#    #+#             */
/*   Updated: 2023/08/06 19:58:12 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int key_press(int key,t_game *data)
{
    printf("%d",key);
    if(key == 13)
        data->move.move_up_down = 1;
    if(key == 1)
        data->move.move_up_down = -1;
    if(key == 123)
        data->move.move_angle = 1;
    if(key == 124)
        data->move.move_angle = -1;
    if(key == 2)
        data->move.move_right_left = 1;
    if(key == 0)
        data->move.move_right_left = -1;

     if (key == 53)
     exit(0);
    
     return (0);
}
int key_realise(int key , t_game *data)
{
    if(key == 13 || key == 1)
        data->move.move_up_down = 0;
    if(key == 123 || key == 124)
        data->move.move_angle = 0;
    if(key == 0 || key == 2)
        data->move.move_right_left = 0;
return (0);

}

void	key_hook(t_game *img)
{
    double x = img->pl_x;
    double y= img->pl_y;
    int i = 0;
	if (img->move.move_up_down == 1 ) // w
    {
      
             if(img->correct_map[(int)(img->pl_y)/50][(int)(img->pl_x + (img->pdx *28))/50]  != '1')
                img->pl_x += img->pdx *15 ;
             if(img->correct_map[(int)(img->pl_y + (img->pdy *28 ))/50][(int)(img->pl_x) / 50] != '1')
                img->pl_y += img->pdy * 15 ;
    }
	if (img->move.move_up_down == -1) // s
	{
             if(img->correct_map[(int)(img->pl_y)/50][(int)(img->pl_x - (img->pdx* 28))/50 ] != '1')
                img->pl_x -= img->pdx * 15;
            if(img->correct_map[(int)(img->pl_y - (img->pdy * 28))/50 ][(int)(img->pl_x)/50] != '1')
                img->pl_y -= img->pdy * 15;
    }

	if (img->move.move_angle == 1) // ->
    {
        img->pa-=0.1;
        img->pdx = cos(img->pa);
        img->pdy = sin(img->pa);
    }
	if (img->move.move_angle == -1) // <-
	 {
        img->pa+=0.1;
        img->pdx=cos(img->pa);
        img->pdy=sin(img->pa);
    }
    if(img->move.move_right_left == 1) // d
    { 

            if(img->correct_map[(int)(img->pl_y)/50][(int)((img->pl_x) - cos(img->pa + PI/2) * 28)/50] != '1')
                img->pl_x += cos(img->pa + PI/2);
            if(img->correct_map[(int)(img->pl_y +(sin(img->pa + PI/2)) * 28)/50][(int)(img->pl_x)/50] != '1')
                     img->pl_y += sin(img->pa + PI/2);
    }
    if(img->move.move_right_left == -1) // a
    { 
            if(img->correct_map[(int)(img->pl_y)/50][(int)(img->pl_x - cos(img->pa + PI/2))/50] != '1')
                img->pl_x += cos(img->pa - PI/2) ;
            if(img->correct_map[(int)(img->pl_y +(sin(img->pa - PI/2)) *28)/50][(int)(img->pl_x)/50] != '1')
                     img->pl_y += sin(img->pa - PI/2) ;
    }
//    if(!check_posision(img))
//    {
//       img->pl_y = y;
//       img->pl_x=  x;
//    }

}


int check_posision(t_game *data)
{
    double x = data->pl_x -8;
    double y = data->pl_y -8; 
    while(x < data->pl_x + 16)
    {
        y = data->pl_y -8;
        while(y < data->pl_y+16 )
        {
            if((data->correct_map[(int)(y)/50][(int)(x)/50]) != '0')
                return(0);
            y++;
        }
        x++;
    }
    return(1);
}

// void	key_hook( t_game *img)
// {
//     double x = img->pl_x;
//     double y= img->pl_y;
//     int i = 0;
// 	if (img->move.move_up_down == 1) // w
//     {
        
//              if(img->correct_map[(int)(img->pl_y)/50][(int)(img->pl_x + (img->pdx / 50 ))/50]  == '0')
//                 img->pl_x += img->pdx ;
//              if(img->correct_map[(int)(img->pl_y + img->pdy )/50][(int)(img->pl_x) / 50] == '0')
//                 img->pl_y += img->pdy ;
//             i++;
//     }
// 	if (img->move.move_up_down == -1) // s
// 	{
//         while (i < 100) {
//              if(img->correct_map[(int)(img->pl_y)/50][(int)(img->pl_x - (img->pdx / 50))/50 ] == '0')
//                 img->pl_x -= img->pdx / 50;
//             if(img->correct_map[(int)(img->pl_y - (img->pdy/ 50 ))/50 ][(int)(img->pl_x)/50] == '0')
//                 img->pl_y -= img->pdy / 50;
//             i++;
//         }
//     }

// 	if (img->move.move_angle == 1) // ->
//     {
//         img->pa-=0.1;
//         img->pdx = cos(img->pa);
//         img->pdy = sin(img->pa);
//     }
// 	if (img->move.move_angle == -1) // <-
// 	 {
//         img->pa+=0.1;
        
//         img->pdx=cos(img->pa);
//         img->pdy=sin(img->pa);
//     }
//     if(img->move.move_right_left == 1) // d
//     {
//             if(img->correct_map[(int)(img->pl_y)/50][(int)((img->pl_x) - cos(img->pa + PI/2) / 100)/50 +3] == '0')
//                 img->pl_x += cos(img->pa + PI/2) *2;
//             if(img->correct_map[(int)(img->pl_y +(sin(img->pa + PI/2) / 100))/50][(int)(img->pl_x)/50] == '0')
//                      img->pl_y += sin(img->pa + PI/2) ;
//     }
//     if(img->move.move_right_left == -1) // a
//     {
//          while (i < 100) 
//         {
//             if(img->correct_map[(int)(img->pl_y)/50][(int)(img->pl_x - cos(img->pa + PI/2) / 30)/50] == '0')
//                 img->pl_x += cos(img->pa - PI/2) / 50;
//             if(img->correct_map[(int)(img->pl_y +(sin(img->pa - PI/2) / 30))/50][(int)(img->pl_x)/50] == '0')
//                      img->pl_y += sin(img->pa - PI/2) / 50;
//             i++;
//         }
//     }
//    if(!check_posision(img))
//    {
//       img->pl_y = y;
//       img->pl_x=  x;
//    }
//}
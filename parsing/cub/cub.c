/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:35:20 by aerraoui          #+#    #+#             */
/*   Updated: 2023/08/06 23:19:21 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"



void get_map_demantion(t_game *game)
{
    int i ;
    int max;
    
    i = 0;
    max = 0;
    game->correct_map[1][1]='0';
    while(game->correct_map[i])
    {
        if(ft_strlen(game->correct_map[i]) > max)
            max = ft_strlen(game->correct_map[i]);
        i++;
    }

    game->WHITE_rays = ((max) * 50);
    game->HIEGHT_rays = (i) * 50;

    game->WHITE = 1080;
    game->HIEGHT = 1080;
    
}


void casting_ray_Ho(t_game *ray,double angle)
{
    double Ay;
    double Ax;
    double offx;
    double offy;
    
    ray->Xh= 2147483647;
    ray->Yh=2147483647;
    
    Ay = floor(ray->pl_y/50) * 50;
    if (sin(angle) > 0)
        Ay += 50;
    else
        Ay -= 0.000001;
    Ax = ray->pl_x +  (Ay - ray->pl_y) / tan(angle);
        ray->Xh= Ax;
        ray->Yh=Ay;
    
   while((Ax < ray->WHITE_rays && Ax >= 0) && (Ay < ray->HIEGHT_rays && Ay >= 0) && ray->correct_map[(int)Ay / 50][(int)Ax / 50] == '0') {
        if(sin(angle) == 0)
           return;
        if (sin(angle) > 0)
            offy = 50;
        else
            offy = -50;
        offx =  Ax + offy/ (tan(angle));
        Ax = offx;
        Ay += offy;
    }
    
    ray->Xh= Ax;
    ray->Yh=Ay;
}

void casting_ray_ver(t_game *ray,double angle)
{
    double Ay;
    double Ax;
    double offx;
    double offy;

    ray->Xv = 2147483647;
    ray->Yv = 2147483647;
    Ax = floor(ray->pl_x / 50) *50;

    if (cos(angle) > 0)
        Ax += 50;
    else
        Ax -= 0.0000001;

    Ay = ray->pl_y +  (Ax - ray->pl_x) * tan(angle);
    ray->Xv = Ax;
    ray->Yv = Ay;

    while((Ax < ray->WHITE_rays && Ax >= 0) && (Ay < ray->HIEGHT_rays && Ay >= 0) && ray->correct_map[(int)Ay / 50][(int)Ax / 50] == '0'){
        if (cos(angle) > 0)
            offx = 50;
        else
            offx = -50 ;
        offy =  50 * tan(angle);
        Ax += offx;
        if (cos(angle) > 0)
            Ay +=offy;
        else
            Ay-=offy;
    }
    ray->Xv= Ax;
    ray->Yv=Ay;
}

char *set_texteur(t_game *data,int x, int y,double angle)
{
    double persontage;
    double color;
   
   if(data->m == 1)
   {
        if(cos(angle) < 0)
             data->addr1 =mlx_get_data_addr(data->mlx_WE, &data->bits_per_pixel1, &data->line_length1, &data->endian1);
        else
        data->addr1 =mlx_get_data_addr(data->mlx_EU, &data->bits_per_pixel1, &data->line_length1, &data->endian1);
   }
   else
   {
         if(sin(angle) < 0)
            data->addr1 =mlx_get_data_addr(data->mlx_NO, &data->bits_per_pixel1, &data->line_length1, &data->endian1);
        else
        data->addr1 =mlx_get_data_addr(data->mlx_SU, &data->bits_per_pixel1, &data->line_length1, &data->endian1);
   }
    return(data->addr1 + (y * data->line_length1 + x * (data->bits_per_pixel1 / 8)));
    
}

void set_demotion_textuer(t_game *data,int *high,int *whi ,double angle )
{
    if(data->m == 1)
    {
        if(cos(angle)<0)
        {
            *high =data->highWE;
            *whi = data->whiWE;
        }
        else
        {
            *high =data->highEU;
            *whi = data->whiEU; 
        } 
    }
    else
    {
        if(sin(angle)< 0)
        {
            (*high =data->highNO ,*whi = data->whiNO);
            
        }
        else
        {
            *high =data->highSU;
            *whi = data->whiSU;
        }
    }
}

void ft_wall(t_game *data, double dest,int i,double angle)
 {
    int y;
    int x;
    double wall;
    double  p;
    int high;
    int whi;
    
    set_demotion_textuer(data ,&high,&whi,angle);
    x = i;
    y =0;
    p= (data->WHITE / 2) / tan(0.524);
    wall = (50 / dest) * p ;

    int start, end;

    start = (data->HIEGHT / 2) - (wall / 2);
    end = (data->HIEGHT / 2) + (wall / 2);
    
    double start_y = 0;
    if (wall > data->HIEGHT) {
        start_y = (((((wall / 2) - (data->HIEGHT / 2)) * 100) / (wall / 2)) / 100) * (high)/2;

    }
    double start_x;
    if (data->m == 1)
        start_x = ((data->Yv / 50 )- (int)(data->Yv / 50)) * whi;
    else
        start_x = ((data->Xh / 50 )- (int)(data->Xh / 50)) * whi;
    while(y < data->HIEGHT)
    {
        if (y >= start && y < end) {
            unsigned int New_color = *(unsigned int *)set_texteur(data,start_x, start_y,angle);
            my_mlx_pixel_put(data, x, y, New_color);
            start_y += high / wall;
        }
        y++;
    }
      
 }

void cast_ray(t_game *ray ,double angle,int i)
{
    double h;
    double v;
    int x = 0;
    
    casting_ray_Ho(ray, angle);
    casting_ray_ver(ray, angle);
    h = sqrt ((ray->pl_x - ray->Xh) * (ray->pl_x - ray->Xh) + (ray->pl_y - ray->Yh) * (ray->pl_y - ray->Yh) );
    v = sqrt ((ray->pl_x - ray->Xv) * (ray->pl_x - ray->Xv) + (ray->pl_y - ray->Yv) * (ray->pl_y - ray->Yv) );
    while (x < ray->HIEGHT)
    {
        if (x < ray->HIEGHT / 2)
            my_mlx_pixel_put(ray, i, x, 0xF2D04B);
        else
            my_mlx_pixel_put(ray, i, x, 0x9E9E9E);
        x++;
    }
    if(h < v)
    {
        ray->m = 0;
        ft_wall(ray, fabs(h *cos(angle - ray->pa)),i,angle);
    }
    else
    {
        ray->m =1;
        ft_wall(ray,fabs(v *cos(angle - ray->pa)) ,i,angle);
    }
    
}




//int check_posision(t_game *data)
// {
//     double x = data->pl_x -8;
//     double y = data->pl_y -8;

//     while(x < data->pl_x + 16)
//     {
//         y = data->pl_y -8;
//         while(y < data->pl_y+16 )
//         {
//             if((data->correct_map[(int)(y)/50][(int)(x)/50]) != '0')
//                 return(0);
//             y++;
//         }
//         x++;
//     }
//     return(1);
// }
 

 
int Cub_3d(t_game *data)
{
    int coulm=0;
    double angle=data->pa- 0.54;
   mlx_clear_window(data->mlx,data->mlx_win);
    while(coulm < data->WHITE) {
        cast_ray(data,angle,coulm);
        coulm++;
        angle += (double)1.04719755/data->WHITE;
    }
    key_hook(data);
    mini_map(data);
   	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
    return (0);
}









void inis_texture(t_game *img)
{
    printf("texture is loading\n");
    img->mlx_WE = mlx_xpm_file_to_image(img->mlx,img->cub_map.west_texture,&img->whiWE,&img->highWE);
    if(!img->mlx_WE)
        exit(0);
    img->mlx_NO = mlx_xpm_file_to_image(img->mlx,img->cub_map.north_texture,&img->whiNO,&img->highNO);
    if(!img->mlx_NO)
        exit(0);
    img->mlx_EU = mlx_xpm_file_to_image(img->mlx,img->cub_map.east_texture,&img->whiEU,&img->highEU);
    if(!img->mlx_EU)
        exit(0);
    img->mlx_SU = mlx_xpm_file_to_image(img->mlx,img->cub_map.south_texture,&img->whiSU,&img->highSU);
    if(!img->mlx_SU)
        exit(0);
    printf("texture is done");
}

int mouse_move(int x,int y ,t_game *data)
{
    static double mousse_position =0;
    if(mousse_position == 0)
    {
       mousse_position = x;
       return(0);     
    }
    if (x >= mousse_position){
        data->pa += (0.009) *fabs((double)x - mousse_position) ;
        data->pdx = cos(data->pa);
        data->pdy = sin(data->pa);
    } else {
        data->pa -= (0.009)  *fabs((double)x - mousse_position) ;
        data->pdx = cos(data->pa);
        data->pdy = sin(data->pa);
    }
    mousse_position = x;
    return(1);
}

void ft_cub(t_game *img)
{
    get_map_demantion(img);
    
   // img->pa = -PI/2 - 0.001;
    img->pdx = cos(img->pa);
    img->pdy = sin(img->pa);

	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window (img->mlx,img->WHITE, img->HIEGHT, "Cub3D!");
	img->img = mlx_new_image (img->mlx, img->WHITE, img->HIEGHT);
    inis_texture(img);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
   	mlx_loop_hook(img->mlx, Cub_3d, img);
    mlx_hook(img->mlx_win, 2, 1L<<0, key_press, img);
    mlx_hook(img->mlx_win, 3, 0L, key_realise, img);
    mlx_hook(img->mlx_win, 6, 0L, mouse_move, img);
    mlx_loop(img->mlx);
}

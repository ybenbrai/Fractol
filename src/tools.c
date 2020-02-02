/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 01:09:26 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/02 22:59:31 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int    keypress(int key, void *param)
{
    t_data *data;

    data = (void*)param;
    if (key == 4)
        data->mandel->quality += 1;
    else if (key == 37)
        data->mandel->quality -= 1;
    if (key == 8)
            data->mandel->hexa += 1;
    if (key == 69)
        {
                data->mandel->zoom_in -= 0.05;
        }
            
    if (key == 78)
    {
                data->mandel->zoom_in += 0.05;
        
    }
    if (key == 123) 
            data->mandel->right_left += 0.05;
    if (key == 124)
            data->mandel->right_left -= 0.05;
    if (key == 126)
            data->mandel->up_down += 0.05;
    if (key == 125)
            data->mandel->up_down -= 0.05;
    mandelbrot(data);
    return (0);     
}
int     mouse_press(int button, int x, int y, void *param)
{
    t_data *data;
        printf("the value of X : %d\tthe value of Y : %d\n", x, y);
    data = (void*)param;
    if (button == 4)
    {
  
        // printf("hey\n");
        data->mandel->zoom_in += 0.05;
        data->mandel->right_left += 0.05;
    }
    else if (button == 5)
    {
        data->mandel->zoom_in -= 0.05;
        data->mandel->right_left -= 0.05;
    }
    
    mandelbrot(data);
    return (0);
}
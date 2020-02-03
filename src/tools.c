/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 01:09:26 by ybenbrai          #+#    #+#             */
/*   Updated: 2020/02/03 18:24:25 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int    keypress(int key, void *param)
{
    t_data *data;

    data = (void *)param;
    if (key == 4)
        data->quality += 1;
    else if (key == 37)
        data->quality -= 1;
    if (key == 8)
            data->hexa += 1;
    if (key == 69)
        {
                data->zoom_in -= 0.05;
        }

    if (key == 78)
    {
                data->zoom_in += 0.05;

    }
    if (key == 123) 
            data->right_left += 0.05;
    if (key == 124)
            data->right_left -= 0.05;
    if (key == 126)
            data->up_down += 0.05;
    if (key == 125)
            data->up_down -= 0.05;
    mandelbrot(data);
    return (0);     
}
int     mouse_press(int button, int x, int y, void *param)
{
    t_data *data;
        printf("the value of X : %d\tthe value of Y : %d\n", x, y);
    data = (void *)param;
    if (button == 4)
    {

        // printf("hey\n");
        data->zoom_in += 0.05;
        data->right_left += 0.05;
    }
    else if (button == 5)
    {
        data->zoom_in -= 0.05;
        data->right_left -= 0.05;
    }

    mandelbrot(data);
    return (0);
} 
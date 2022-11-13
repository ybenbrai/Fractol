/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:02:30 by ybenbrai          #+#    #+#             */
/*   Updated: 2022/11/13 15:59:48 by ybenbrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void zoomin(int x, int y, t_core *core)
{
    x -= WIDTH / 2;
    y -= HEIGHT / 2;
    core->x2 = ((core->x - x) - WIDTH / 2) / ((double)HEIGHT * 2);
    core->y2 = ((core->y - y) - HEIGHT / 2) / (((double)WIDTH * 2) + y);
    core->zoom *= pow(1.001, 70);
    core->movex = core->y2;
    core->movey = core->x2;
}

void zoomout(int x, int y, t_core *core)
{
    x -= WIDTH / 2;
    y -= HEIGHT / 2;
    core->x2 = ((core->x - x) - WIDTH) / ((double)HEIGHT * 2);
    core->y2 = ((core->y - y) - HEIGHT) / (((double)WIDTH * 2) + y);
    core->zoom /= pow(1.001, 70);
    core->movex -= core->x2;
    core->movey -= core->y2;
}
int closing(t_core *core)
{
    mlx_destroy_window(core->mlx, core->win);
    exit(EXIT_SUCCESS);
}
int moves(int x, int y, t_core *core)
{
    if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
    {
        if ((core->fractol == 1 || core->fractol == 6) && core->movemouse == 1)
        {
            core->clickx = x;
            core->clicky = y;
            core->cre = ((core->clickx - core->x) - WIDTH) /
                        (((double)HEIGHT * 2) + core->y);
            core->cim = ((core->clicky + core->y) - HEIGHT) /
                        ((double)HEIGHT * 2);
            fractolPicker(core);
            mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
        }
    }
    return (0);
}

int mouseKeys(int mousekey, int x, int y, t_core *core)
{
    if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
    {
        if (mousekey == 5)
            zoomin(x, y, core);
        else if (mousekey == 4)
            zoomout(x, y, core);
        if (mousekey == 1)
            core->maxinter += 5;
        else if (mousekey == 2)
        {
            if (core->movemouse == 1)
                core->movemouse = 0;
            else
                core->movemouse = 1;
        }
        fractolPicker(core);
        mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
    }
    return (0);
}
int directionsKeys(int key, t_core *core)
{
    if (key == 49)
        redrawing(core);
    if (key == 18)
    {
        core->color = 1;
        redrawing(core);
    }
    else if (key == 126)
        core->movey += .2 / core->zoom;
    else if (key == 125)
        core->movey -= .2 / core->zoom;
    else if (key == 124)
        core->movex += .2 / core->zoom;
    else if (key == 123)
        core->movex -= .2 / core->zoom;
    return (0);
}

int colorsKeys(int key, t_core *core)
{
    if (key == 19)
    {
        core->color = 0x247812;
        redrawing(core);
    }
    if (key == 20)
    {
        core->color = 2000;
        redrawing(core);
    }
    if (key == 21)
    {
        core->color += 50;
        redrawing(core);
    }
    if (key == 23)
    {
        core->color -= 10;
        redrawing(core);
    }
    return (0);
}

int keysMap(int key, t_core *core)
{
    if (!(core->win))
        return (0);
    if (key == 53)
    {
        ft_putendl_fd("Exiting", 2);
        exit(0);
    }
    else if (key == 116)
        core->zoom *= pow(1.001, 70);
    else if (key == 121)
        core->zoom /= pow(1.001, 70);
    else if (key == 24)
        core->maxinter += 5;
    else if (key == 27)
        core->maxinter -= 5;
    colorsKeys(key, core);
    directionsKeys(key, core);
    fractolPicker(core);
    mlx_put_image_to_window(core->mlx, core->win, core->img, 0, 0);
    return (0);
}
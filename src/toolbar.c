/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** toolbar.c
*/

#include "my_world.h"

static sfColor get_button_color(int index)
{
    if (index == 0)
        return ((sfColor){180, 60, 60, 255});
    if (index == 1)
        return ((sfColor){60, 60, 180, 255});
    return ((sfColor){60, 160, 60, 255});
}

static void draw_button(game_t *game, int index)
{
    sfRectangleShape *button;
    sfColor color;

    color = get_button_color(index);
    if (game->tool != index) {
        color.r /= 2;
        color.g /= 2;
        color.b /= 2;
    }
    button = sfRectangleShape_create();
    sfRectangleShape_setSize(button, (sfVector2f){100, 40});
    sfRectangleShape_setPosition(button, (sfVector2f){10.0f + index * 120, 10});
    sfRectangleShape_setFillColor(button, color);
    sfRectangleShape_setOutlineThickness(button, 2);
    sfRectangleShape_setOutlineColor(button, game->tool == index
        ? sfWhite : (sfColor){60, 60, 60, 255});
    sfRenderWindow_drawRectangleShape(game->win, button, NULL);
    sfRectangleShape_destroy(button);
}

void draw_toolbar(game_t *game)
{
    sfRectangleShape *background;
    int index;

    background = sfRectangleShape_create();
    sfRectangleShape_setSize(background, (sfVector2f){WIN_W, TBH});
    sfRectangleShape_setFillColor(background, (sfColor){30, 30, 30, 255});
    sfRenderWindow_drawRectangleShape(game->win, background, NULL);
    sfRectangleShape_destroy(background);
    index = 0;
    while (index < 3) {
        draw_button(game, index);
        index++;
    }
}

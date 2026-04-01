/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** events.c
*/

#include "my_world.h"
#include <math.h>

static void update_selection(game_t *game, int mouse_x, int mouse_y)
{
    float proj_x;
    float proj_y;

    if (mouse_y < TBH) {
        game->sx = -1;
        game->sy = -1;
        return;
    }
    proj_x = (mouse_x - OX) / (TW / 2.0f);
    proj_y = (mouse_y - OY) / (TH / 2.0f);
    game->sx = (int)floor((proj_x + proj_y) / 2.0f);
    game->sy = (int)floor((proj_y - proj_x) / 2.0f);
    if (game->sx < 0 || game->sx >= MW || game->sy < 0 || game->sy >= MH) {
        game->sx = -1;
        game->sy = -1;
    }
}

static void apply_selected_tool(game_t *game)
{
    if (game->sx < 0 || game->sy < 0)
        return;
    if (game->tool == 0 && game->map[game->sy][game->sx] < 10)
        game->map[game->sy][game->sx]++;
    if (game->tool == 1 && game->map[game->sy][game->sx] > 0)
        game->map[game->sy][game->sx]--;
    if (game->tool == 2)
        game->map[game->sy][game->sx] = 0;
}

static void handle_keyboard(game_t *game, sfEvent *event)
{
    if (event->key.code == sfKeyEscape)
        sfRenderWindow_close(game->win);
    if (event->key.code == sfKeyNum1)
        game->tool = 0;
    if (event->key.code == sfKeyNum2)
        game->tool = 1;
    if (event->key.code == sfKeyNum3)
        game->tool = 2;
}

static void handle_mouse_click(game_t *game, sfEvent *event)
{
    int mouse_x;
    int mouse_y;

    mouse_x = event->mouseButton.x;
    mouse_y = event->mouseButton.y;
    if (mouse_y >= TBH) {
        apply_selected_tool(game);
        return;
    }
    if (mouse_x >= 10 && mouse_x <= 110)
        game->tool = 0;
    if (mouse_x >= 130 && mouse_x <= 230)
        game->tool = 1;
    if (mouse_x >= 250 && mouse_x <= 350)
        game->tool = 2;
}

void handle_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->win);
        if (event.type == sfEvtKeyPressed)
            handle_keyboard(game, &event);
        if (event.type == sfEvtMouseMoved)
            update_selection(game, event.mouseMove.x, event.mouseMove.y);
        if (event.type == sfEvtMouseButtonPressed
            && event.mouseButton.button == sfMouseLeft)
            handle_mouse_click(game, &event);
    }
}

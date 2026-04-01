/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world.h
*/

#ifndef MY_WORLD_H
    #define MY_WORLD_H

    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #define WIN_W 1280
    #define TBH 60
    #define MW 20
    #define MH 20
    #define TW 64
    #define TH 32
    #define ZS 8
    #define OX (WIN_W / 2)
    #define OY (TBH + 60)

typedef struct s_game
{
    sfRenderWindow *win;
    sfClock *clk;
    sfTexture *tex[3];
    float map[MH][MW];
    int tool;
    int sx;
    int sy;
} game_t;

void draw_map(game_t *g);
void draw_toolbar(game_t *g);
void handle_events(game_t *g);

#endif

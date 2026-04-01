/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** main.c
*/

#include "my_world.h"

static sfTexture *create_texture(int red, int green, int blue)
{
    sfImage *image;
    sfTexture *texture;
    sfColor color;

    color = (sfColor){(sfUint8)red, (sfUint8)green, (sfUint8)blue, 255};
    image = sfImage_create(2, 2);
    sfImage_setPixel(image, 0, 0, color);
    sfImage_setPixel(image, 1, 0, color);
    sfImage_setPixel(image, 0, 1, color);
    sfImage_setPixel(image, 1, 1, color);
    texture = sfTexture_createFromImage(image, NULL);
    sfImage_destroy(image);
    return (texture);
}

static void create_textures(game_t *game)
{
    game->tex[0] = create_texture(34, 139, 34);
    game->tex[1] = create_texture(139, 90, 43);
    game->tex[2] = create_texture(110, 110, 110);
}

static void init_game(game_t *game)
{
    game->win = sfRenderWindow_create(
        (sfVideoMode){WIN_W, 720, 32},
        "my_world", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(game->win, 60);
    game->clk = sfClock_create();
    game->tool = 0;
    game->sx = -1;
    game->sy = -1;
    create_textures(game);
}

static void cleanup_game(game_t *game)
{
    int index;

    index = 0;
    while (index < 3) {
        sfTexture_destroy(game->tex[index]);
        index++;
    }
    sfRenderWindow_destroy(game->win);
    sfClock_destroy(game->clk);
}

int main(void)
{
    game_t game;

    game = (game_t){0};
    init_game(&game);
    while (sfRenderWindow_isOpen(game.win)) {
        sfClock_restart(game.clk);
        handle_events(&game);
        sfRenderWindow_clear(game.win, (sfColor){20, 20, 40, 255});
        draw_map(&game);
        draw_toolbar(&game);
        sfRenderWindow_display(game.win);
    }
    cleanup_game(&game);
    return (0);
}

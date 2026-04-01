/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** draw.c
*/

#include "my_world.h"

static sfTexture *get_tile_texture(game_t *game, float height)
{
    if (height > 5)
        return (game->tex[2]);
    if (height > 1)
        return (game->tex[1]);
    return (game->tex[0]);
}

static void draw_tile_face(sfRenderWindow *win, sfVertex *verts,
    sfTexture *texture)
{
    sfRenderStates state;
    sfVertex wire[5];

    state = sfRenderStates_default();
    state.texture = texture;
    sfRenderWindow_drawPrimitives(win, verts, 4, sfQuads, &state);
    wire[0] = (sfVertex){verts[0].position, {0, 0, 0, 160}, {0, 0}};
    wire[1] = (sfVertex){verts[1].position, {0, 0, 0, 160}, {0, 0}};
    wire[2] = (sfVertex){verts[2].position, {0, 0, 0, 160}, {0, 0}};
    wire[3] = (sfVertex){verts[3].position, {0, 0, 0, 160}, {0, 0}};
    wire[4] = wire[0];
    sfRenderWindow_drawPrimitives(win, wire, 5, sfLinesStrip, NULL);
}

static void draw_tile(game_t *game, int col, int row)
{
    float height;
    float base_x;
    float base_y;
    sfVertex verts[4];
    sfColor color;

    height = game->map[row][col];
    base_x = (col - row) * (TW / 2.0f) + OX;
    base_y = (col + row) * (TH / 2.0f) + OY - height * ZS;
    color = (col == game->sx && row == game->sy)
        ? (sfColor){255, 180, 180, 255} : sfWhite;
    verts[0] = (sfVertex){{base_x, base_y}, color, {0, 0}};
    verts[1] = (sfVertex){{base_x + TW / 2.0f, base_y + TH / 2.0f},
        color, {2, 0}};
    verts[2] = (sfVertex){{base_x, base_y + TH}, color, {2, 2}};
    verts[3] = (sfVertex){{base_x - TW / 2.0f, base_y + TH / 2.0f},
        color, {0, 2}};
    draw_tile_face(game->win, verts, get_tile_texture(game, height));
}

static void draw_diagonal(game_t *game, int diag)
{
    int col;
    int row;

    col = 0;
    while (col < MW) {
        row = diag - col;
        if (row >= 0 && row < MH)
            draw_tile(game, col, row);
        col++;
    }
}

void draw_map(game_t *game)
{
    int diag;

    diag = 0;
    while (diag < MW + MH - 1) {
        draw_diagonal(game, diag);
        diag++;
    }
}

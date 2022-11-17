/**
 * @file player.c
 * @author Marcoly ANTOINE/ Adrien GAME
 * @brief code pour le joueur
 * @version 0.1
 * @date 2022-11-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "player.h"
#include "grid.h"


/**
 * @brief Fonction permettant de deplacer le joueur dans la grille de jeu 
 * 
 * @param grid une grille de jeu
 * @param direction la direction dans laquelle on se deplace
 */
void move_player(Grid* grid, enum Direction direction){
    ///position x,y actuelle du joueur
    int x = grid->player.x; 
    int y = grid->player.y; 
    switch (direction){
        case Right:
            if(x < grid->column_number-1 && 
            (grid->game_grid[y][x+1]== NONE || grid->game_grid[y][x+1]== GOAL  ))
                grid->player.x++;
            break;

        case Left:
            if(x > 0 && 
            (grid->game_grid[y][x-1]== NONE || grid->game_grid[y][x-1]== GOAL  ))
                grid->player.x--;
            break;
        
        case Bottom:
            if(y < grid->row_number-1 && 
            (grid->game_grid[y+1][x]== NONE || grid->game_grid[y+1][x]== GOAL  ))
                grid->player.y++;
            break;

        case Top:
            if(y > 0 && 
            (grid->game_grid[y-1][x]== NONE || grid->game_grid[y-1][x]== GOAL  ))
                grid->player.y--;
            break;
        default :
            break;
    }

}





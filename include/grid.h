/**
 * @file grid.h
 * @author Marcoly ANTOINE/ Adrien GAME
 * @brief header pour la grille
 * @version 0.1
 * @date 2022-11-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GRID_HEADER
#define GRID_HEADER

#include "player.h"
 
/**
 * @enum CaseType
 * déclaration de l'énumération du CaseType
 */
enum CaseType{
	WALL = '#', 	/**< caractère réprésentant un mur **/
	BOX = '$',		/**< caractère réprésentant une boite **/
	PLAYER = '@',	/**< caractère réprésentant le joueur **/
	GOAL = '.',		/**< caractère réprésentant un objectif **/
	NONE = ' '		/**< caractère réprésentant un espace vide **/
};


/**
 * @typedef typedef enum CaseType CaseType 
 * type synonyme de \c enum \c CaseType
 */
typedef enum CaseType CaseType;

/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */
struct Grid{
	enum CaseType** game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid
	int row_number; ///< Nomber de ligne de game_grid
	Player player;///< Joueur 
};

/**
 * @typedef typedef struct Grid Grid
 * @brief type synonyme de \c struct \c Grid
 */
typedef struct Grid Grid;

/**
 * @fn fonction qui initie le niveau de jeu
 * 
 * @param file_path 
 * @param grid Pointeur sur la grille de jeu
 */
void init_level(const char* file_path, Grid* grid);

/**
 * @fn fonction display qui affiche la grille de jeu
 * 
 * @param grid (pointeur sur) La grille de jeu .
 */
void display (Grid *grid);

/**
 * @brief fonction permettant de faire bouger le joueur dans la grille
 * 
 * @param grid une grille de jeu
 * @param direction la direction dans laquelle on souhaite se diriger
 */
void move_player(Grid* grid, enum Direction direction);

/**
 * @fn fonction suppr_grid qui va désallouer l'espace mémoire allouée pour notre jeu
 * 
 * @param grid 
 */
void suppr_grid(Grid * grid);
#endif


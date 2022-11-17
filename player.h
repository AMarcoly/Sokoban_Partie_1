/**
 * @file player.h
 * @author Marcoly ANTOINE/Adrien GAME
 * @brief header pour le joueur
 * @version 0.1
 * @date 2022-11-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

/**
 * @enum Direction
 * \brief declaration de l'énumération des directions
 */
enum Direction{
	Top = 'k',		/**< caractère réprésentant la direction haut **/
	Left = 'h',		/**< caractère réprésentant la direction gauche **/
	Right = 'l',	/**< caractère réprésentant la direction droite **/
	Bottom = 'j'	/**< caractère réprésentant la direction bas **/
};


/**
 * @struct Player
 * @brief déclaration de la structure joueur
 */
struct Player
{
    int x;  ///<x: position du joueur en colonne 
    int y;  ///<y: position du joueur par rapport aux lignes
};

/**
 * @typedef typedef struct Player Player
 * \brief type synonyme de \c struct \c Player
 */
typedef struct Player Player;

#endif

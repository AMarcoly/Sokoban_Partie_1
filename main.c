/**
 * @file main.c
 * @author Marcoly ANTOINE/ Adrien GAME
 * @brief fichier principal 
 * @version 0.1
 * @date 2022-11-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdbool.h>

#include "grid.h"
#include "player.h"

/**
 * @brief Fonction principale du programme
 * 
 * @return int 
 */
int main(void){
	bool start = false; // jeu commencé?
	bool run = true; //booléen pour conditionner l'arrêt de la boucle principale
	printf("Bienvenue dans le jeu sokoban\nTaper r + Entrer pour commencer le jeu\nTaper q + Entrer pour quitter\n");
	while(run){
		char entry = (char)fgetc(stdin);
		Grid grid;
		switch(entry){
			case 'q' :{
				run = false;
				if(start)
					suppr_grid(&grid);
				break;
			}
			case 'r' : {
				start = true;
				init_level("level1.txt",&grid);
				display(&grid);
				printf("Déplacements : h = gauche , j = bas, k = haut , l = droite, r = recommencer le jeu\n");
				break;
				}
			case (char)Right: 
			case (char)Left: 
			case (char)Top: 
			case (char)Bottom: {
				if (start)  // si le jeu n'a pas demarré on ne fait rien
				{
					move_player(&grid,(enum Direction) entry);
					display(&grid);
				}
				break;
			}
			
			case '\n' : break; // pour ne pas tenir conte des retour chariot

			default:{  
				// si aucune touche valide n'a été entrée
				if(start)
				{
					printf("Déplacements : h = gauche , j = bas, k = haut , l = droite , r = recommencer le jeu\n");	
				}
				else{
					printf("Taper r + Entrer pour commencer le jeu\nTaper q + Entrer pour quitter\n");	
				}
				break;
			}	
		}	
	}
}


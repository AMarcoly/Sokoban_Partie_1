/**
 * @file grid.c
 * @author Marcoly ANTOINE/ Adrien GAME
 * @brief Code pour la grille de jeu
 * @version 0.1
 * @date 2022-11-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "grid.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * @fn Fonction qui initialise le niveau pour chaque fichier texte. Il prend en parametre un pointeur sur la grille de jeu et un pointeur sur le fichier contenant le niveau de jeu  
 * 
 * @param file_path un fichier txt lu
 * @param grid une grille de jeu 
 */
void init_level(const char* file_path,Grid* grid){
	// ouverture du fichier en mode lecture
	FILE* file = fopen(file_path, "r");
	if(!file){
		fprintf(stderr, "Error %s not found", file_path);
		exit(-1);
	}
	char line[100] = {0};
	int number_column = 0; // nombre de colonne
	int number_row = 0; /// nombre de ligne
	int number_goals = 0;
	
	// on lit la première ligne du fichier
	fgets(line, 100, file); //Ligne non écrite par nous mais donné
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);
	
	grid->column_number=number_column;
	grid->row_number=number_row;
	grid->game_grid = malloc((unsigned long)number_row*sizeof(CaseType*));
	
	int current_row = 0;
	
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		int current_column = 0;

		grid->game_grid[current_row]=malloc(((unsigned long)number_column*sizeof(CaseType))); //on pointe sur le tableau de casetype 'ligne' 

		while(*buffer && *buffer != '\n'){
			CaseType ct;
			switch (*buffer){
				case '#': ct = WALL;
				break;
				case '$': ct = BOX;
				break;
				case '@': 
				grid->player.x=current_column; ///< on prend x comme abscisse (colonne)
				grid->player.y=current_row; ///< y comme ordonnée
				ct=NONE;
				break;
				case '.': ct = GOAL;
				break;
				default: ct = NONE;
				break;
				
			}
			grid->game_grid[current_row][current_column]=ct;
			current_column += 1;
			buffer += 1;
		}		
		current_row += 1;
	}
	// fermeture du fichier
	fclose(file);
}

/**
 * @fn Fonction qui affiche la grille du Sokoban
 * 
 * @param grid la grille de jeu
 */
void display (Grid* grid){

	for (int i =0; i<grid->row_number;i++){
		for (int j = 0; j < grid->column_number; j++)
		{
			if(i==grid->player.y && j==grid->player.x)
				printf("@");  ///< affichage du joueur
			else
				printf("%c", grid->game_grid[i][j]); ///<affichage du CaseType
		}
		printf("\n");
	}
}

/**
 * @fn Fonction qui désalloue la mémoire allouée dans la fonction init_level 
 * 
 * @param grid la grille de jeu
 */
void suppr_grid (Grid* grid){
	for (int i =0; i<grid->row_number;i++){
		free(grid->game_grid[i]);///< La boucle désalloue le tableau de CaseType de la ligne i
	}
	free(grid->game_grid); ///<désallocation du tableau de lignes
}

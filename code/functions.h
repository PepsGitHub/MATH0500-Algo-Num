/**
 * @file functions.h
 * 
 * @brief Ce fichier contient les déclarations de types et les prototypes
 * des fonctions de functions.c
 *
 * @author Delacollette Guillaume - Université de Liège
 * @author Dumoulin Peissone - Université de Liège
 * @projet: MATH0500-1 Projet première session 2021-2022
 * @date 06/11/21
 * @version 1.0
 */

/*
 * Include guard (pour éviter les problèmes d'inclusions multiples)
 */
#ifndef __FUNCTIONS__
#define __FUNCTIONS__

/**
 * Déclaration de la structure CSparse représentant une matrice creuse sous le format column compressed
 */
typedef struct{
    unsigned long *index_column; //Contient les indices de début de chaque colonne pour les 2 vecteurs suivants
    unsigned long *index_row; //Contient les indices de ligne de chaque élément
    long double *value; //Contient les valeurs de chaque élément
    unsigned long nb_elements; //Nombre d'éléments de la matrice
}CSparse;

/**
 * \fn int load_sparse_matrix(char *matrix_filename)
 * \brief Lis un fichier MatrixMarket puis crée une matrice creuse en format column compressed.
 * 
 * @param matrix_filename le chemin vers le fichier MatrixMarket contenant la matrice.
 *
 * @pre: matrix_filename != NULL
 * @post: la lecture du fichier et la création de la matrice creuse.
 *
 * @return:
 *     0 Succès
 *    -1 Erreur à l'allocation de mémoire
 *    -2 Erreur dans l'ouverture du fichier
 *
 */
int load_sparse_matrix(char *matrix_filename);

#endif // __FUNCTIONS__

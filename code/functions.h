/**
 * @file functions.h
 * 
 * @brief Ce fichier contient les déclarations de types et les prototypes
 * des fonctions de functions.c
 *
 * @author Delacollette Guillaume - Université de Liège
 * @author Dumoulin Peissone - Université de Liège
 * @projet: MATH0500-1 Projet première session 2021-2022
 * @date 15/12/21
 * @version 1.0
 */

/*
 * Include guard (pour éviter les problèmes d'inclusions multiples)
 */
#ifndef __FUNCTIONS__
#define __FUNCTIONS__

/**
 * Déclaration de la structure RowCompressed représentant une matrice creuse sous le format row compressed
 */
typedef struct{
    unsigned long *index_next_element_row; //Contient les indices de début de chaque ligne pour les 2 vecteurs suivants
    unsigned long *index_column; //Contient les indices de colonne de chaque élément
    long double *value; //Contient les valeurs de chaque élément
    unsigned long nb_elements; //Nombre d'éléments de la matrice
}RowCompressed;

/**
 * Déclaration de la structure ColumnCompressed représentant une matrice creuse sous le format column compressed
 */
typedef struct{
    unsigned long *index_next_element_column; //Contient les indices de début de chaque colonne pour les 2 vecteurs suivants
    unsigned long *index_row; //Contient les indices de ligne de chaque élément
    long double *value; //Contient les valeurs de chaque élément
    unsigned long nb_elements; //Nombre d'éléments de la matrice
}ColumnCompressed;

/**
 * \fn int load(char *matrix)
 * \brief Lis une matrice MatrixMarket
 * 
 * @param matrix La matrice L ou U
 *
 * @pre: matrix != NULL
 * @post: Lecture d'une matrice
 *
 * @return:
 *     0 Succès
 *    -1 Erreur à l'allocation de mémoire
 *    -2 Erreur dans l'ouverture d'un fichier
 *
 */
int load_matrix(char *matrix);

/**
 * \fn int load(char *vector)
 * \brief Lis 4 fichiers MatrixMarket
 * 
 * @param vector le vecteur a ou x
 *
 * @pre: vector
 * @post: Lecture des fichiers
 *
 * @return:
 *     0 Succès
 *    -1 Erreur à l'allocation de mémoire
 *    -2 Erreur dans l'ouverture d'un fichier
 *
 */
int load_vector(char *vector);

#endif // __FUNCTIONS__

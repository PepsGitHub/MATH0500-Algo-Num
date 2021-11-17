/**
 * @file functions.c
 *
 * @brief Contient les fonctions demandées dans le cadre du projet de MATH0500-1 (points 1 à 4 du projet)
 *
 * @author Delacollette Guillaume - Université de Liège
 * @author Dumoulin Peissone - Université de Liège
 * @projet: MATH0500-1 Projet première session 2021-2022
 * @date 06/11/21
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#include "functions.h"

int load_sparse_matrix(char *matrix_filename){
    assert(matrix_filename != NULL);

    //Ouverture du fichier
    FILE *fp = fopen(matrix_filename, "r");
    
    //check ouverture de fichier
    if(!fp){
        printf("Erreur dans l'ouverture de la matrice");
        return -2;
    }

    unsigned long nb_rows, nb_columns, nb_elements, *index_row, *index_column;

    long double *value;

    fscanf(fp, "%*[^\n]\n");//Première ligne du fichier à ignorer
    fscanf(fp, "%lu %lu %lu ", &nb_rows, &nb_columns, &nb_elements);//Deuxième ligne du fichier contenant ces informations

    //Allocation dynamique
    long double *matrix;
    matrix = (long double *)calloc(nb_rows * nb_columns, sizeof(long double));
    
    index_column = malloc(nb_columns * sizeof(unsigned long));
    value = malloc(nb_elements * sizeof(long double));
    index_row = malloc(nb_rows * sizeof(unsigned long));

    //check allocation mémoire
    if(!matrix || !index_row || !index_column || !value){
        printf("Erreur dans l'allocation de la mémoire");
        return -1;
    }

    unsigned long i = 0;

    while(fscanf(fp, "%lu %lu %Lf", &index_row[i], &index_column[i], &value[i]) == 3)
        i++;

    printf("\n\n");

    for(unsigned long i = 0; i < nb_elements; i++)
        matrix[(index_row[i] * index_column[i]) - 1] = value[i];

    for(unsigned long i = 0; i < nb_rows * nb_columns; i++)
        printf("%Lf ", matrix[i]);

    //Destructeurs
    free(matrix);
    free(index_row);
    free(index_column);
    free(value);

    fclose(fp);

    return 0;
}

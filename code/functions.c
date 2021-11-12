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

    unsigned long rows, columns, non_zeros;

    fscanf(fp, "%*[^\n]\n");//Première ligne du fichier à ignorer
    fscanf(fp, "%lu %lu %lu ", &rows, &columns, &non_zeros);//Deuxième ligne du fichier contenant ces informations

    double *value;
    unsigned long *index_row, *index_column;

    //Allocation dynamique
    double **matrix;
    matrix = (double **)calloc(rows, sizeof(double*));
    for(unsigned long i = 0; i < rows; i++) 
        matrix[i] = (double *)calloc(columns, sizeof(double));
    
    index_row = malloc(rows * sizeof(unsigned long));
    index_column = malloc(columns * sizeof(unsigned long));
    value = malloc(non_zeros * sizeof(double));

    //check allocation mémoire
    if(!matrix || !index_row || !index_column || !value){
        printf("Erreur dans l'allocation de la mémoire");
        return -1;
    }

    unsigned long i = 0;

    while(fscanf(fp, "%lu %lu %lf", &index_row[i], &index_column[i], &value[i]) == 3)
        i++;

    printf("\n\n");

    /*for(unsigned long i = 0; i < non_zeros; i++)
        printf("%lu ", index_row[i]);

    printf("\n\n");

    for(unsigned long i = 0; i < non_zeros; i++)
        printf("%lu ", index_column[i]);

    printf("\n\n");

    for(unsigned long i = 0; i < non_zeros; i++)
        printf("%f ", value[i]);

    printf("\n\n");*/

    for(unsigned long i = 0; i < non_zeros; i++){
        matrix[index_row[i]][index_column[i]] = value[i];
    }

    for(unsigned long i = 0; i < rows; i++){
        for(unsigned long j = 0; j < columns; j++)
            printf("%lf ", matrix[i][j]);
        printf("\n");
    }
    //Destructeurs
    for(unsigned long i = 0; i < rows; i++) 
        free(matrix[i]);
    free(matrix);
    free(index_row);
    free(index_column);
    free(value);

    return 0;
}

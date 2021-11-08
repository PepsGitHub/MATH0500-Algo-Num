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
    fscanf(fp, "%lu %lu %lu", &rows, &columns, &non_zeros);//Deuxième ligne du fichier contenant ces informations

    double *matrix, *value;
    unsigned long *index_row, *index_column;

    //Allocation dynamique
    matrix = malloc(rows * columns * sizeof(double));
    index_row = malloc(rows * sizeof(unsigned long));
    index_column = malloc(columns * sizeof(unsigned long));
    value = malloc(non_zeros * sizeof(double));

    //check allocation mémoire
    if(!matrix || !index_row || !index_column || !value){
        printf("Erreur dans l'allocation de la mémoire");
        return -1;
    }

    unsigned int i = 0;

    while(fscanf(fp, "%lu %lu %lf", &index_row[i], &index_column[i], &value[i]) == 3)
        i++;

    printf("\n\n");

    for(unsigned long i = 0; i < non_zeros; i++)
        printf("%lu ", index_row[i]);

    printf("\n\n");

    for(unsigned long i = 0; i < non_zeros; i++)
        printf("%lu ", index_column[i]);

    printf("\n\n");

    for(unsigned long i = 0; i < non_zeros; i++)
        printf("%f ", value[i]);

    printf("\n\n");


    /*for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++){
            
        }*/

    //Destructeurs
    free(matrix);
    free(index_row);
    free(index_column);
    free(value);

    /*unsigned long rows, columns, non_zeros, *columns_indexes;

    fscanf(fp, "%*[^\n]\n");//Première ligne du fichier à ignorer
    fscanf(fp, "%lu %lu %lu", &rows, &columns, &non_zeros);//Deuxième ligne du fichier contenant ces informations

    //Allocation dynamique
    CSparse *c = malloc((non_zeros * 2 + 1) * sizeof(unsigned long) + non_zeros * sizeof(long double));
    c->index_row = malloc(non_zeros * sizeof(unsigned long));
    c->index_column = malloc(non_zeros * sizeof(unsigned long));
    c->value = malloc(non_zeros * sizeof(long double));

    columns_indexes = malloc(non_zeros * sizeof(unsigned long));

    //Check allocation dynamique
    if(!c || !columns_indexes){
        printf("Erreur dans l'allocation de la mémoire");
        return -1;
    }

    c->nb_elements = non_zeros;
    //printf("%lu\n", c->nb_elements);

    unsigned int i = 0, start_column_value = 0, j = 0;

    c->index_column[j] = 0;

    //Lecture de la matrice
    while(fscanf(fp, "%lu %lu %Lf", &c->index_row[i], &columns_indexes[i], &c->value[i]) == 3){
        if(i > 0 && c->index_row[i] > c->index_row[i-1]){
            c->index_column[j] = start_column_value;
            printf("%lu ", c->index_column[j]);
            j++;
        }
        //printf("%lu ", c->index_row[i]);
        //printf("%lu ", c->index_column[i]);
        //printf("%ld\n", c->value[i]);
        start_column_value++;
        i++;
    }

    printf("\n\n");

    for(unsigned long i = 0; i < c->nb_elements; i++)
        printf("%lu ", c->index_row[i]);

    printf("\n\n");

    for(unsigned long i = 0; i < c->nb_elements; i++)
        printf("%Lf ", c->value[i]);

    printf("\n\n");

    //Destructeurs
    free(c->index_row);
    free(c->index_column);
    free(c->value);
    free(c);
    free(columns_indexes);*/

    return 0;
}

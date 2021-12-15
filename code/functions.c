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
    
    if(fp == NULL){
        printf("Erreur dans l'ouverture de la matrice");
        return -2;
    }

    unsigned long rows, columns, non_zeros;

    fscanf(fp, "%*[^\n]\n");//Première ligne du fichier à ignorer
    fscanf(fp, "%lu %lu %lu", &rows, &columns, &non_zeros);//Deuxième ligne du fichier contenant ces informations

    //Allocation dynamique
    CSparse *c = malloc((non_zeros * 3 + 1) * sizeof(unsigned long));
    c->index_row = malloc(non_zeros * sizeof(unsigned long));
    c->index_column = malloc(non_zeros * sizeof(unsigned long));
    c->value = malloc(non_zeros * sizeof(long));

    //Check allocation dynamique
    if(!c){
        printf("Erreur dans l'allocation de la mémoire");
        return -1;
    }

    c->nb_elements = non_zeros;
    printf("%lu\n", c->nb_elements);

    unsigned int i = 0;

    //Lecture de la matrice
    while(fscanf(fp, "%lu %lu %ld", &c->index_row[i], &c->index_column[i], &c->value[i]) == 3){
        printf("%lu ", c->index_row[i]);
        printf("%lu ", c->index_column[i]);
        printf("%ld\n", c->value[i]);
        i++;
    }

    //Destructeurs
    free(c->index_row);
    free(c->index_column);
    free(c->value);
    free(c);

    return 0;
}

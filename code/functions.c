/**
 * @file functions.c
 *
 * @brief Contient les fonctions demandées dans le cadre du projet de MATH0500-1 (seulement point 1 du projet)
 *
 * @author Delacollette Guillaume - Université de Liège
 * @author Dumoulin Peissone - Université de Liège
 * @projet: MATH0500-1 Projet première session 2021-2022
 * @date 15/12/21
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#include "functions.h"

int load_matrix(char *matrix){
    assert(matrix);

    //Ouverture du fichier
    FILE *fp = fopen(matrix, "r");
    
    //Check du fichier
    if(!fp){
        printf("Erreur dans l'ouverture de la matrice");
        return -2;
    }

    unsigned long rows, columns, non_zeros;

    fscanf(fp, "%*[^\n]\n");//Première ligne du fichier à ignorer
    fscanf(fp, "%lu %lu %lu", &rows, &columns, &non_zeros);//Deuxième ligne du fichier contenant ces informations

    //Allocation dynamique
    unsigned long *matrix_rows = malloc(non_zeros * sizeof(unsigned long));
    unsigned long *matrix_columns = malloc(non_zeros * sizeof(unsigned long));
    long double *matrix_elements = malloc(non_zeros * sizeof(long double));

    RowCompressed *mR = malloc((non_zeros * 2 + 1) * sizeof(unsigned long) + non_zeros * sizeof(long double));
    mR->index_next_element_row = malloc(non_zeros * sizeof(unsigned long));
    mR->index_column = malloc(non_zeros * sizeof(unsigned long));
    mR->value = malloc(non_zeros * sizeof(long double));

    ColumnCompressed *mC = malloc((non_zeros * 2 + 1) * sizeof(unsigned long) + non_zeros * sizeof(long double));
    mC->index_row = malloc(non_zeros * sizeof(unsigned long));
    mC->index_next_element_column = malloc(non_zeros * sizeof(unsigned long));
    mC->value = malloc(non_zeros * sizeof(long double));

    //Check allocation dynamique
    if(!matrix_rows || !matrix_columns || !matrix_elements || !mR || !mR->index_next_element_row || !mR->index_column|| !mR->value || !mC || !mC->index_row || !mC->index_next_element_column|| !mC->value){
        printf("Erreur dans l'allocation mémoire de la matrice");
        return -1;
    }

    mR->nb_elements = non_zeros;
    mC->nb_elements = non_zeros;

    //Lecture du fichier
    unsigned i = 0;
    while(fscanf(fp, "%lu %lu %Lf", &matrix_rows[i], &matrix_columns[i], &matrix_elements[i]) == 3){
        mR->index_column[i] = matrix_columns[i];
        mR->value[i] = matrix_elements[i];
        i++;
    }

    //printf("La matrice en row compressed :\n\nA.p = [");
    //Vecteur p en row compressed
    unsigned long n = 0;
    for(unsigned long i = 0; i < non_zeros; i++){
        if(i == 0){
            mR->index_next_element_row[i] = 1;
            //printf("%ld ", mR->index_next_element_row[i]);
        }else if(matrix_rows[i] == matrix_rows[i-1]){
            mR->index_next_element_row[i-n] = mR->index_next_element_row[i-1-n] + 2;
            i++;
            n++;
            non_zeros--;
            //printf("%ld ", mR->index_next_element_row[i-n]);
        }else{
            mR->index_next_element_row[i-n] = mR->index_next_element_row[i-1-n] + 1;
            //printf("%ld ", mR->index_next_element_row[i-n]);
        }
    }

    //printf("]\nA.i = [");
    non_zeros = mR->nb_elements;

    //for(unsigned long i = 0; i < mR->nb_elements; i++)
        //printf("%ld ", mR->index_column[i]);

    //printf("]\nA.x = [");

    //for(unsigned long i = 0; i < mR->nb_elements; i++)
        //printf("%Lf ", mR->value[i]);

    //printf("]\n\n");

    //Transposition pour passer de lignes à colonnes
    unsigned long *column_count = calloc(non_zeros, sizeof(unsigned long));
    unsigned long count;
    for(unsigned long k = 0; k < non_zeros; k++){//compte le #d'occurrences de chaque ligne
        count = 0;
        for(unsigned long i = 0; i < mR->nb_elements; i++){
            if(mR->index_column[i] == k + 1){
                count++;
            }
        }
        column_count[k] = count;
        if(count > 1)
           non_zeros--;
    }

    non_zeros = mR->nb_elements;

    //Vecteur p column compressed
    mC->index_next_element_column[0] = 1;
    for(unsigned long i = 1; i < non_zeros; i++){
        mC->index_next_element_column[i] = mC->index_next_element_column[i - 1] + column_count[i - 1];
    }

    //Vecteur i column compressed

    //Destructeurs
    
    free(matrix_rows);
    free(matrix_columns);
    free(matrix_elements);
    free(mR->index_next_element_row);
    free(mR->index_column);
    free(mR->value);
    free(mR);
    free(mC->index_row);
    free(mC->index_next_element_column);
    free(mC->value);
    free(mC);

    //Fermeture du fichier
    fclose(fp);

    return 0;
}

int load_vector(char *vector){
    assert(vector);

    //Ouverture du fichier
    FILE *fp = fopen(vector, "r");
    
    //Check du fichier
    if(!fp){
        printf("Erreur dans l'ouverture du vecteur");
        return -2;
    }

    unsigned long rows, columns, non_zeros;

    fscanf(fp, "%*[^\n]\n");//Première ligne du fichier à ignorer
    fscanf(fp, "%lu %lu %lu", &rows, &columns, &non_zeros);//Deuxième ligne du fichier contenant ces informations

    //Allocation dynamique
    unsigned long *vector_rows = malloc(non_zeros * sizeof(unsigned long));
    unsigned long *vector_columns = malloc(non_zeros * sizeof(unsigned long));
    long double *vector_elements = malloc(non_zeros * sizeof(long double));

    //Check allocation dynamique
    if(!vector_rows || !vector_columns || !vector_elements){
        printf("Erreur dans l'allocation mémoire du vecteur");
        return -1;
    }

    //printf("Vecteur :\n[");

    unsigned l = 0;
    while(fscanf(fp, "%lu %lu %Lf", &vector_rows[l], &vector_columns[l], &vector_elements[l]) == 3){
        //printf("%Lf ", vector_elements[l]);
        l++;
    }

    //printf("]\n\n");

    //Destructeurs
    free(vector_rows);
    free(vector_columns);
    free(vector_elements);

    //Fermeture des fichiers
    fclose(fp);

    return 0;
}
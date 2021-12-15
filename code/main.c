/**
 * @file main.c
 *
 * @brief Ce fichier est le point d'entrée du programme
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
#include <getopt.h>
#include <string.h>
#include <stdbool.h>

#include "functions.h"

int main(int argc, char **argv){

    char *matrix_L = NULL, *matrix_U = NULL, *vector_x = NULL, *vector_a = NULL, *optstring = ":L:U:x:a:";

    int val;
    while((val = getopt(argc, argv, optstring)) != EOF){
        switch(val){
        case 'L':
            matrix_L = optarg;
            printf("Nom du fichier contenant la matrice L: %s\n", matrix_L);
            break;
        case 'U':
            matrix_U = optarg;
            printf("Nom du fichier contenant la matrice U: %s\n", matrix_U);
            break;
        case 'x':
            vector_x = optarg;
            printf("Nom du fichier contenant le vecteur x: %s\n", vector_x);
            break;
        case 'a':
            vector_a = optarg;
            printf("Nom du fichier contenant le vecteur a: %s\n\n", vector_a);
            break;
        case '?':
            printf("Option inconnue: %c\n", optopt);
            return -1;
        case ':':
            printf("Veuillez spécifier un nom de fichier: %c\n", optopt);
            return -2;
        }
    }
    load_matrix(matrix_L);
    load_matrix(matrix_U);
    load_vector(vector_a);
    load_vector(vector_x);

    return EXIT_SUCCESS;
}

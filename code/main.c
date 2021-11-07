/**
 * @file main.c
 *
 * @brief Ce fichier est le point d'entrée du programme
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
#include <getopt.h>
#include <string.h>
#include <stdbool.h>

#include "functions.h"

int main(int argc, char **argv){

    char *matrix_filename = NULL, *optstring = ":f:";

    int val;
    while((val = getopt(argc, argv, optstring)) != EOF){
        switch(val){
        case 'f':
            matrix_filename = optarg;
            printf("Nom du fichier contenant la matrice: %s\n", matrix_filename);
            break;
        case '?':
            printf("Option inconnue: %c\n", optopt);
            return -1;
        case ':':
            printf("Veuillez spécifier un nom de fichier: %c\n", optopt);
            return -2;
        }
    }
    load_sparse_matrix(matrix_filename);

    return EXIT_SUCCESS;
}

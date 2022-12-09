/*
**  Filename : count.c
**
**  Made by : Hugo
**
**  Description : File that contains all the functions to count the number of items
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "count.h"
#define MAX_SIZE 255

int count(FILE *f) {

    int counter = 0;
    char fileLine[MAX_SIZE];
    
    rewind(f);
     while (fgets(fileLine, MAX_SIZE, f) != NULL)
    {
        if (strstr(fileLine, "name") != NULL)
        {
            counter += 1;
        }
        
    }
    return counter;
}

void addCount(FILE *f) {

    rewind(f);
    fprintf(f, "{%d}\n", count(f));
}


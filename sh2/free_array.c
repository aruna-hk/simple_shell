#include "main.h"

void free_string_array(char **array)
{
	int i = 0;
    if (array == NULL)
        return;

    for (i = 0; array[i] != NULL; i++) {
        free(array[i]);     }
    
    free(array); }


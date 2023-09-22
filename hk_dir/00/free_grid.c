#include "main.h"
/**
* freegrid --free array
* @arr: array to free
*/
void freegrid(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

#include "main.h"
/**
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

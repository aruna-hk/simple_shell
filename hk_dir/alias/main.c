#include "main.h"
int main()
{
	char *l;
	ssize_t nread;
	size_t n_read;
	while (1)
	{
		n_read = getline(&line, nread, stdin)
		if (n_read == -1)
			break;
	}
	return (0);
}

#include "philos.h"

int	error_message(char *msg)
{
	int	index;

	index = 0;
	while (msg[index])
		index++;
	write(1, "Error: ", 7);
	write(1, msg, index);
	write(1, "\n", 1);
	return (1);
}

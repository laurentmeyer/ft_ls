//#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARG_l (1 << 0)
#define ARG_R (1 << 1)
#define ARG_a (1 << 2)
#define ARG_r (1 << 3)
#define ARG_t (1 << 4)


int		main (int argc, char **argv)
{
	int		flags;
	char	*cvalue;
	int		index;
	int		c;

	flags = 0;
	opterr = 0;
	while ((c = getopt (argc, argv, "lRart")) != -1)
	{
		if (c == '?')
			fprintf (stderr, "? error\n");
		else if (c == ':')
			fprintf (stderr, ": error\n");
		else
			flags |= (c == 'l') * ARG_l | (c == 'R') * ARG_R | (c == 'a') *
			   	ARG_a | (c == 'r') * ARG_r | (c == 't') * ARG_t;
	}
	printf ("l flag = %d, R flag = %d, a flag = %d\n",
			((flags & ARG_l) != 0),
			((flags & ARG_R) != 0),
			((flags & ARG_a) != 0));

	for (index = optind; index < argc; index++)
		printf ("Non-option argument %s\n", argv[index]);
	return 0;
}

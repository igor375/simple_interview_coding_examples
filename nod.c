#include <stdio.h>
#include <stdlib.h>

int nod(int a, int b)
{
	return (!b) ? a : nod(b, a % b);
}

int main(int argc, char **argv)
{
	printf("%i\n\n", nod(atoi(argv[1]), atoi(argv[2])));
	
	return 0;
}

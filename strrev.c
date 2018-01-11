#include <stdio.h>

void strrev(char *s)
{
	char *e = s;
	for(; *e; e++);
	e--;
	while (e > s) {
		*e = *e ^ *s;
		*s = *e ^ *s;
		*e-- = *e ^ *s++;
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return -1;
	printf("%s\n", argv[1]);
	strrev(argv[1]);
	printf("%s\n", argv[1]);
	return 0;
}

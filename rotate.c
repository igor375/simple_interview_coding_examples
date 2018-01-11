#include <stdio.h>

#define N 5
int c[][N] = {
	{ 0, 1, 2, 3, 4 },
	{ 0, 1, 2, 3, 4 },
	{ 0, 1, 2, 3, 4 },
	{ 0, 1, 2, 3, 4 },
	{ 0, 1, 2, 3, 4 }};

void rotate_90()
{
	for (int layer = 0; layer < N / 2; layer++) {
		int first = layer;
		int last = N - 1 - layer;
		for(int i = first; i < last; ++i) {
			int offset = i - first;
			int top = c[first][i]; // save top
			// left -> top
			c[first][i] = c[last-offset][first]; 			
			// bottom -> left
			c[last-offset][first] = c[last][last - offset];
			// right -> bottom
			c[last][last - offset] = c[i][last];
			// top -> right
			c[i][last] = top; // right <- saved top
		}
	}
}

void print_cube()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d", c[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	for (int i = 0; i < 4; i++) {
		rotate_90();
		print_cube();
	}
	return 0;
}

// Ханойские башни
#include <stdio.h>
#include <stdlib.h>

static int move_count;
//quantity-число колец, from-начальное положение колец(1-3),to-конечное положение колец(1-3)
//buf_peg - промежуточный колышек(1-3)
void hanoi(int quantity, int from, int to, int buf_peg)
{
	if (!quantity)
       		return;
	hanoi(quantity-1, from, buf_peg, to);
	printf("from %d to %d\n", from, to);
	move_count++;
	hanoi(quantity-1, buf_peg, to, from);
}

int main(int argc, char **argv)
{
	int start_peg = 1, destination_peg = 3, buffer_peg = 2, plate_quantity = 8;

	if (argc > 1)
		plate_quantity = atoi(argv[1]);
	hanoi(plate_quantity, start_peg, destination_peg, buffer_peg);
	printf("Moves: %d\n", move_count);
        return 0;
}

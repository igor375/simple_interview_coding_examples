#include <stdio.h>

int cnt = 10;
int a[] =   {1, 2, 3, 4, 9, 8, 7, 6, 10, 11};
int bsa[] = {0, 2, 3, 4, 5, 7, 8, 9, 13, 20};

void xcng(int i, int j)
{
	int tmp = a[j];
	a[j] = a[i];
	a[i] = tmp;

	a[i] = a[i] ^ a[j];
	a[j] = a[i] ^ a[j];
	a[i] = a[i] ^ a[j];

	a[i] = a[i] + a[j];
	a[j] = a[i] - a[j];
	a[i] = a[i] - a[j];
}

void _simple_sort()
{
	int i, j;
	for (i = 0; i < cnt-1; i++)
		for (j = i; j < cnt; j++)
		       if (a[i] > a[j])
				xcng(i, j);
}

void simple_sort(void)
{
	_simple_sort();
	printf("\nSort result:\n");
	for (int i = 0; i < cnt; i++)
		printf("\t%d", a[i]);
}

// returns index of last element not greater then s_val
int _b_search(int s_val)
{
	int start_ind = 0, end_ind = cnt - 1;
	for(;;) {
		if (s_val >= a[end_ind])
			return end_ind;
		if (s_val <= a[start_ind])
			return start_ind;
		int m_ind = (start_ind + end_ind)/2;
		if (m_ind == start_ind)
			return start_ind;
		if (s_val > a[m_ind])
			start_ind = m_ind;
		else
			end_ind = m_ind;
	}
}

void b_search(void)
{
	printf("\nBinary search results:\n");
	for (int i = 0; i < cnt; i++)
		printf("\t%d%s", bsa[i],
		       a[_b_search(bsa[i])] == bsa[i] ? "y" : "n" );
}

int main(void)
{
	simple_sort();
	b_search();
	printf("\n");

	return 0;
}

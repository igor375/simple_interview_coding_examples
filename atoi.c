#include <stdio.h>
#include <string.h>

int solution(char *S) {
	int x = strlen(S), negative = 0;
	int i;
	long long int val = 0;

	for(i = 0; i < x; i++)
		if(S[i] == '0' || S[i] == ' ')
			continue;
		else
			break;
	S = &S[i];

	if(S[0] == '+' || S[0] == '-') {
		negative = (S[0] == '-');
		S = &S[1];
	}

	for(; *S; S++) {
		if(*S >= '0' && S[i] <= '9') {
			val = val * 10 + (*S - '0');

			if((negative && ((0 - val) < (1 << 31))) || (!negative && (val > ~(1 << 31))))
				return 0;
		} else
			return 0;

	}
	return negative ? 0 - val : val;
}

void main(void) {
	printf("%d\n", solution("1999912345"));
	printf("%d\n", solution(" -  12345"));
	printf("%d\n", solution(" 12345"));
	printf("%d\n", solution("-00012345"));
	printf("%d\n", solution("-12345"));
}

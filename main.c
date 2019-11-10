#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main (void)
{
	int scores[5];
	int i;
	
	for (i=0; i<5; i++)
		printf("scores[%d]= %d\n", i, scores[i]);
	
	return 0;	
}

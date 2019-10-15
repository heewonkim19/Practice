#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* Calculation factorial */

int factorial (int n)	
{	int i;
	int result=1;
	for (i=1; i<=n; i++)
		result*=i;
	return result;
}

int main(int argc, char *argv[]) {
	
	int n;
	printf ("input 'n'");
	scanf ("%d",&n);
	
	printf ("Result is %d", factorial (n));
	
	return 0;
}


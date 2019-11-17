#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
static int i=1;
int fib(int n)
{
	i++;
	if (i>n)
		return ;
	else
		return printf("fib(%d)=fib(%d)+ fib(%d)", i, i-2, i-1 );
}
int main(void)
{
	int n;
	printf("수를 입력하세요: ");
	scanf("%d", &n);
	printf("fib(0)=0\nfib(1)=1");
	printf("%d", fib(n));
	
	return 0;
}

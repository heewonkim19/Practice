#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* calculation program */
int main(int argc, char *argv[]) 
{
	int x,y,result;
	char op;
	
	printf("input equation:\n");
	scanf("%d %c %d", &x, &op, &y);
	
	switch (op)
	{
		case '+':
			result = x + y;
			break;
		case '-':
			result = x - y;
			break;
		case '*':
			result = x * y;
  			break;		
		case '/':
			result = x / y;
			break;
		case '%':
			result = x % y;
			break;
		default:
			printf("Unsupported operator.");
			break;
	}	
	printf("%d %c %d = %d\n", x, op, y, result);
	return 0;
				
		  
}


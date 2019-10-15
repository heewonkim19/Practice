#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* The number of Days of Month*/ 
int main(int argc, char *argv[]) {
	
	int month, days;
	printf("input a month");
	scanf("%d", &month);

	switch (month)
	{
		case 1:
			printf("Day is 31.");
		break;
		case 3:
			printf("Day is 31.");
		break;
		case 5:
			printf("Day is 31.");
		break;
		case 7:
			printf("Day is 31.");
		break;
		case 8:
			printf("Day is 31.");
		break;
		case 10:
			printf("Day is 31.");
		break;
		case 12:	
			printf("Day is 31.");
		break;
		case 2:
			printf("Day is 28.");
		break;
		default:
			printf("Day is 30.");
				
	}
	return 0;
}


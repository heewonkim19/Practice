#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* Rock_Paper_scissors */
int main(int argc, char *argv[]) 
{
	int user;
	int computer;
	
	computer = (rand()%3+1);
	printf("choice a number(1:scissors, 2:rock, 3:paper): ");
	scanf("%d", &user);
	
	if(user+computer!= 4)
	{
		if (user>computer)
			printf("winner is user.\n");
		else if (user<computer)
			printf("winner is computer.\n");
		else
			printf("user = computer.\n");
	}
	else if (user+computer == 4)
	{
		if (user<computer)
			printf("winner is user.\n");
		else if (user>computer)
			printf("winner is computer.\n");
		else
			printf("user = computer.\n");
	}	 
	
	printf("user= %d | computer= %d", user, computer);
	

	return 0;

}

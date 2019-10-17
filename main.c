#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* Change Calculation Program */
int main(int argc, char *argv[]) 
{
	int price;
	int user;
	int change;
	int c10000, c5000, c1000, c500, c100, c50, c10;
	printf("input a price:");
	scanf("%d", &price);
	printf("input a money:");
	scanf("%d", &user);	  
	change = user - price;
	
	c10000 = change / 10000;
	change %= 10000;
	
	c5000 = change / 5000;
	change %= 5000;
	
	c1000 = change / 1000;
	change %= 1000;
	
	c500 = change / 500;
	change %= 500;
	
	c100 = change / 100;
	change %= 100;
	
	c50 = change / 50;
	change %= 50;
	
	c10 = change / 10;
	change %= 10;
	
	printf("10000 : %d\n", c10000);
	printf("5000 : %d\n", c5000);
	printf("1000 : %d\n", c1000);
	printf("500 : %d\n", c500);
	printf("100 : %d\n", c100);
	printf("50 : %d\n", c50);
	printf("10 : %d\n", c10);
	
	return 0;
}


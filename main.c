#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* ID & PASSWORD */
int main(int argc, char *argv[]) {
	
	int ID;
	int PASSWORD;
	
	printf ("please enter ID and PASSWODR in 4 number: \n");
	printf ("ID: ____\b\b\b\b");
	scanf ("%d", &ID);
	printf ("PASSWORD: ____\b\b\b\b");
	scanf ("%d", &PASSWORD);
	printf ("\aID is \"%d\"and PASSWORD is \"%d\".\nRight?", ID, PASSWORD);
	return 0;
}


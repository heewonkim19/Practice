#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/* sun_light */
int main(int argc, char *argv[]) {
    
	double light_speed = 300000;
    double distance = 149600000;
    
    int time;
    int minute;
    int second;
    time = distance / light_speed;
	minute = time / 60;
	second = time % 60; 
	
	printf("light_speed is %fkm \n", light_speed);
	printf("distance is %f km \n", distance);
	printf("time is %dminute %dsecond.\n",minute, second );

	return 0;
}


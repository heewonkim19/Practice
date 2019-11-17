#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void add(double x, double y);
void mul(double x, double y);
void div(double x, double y);
void sub(double x, double y);
int disp_menu();
double get_number();

int main(int argc, char *argv[]) 
{	
	int a;
	double x,y;

	
	a = disp_menu();	

	x= get_number();
	y= get_number();
	

	if (a==1)
		add(x,y);
	else if (a==2)
		sub(x,y);
	else if (a==3)
		mul(x,y);
	else if (a==4)
		div(x,y);
	
	return 0;
}

double get_number()
{
	double n;
	printf("실수를 입력하세요: ");
	scanf("%lf", &n);
	
	return n; 
}

int disp_menu()
{	
	int menu;
	printf("1---덧셈\n");
	printf("2---뺄셈\n");
	printf("3---곱셈\n");
	printf("4---나눗셈\n"); 
	printf("메뉴를 입력하세요: ");
	scanf("%d", &menu);

	return menu; 
}	

void add(double x, double y)
{
	double result;

	result = x+y; 
	
	printf(" 값은 %lf입니다. ", result);
}

void mul(double x, double y)
{
	double result;

	result = x*y; 
	
	printf(" 값은 %lf입니다. ", result);
}

void div(double x, double y)
{
	double result;

	result = x/y; 

	printf(" 값은 %lf입니다. ", result);	
}

void sub(double x, double y)
{
	double result;

	result = x-y; 
	printf(" 값은 %lf입니다. ", result);
}
	


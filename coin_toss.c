#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int x,y,result;
char op;
int count, over;

int add(x,y)
{
	result= x+y;
	count++;
	printf("덧셈은 총 %d번 실행되었습니다.", count);
	return result;
}
int sub(x,y)
{
	result= x-y;
	count++;
	printf("뺄셈은 총 %d번 실행되었습니다. ", count);
	return result;
}
int mul(x,y)
{
	result= x*y;
	count++;
	printf("곱셈은 총 %d번 실행되었습니다. ", count);
	return result;
}
int div(x,y)
{
	result= x/y;
	count++;
	printf("나눗셈은 총 %d번실행되었습니다. ", count);
	return result;
}
int per(x,y)
{
	result= x%y;
	count++;
	printf("나머지는 총 %d번 실행되었습니다. ", count);
	return result;
}
int get(over)
{

	printf("연산을 입력하세요: ");
	scanf("%d %c %d", &x, &op, &y);
	
	if(op=='+')
		result=add(x,y);
	else if (op=='-')
		result=sub(x,y);
	else if (op=='*')
		result=mul(x,y);
	else if (op=='/')
		result=div(x,y);
	else if (op=='%')
		result=per(x,y);
	else 
		printf("지원되지 않은 연산자입니다.\n");
	
	printf("\n연산결과: %d\n", result);
	
	printf("\n계속 하시겠습니까?(1 or 0): " );
	scanf("&d", &over);
	
	return over;
		
}
int main(void)
{
	static int count;
	char con;
	do{
	get(over);
	}while(get(over)==1);

	return 0;
}

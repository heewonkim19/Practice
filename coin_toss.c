#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int x,y,result;
char op;
int count, over;

int add(x,y)
{
	result= x+y;
	count++;
	printf("������ �� %d�� ����Ǿ����ϴ�.", count);
	return result;
}
int sub(x,y)
{
	result= x-y;
	count++;
	printf("������ �� %d�� ����Ǿ����ϴ�. ", count);
	return result;
}
int mul(x,y)
{
	result= x*y;
	count++;
	printf("������ �� %d�� ����Ǿ����ϴ�. ", count);
	return result;
}
int div(x,y)
{
	result= x/y;
	count++;
	printf("�������� �� %d������Ǿ����ϴ�. ", count);
	return result;
}
int per(x,y)
{
	result= x%y;
	count++;
	printf("�������� �� %d�� ����Ǿ����ϴ�. ", count);
	return result;
}
int get(over)
{

	printf("������ �Է��ϼ���: ");
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
		printf("�������� ���� �������Դϴ�.\n");
	
	printf("\n������: %d\n", result);
	
	printf("\n��� �Ͻðڽ��ϱ�?(1 or 0): " );
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

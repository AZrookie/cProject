#include<stdio.h>
 
int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;                  //���㺯�� 
}
int Mul(int a, int b)
{
	return a * b;
}
int Div(int a, int b)
{
	return a / b;
	
}
 
void menu()
{
	printf("****************************\n");
	printf("***** 1.add      2.sub *****\n");
	printf("***** 3.mul      4.div *****\n");    
	printf("******     0.exit      *****\n");
	printf("****************************\n");
}
int main()
{
	int input = 1;//�����ʼֵΪ1����֤��������� 
	int x = 0;
	int y = 0;
	int ret = 0;
	int(*p[5])(int, int) = { 0, Add, Sub, Mul, Div }; //int(*P)(int,int)��ָ��һ�������ķ���ֵ(��������ķ���ֵ�Ǹ�����ֵ)����int(*p[5])��һ��ָ�����飬��������5��ָ��Ԫ�� 
	while (input)//��inputΪ�棬��input��ֵΪ1�ǻ�һֱѭ��������ÿ�����´򿪳�������0ʱ���� 
	{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);//sacnf_s����һ���÷�����&input����һ�������������û������ģ���ֹ���������Խ�� 
		if (input >= 1 && input <= 4)
		{
			printf("������������");
			scanf_s("%d%d", &x, &y);
			ret = p[input](x, y);//�����p[input]��ʵ�ǵ�ַp[input]==����������Ϊ���������൱�ں������ڴ��еĵ�ַ 
			printf("ret = %d\n", ret);
		}
	}
	return 0;
}


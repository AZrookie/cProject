#include<stdio.h>
 
int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;                  //运算函数 
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
	int input = 1;//定义初始值为1，保证进入计算器 
	int x = 0;
	int y = 0;
	int ret = 0;
	int(*p[5])(int, int) = { 0, Add, Sub, Mul, Div }; //int(*P)(int,int)是指向一个函数的返回值(这个函数的返回值是个整型值)，而int(*p[5])是一个指针数组，里面存放了5个指针元素 
	while (input)//当input为真，即input的值为1是会一直循环，以免每次重新打开程序，输入0时结束 
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);//sacnf_s是另一种用法，在&input后还有一个参数，是设置缓冲区的，防止输入的数据越界 
		if (input >= 1 && input <= 4)
		{
			printf("输入两个数：");
			scanf_s("%d%d", &x, &y);
			ret = p[input](x, y);//这里的p[input]其实是地址p[input]==函数名，因为函数名就相当于函数在内存中的地址 
			printf("ret = %d\n", ret);
		}
	}
	return 0;
}


#include<stdio.h>
void shizi(double x,double y);		//负责打印式子
void result(double x,double y);		//负责打印结果
struct Love{		
	double shi,xu;	//表示实部，虚部
}love1,love2;
int main()
{	
	scanf("%lf%lf%lf%lf",&love1.shi,&love1.xu,&love2.shi,&love2.xu);
	//下面的计算根据复数的实部与虚部计算公式：
	//求加法的实部与虚部值
	double jia_shi = love1.shi + love2.shi;
	double jia_xu  = love1.xu  + love2.xu;

	//求减法的实部与虚部值
	double jian_shi = love1.shi - love2.shi;
	double jian_xu  = love1.xu  - love2.xu;

	//求乘法的实部与虚部值
	double cheng_shi = love1.shi*love2.shi-love1.xu*love2.xu;
	double cheng_xu  = love1.xu*love2.shi+love1.shi*love2.xu;
	
	//求除法的实部与虚部值
	double chu_shi = (love1.shi*love2.shi+love1.xu*love2.xu)/(love2.shi*love2.shi+love2.xu*love2.xu);
	double chu_xu  = (love1.xu*love2.shi-love1.shi*love2.xu)/(love2.shi*love2.shi+love2.xu*love2.xu);
	
	//因为题目的输出结果要分多种情况，那就在函数里来判断情况输出吧
	
	//加法
	shizi(love1.shi,love1.xu);	//式子
	printf(" + ");
	shizi(love2.shi,love2.xu);	//式子
	printf(" = ");
	result(jia_shi,jia_xu);		//结果

	//减法
	shizi(love1.shi,love1.xu);	//式子
	printf(" - ");
	shizi(love2.shi,love2.xu);	//式子
	printf(" = ");
	result(jian_shi,jian_xu);		//结果
	
	//乘法
	shizi(love1.shi,love1.xu);	//式子
	printf(" * ");
	shizi(love2.shi,love2.xu);	//式子
	printf(" = ");
	result(cheng_shi,cheng_xu);		//结果

	//除法
	shizi(love1.shi,love1.xu);	//式子
	printf(" / ");
	shizi(love2.shi,love2.xu);	//式子
	printf(" = ");
	result(chu_shi,chu_xu);		//结果
	return 0;
}
void shizi(double x,double y)		//负责打印式子
{
	if(y<0)							//虚部为负数的时候不用加'+'号
		printf("(%.1lf%.1lfi)",x,y);
	else
		printf("(%.1lf+%.1lfi)",x,y);	//反之成立
}
void result(double rshi,double rxu)
{	
	//虚部不存在时，只需输出实部
	if(rxu<=0.05&&rxu>=-0.05)	//其实这里也判断了两段都没有的情况，输出0.0
		printf("%.1lf\n",rshi);
	else if(rshi<=0.05&&rshi>=-0.05)	//实部不存在时，输出虚部单个即可
		printf("%.1lfi\n",rxu);
	else if(rxu<0)
		printf("%.1lf%.1lfi\n",rshi,rxu);	//结果虚部为负数的时候不用加'+'号
	else
		printf("%.1lf+%.1lfi\n",rshi,rxu);	//反之成立
}

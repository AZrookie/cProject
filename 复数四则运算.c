#include<stdio.h>
void shizi(double x,double y);		//�����ӡʽ��
void result(double x,double y);		//�����ӡ���
struct Love{		
	double shi,xu;	//��ʾʵ�����鲿
}love1,love2;
int main()
{	
	scanf("%lf%lf%lf%lf",&love1.shi,&love1.xu,&love2.shi,&love2.xu);
	//����ļ�����ݸ�����ʵ�����鲿���㹫ʽ��
	//��ӷ���ʵ�����鲿ֵ
	double jia_shi = love1.shi + love2.shi;
	double jia_xu  = love1.xu  + love2.xu;

	//�������ʵ�����鲿ֵ
	double jian_shi = love1.shi - love2.shi;
	double jian_xu  = love1.xu  - love2.xu;

	//��˷���ʵ�����鲿ֵ
	double cheng_shi = love1.shi*love2.shi-love1.xu*love2.xu;
	double cheng_xu  = love1.xu*love2.shi+love1.shi*love2.xu;
	
	//�������ʵ�����鲿ֵ
	double chu_shi = (love1.shi*love2.shi+love1.xu*love2.xu)/(love2.shi*love2.shi+love2.xu*love2.xu);
	double chu_xu  = (love1.xu*love2.shi-love1.shi*love2.xu)/(love2.shi*love2.shi+love2.xu*love2.xu);
	
	//��Ϊ��Ŀ��������Ҫ�ֶ���������Ǿ��ں��������ж���������
	
	//�ӷ�
	shizi(love1.shi,love1.xu);	//ʽ��
	printf(" + ");
	shizi(love2.shi,love2.xu);	//ʽ��
	printf(" = ");
	result(jia_shi,jia_xu);		//���

	//����
	shizi(love1.shi,love1.xu);	//ʽ��
	printf(" - ");
	shizi(love2.shi,love2.xu);	//ʽ��
	printf(" = ");
	result(jian_shi,jian_xu);		//���
	
	//�˷�
	shizi(love1.shi,love1.xu);	//ʽ��
	printf(" * ");
	shizi(love2.shi,love2.xu);	//ʽ��
	printf(" = ");
	result(cheng_shi,cheng_xu);		//���

	//����
	shizi(love1.shi,love1.xu);	//ʽ��
	printf(" / ");
	shizi(love2.shi,love2.xu);	//ʽ��
	printf(" = ");
	result(chu_shi,chu_xu);		//���
	return 0;
}
void shizi(double x,double y)		//�����ӡʽ��
{
	if(y<0)							//�鲿Ϊ������ʱ���ü�'+'��
		printf("(%.1lf%.1lfi)",x,y);
	else
		printf("(%.1lf+%.1lfi)",x,y);	//��֮����
}
void result(double rshi,double rxu)
{	
	//�鲿������ʱ��ֻ�����ʵ��
	if(rxu<=0.05&&rxu>=-0.05)	//��ʵ����Ҳ�ж������ζ�û�е���������0.0
		printf("%.1lf\n",rshi);
	else if(rshi<=0.05&&rshi>=-0.05)	//ʵ��������ʱ������鲿��������
		printf("%.1lfi\n",rxu);
	else if(rxu<0)
		printf("%.1lf%.1lfi\n",rshi,rxu);	//����鲿Ϊ������ʱ���ü�'+'��
	else
		printf("%.1lf+%.1lfi\n",rshi,rxu);	//��֮����
}

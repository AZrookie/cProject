#include <stdio.h>
#include <stdlib.h>

#define bf 34 


int main(int argc, char *argv[]) {
FILE *fp ,*fp1;
fp=fopen("D:\\test.txt","w");
char buf[bf]={"this is fputs function!\n"};
fputs(buf,fp); 
fp1=fopen("D:\\test1.txt","w+");
char buf1[bf]={"this us puts function1!"};
fputs(buf1,fp1);

FILE *fp2;
fp2=fopen("D:\\test2.txt","w+");
fputs(buf,fp2);
long location = ftell(fp2);//ftell�������ص��ǵ�ǰ�ļ�ָ���λ�ã����ֽ�������long���ͱ�ʾ 
fseek(fp2,location,SEEK_SET);//fseek�������Խ�ָ���λ���ƶ�ָ�����ֽ�����ע����long���ͣ��������ֽ������L 
fputs(buf1,fp2);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
FILE *fp;
fp=fopen("D:\\test.txt","r");
char buf[45];
fgets(buf,23,fp);
//fgets�ĸ�ʽ�ǻ��������֣����������ȣ��ļ���ַ������fgetsһ��ֻ�ܴ�һ�е��ַ�����Ҫ��ȡ�����ַ������͵�д�϶��gets 
//����ʹ��ѭ����������
//while(fgets(buf,20,fp)){
//	printf("%s",buf);
//} 
//fgets������ʱ����Զ���ת����һ�У����û�оͻ᷵�ؿ�ֵ��ѭ������ 
if(NULL==fp){
	printf("���ļ�ʧ��"); 
}
else{
	printf("%s",buf);
} 
fclose(fp);

	return 0;
}

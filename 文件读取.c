#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
FILE *fp;
fp=fopen("D:\\test.txt","r");
char buf[45];
fgets(buf,23,fp);
//fgets的格式是缓冲区名字，缓冲区长度，文件地址，并且fgets一次只能打开一行的字符，想要获取多行字符串，就得写上多个gets 
//或者使用循环读入数组
//while(fgets(buf,20,fp)){
//	printf("%s",buf);
//} 
//fgets结束的时候会自动跳转到下一行，如果没有就会返回空值，循环结束 
if(NULL==fp){
	printf("打开文件失败"); 
}
else{
	printf("%s",buf);
} 
fclose(fp);

	return 0;
}

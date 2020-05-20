#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int hanio(int n,char x,char y,char z,int cnt);
int main(int argc, char *argv[]) {
	int cnt=0,num;
	printf("请输入汉诺塔的层数");
	scanf("%d",&num);
	cnt=hanio(num,'A','B','C',cnt);
	return 0;
}int hanio(int n,char x,char y,char z,int cnt){
	if(1==n){
		cnt++;
		printf("第%d步:%c-->%c",cnt,x,z);
		return cnt;
	}
	else{
		cnt=hanio(n-1,x,z,y,cnt);
		cnt++;
		printf("第%d步：%c-->%c\n",cnt,x,z);
		cnt=hanio(n-1,y,x,z,cnt);
		return cnt;
	}
}

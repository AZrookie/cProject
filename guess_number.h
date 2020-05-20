int main(int argc, char *argv[]) 
{srand(time(0));
int number=rand()%100+1;
int count=0;
int a=0;
printf("我已经想好了一个1到100的数");
do {
printf("猜猜这个数");
scanf("%d",&a);
count ++;
if(a>number) {
	printf("你猜的数大了Ë"); 
} else if (a<number) {
	printf("你猜的数小了");
} 
   }while (a!=number);
 printf("你用了%d次就猜到了答案",count); 
	return 0;}

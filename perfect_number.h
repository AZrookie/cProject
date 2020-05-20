
int perfect_number(int m,int n) {
int i,sum=0,j,T;
	for(i=m;i<=n;i++){
	            sum=0;
		for(j=1;j<i;j++){
			if(i%j==0){
				sum+=j;
			}
		}
	     if(sum==i){
	        T=sum;
		 printf("%d = 1 ",T);
		 for(i=2;i<T;i++){
		 	if(T%i==0){
		 		printf("+ %d ",i);
			 }
		 } 
			     printf("\b");
			     printf("\n");
		 }
	}
	return 0;
}
/*
输入两个数m，n，函数会输出两数间的所有完数
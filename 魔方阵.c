#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	
	return 0;
}
void mofangz(){
	int N,a[20][20];
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			a[i][j]=0;
		}
	}
	
	a[0][N/2]=1;
	
	i=0;j=0;
	
	for(x=1;x<=N*N;x++){
		if(i==0){
			a[N-1][j++]=x;
		}
		else if(j==N-1){
			a[i--][0];
		}
		else if()
	}
	
} 

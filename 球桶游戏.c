#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
struct keg{
	int red,black,white,number;  //定义结构体，编号，红，黑，白 
};

struct keg ball_keg[40];
struct keg Max[40];  
struct keg t[40];            //定义两个相同结构体，最后赋值用 
int n,i;
scanf("%d",&n);
for (i=0;i<n;i++){
	ball_keg[i].red=10;
	ball_keg[i].black=10;
	ball_keg[i].white=10;
	ball_keg[i].number=i+1;
}

int location,T,i1,t1,t2;
char action[14];
printf("请输入T：");
scanf("%d",&T);
int c,c1,c2,c3,c4,c5;

	printf("location与操作用空格隔开");
for (i1=0;i1<T;i1++){
scanf("%d %s",&location,&action);
if(strcmp(action,"putleft")==0&&location>=1&&(ball_keg[location-1].red)!=0){
	ball_keg[location-2].white=ball_keg[location-1].white+ball_keg[location-2].white;
	ball_keg[location-1].white=0;
	ball_keg[location-2].red=ball_keg[location-2].red+1;
	ball_keg[location-1].red=ball_keg[location-1].red-1;
   } 
   
else if(strcmp(action,"putleft")==0&&(location>=1&&ball_keg[location-1].red==0))
   continue;
else if(strcmp(action,"putright")==0&&(location)<=20&&ball_keg[location-1].red!=0){
	ball_keg[location].black=ball_keg[location].black+ball_keg[location-1].black;
	ball_keg[location-1].black=0;
	ball_keg[location].red=ball_keg[location].red+1;
	ball_keg[location-1].red=ball_keg[location-1].red-1;	
	}
	
else if(strcmp(action,"putright")==0&&(location)<=20&&ball_keg[location].red==0)
    continue;
else if(strcmp(action,"exchangeleft")==0&&(location-1)>=0){
      c=ball_keg[location-1].white;
      ball_keg[location-1].white=ball_keg[location-2].white;
      ball_keg[location-2].white=c;
      c1=ball_keg[location-1].red;
      ball_keg[location-1].red=ball_keg[location-2].red;
      ball_keg[location-2].red=c1;
      c2=ball_keg[location-1].black;
      ball_keg[location-1].black=ball_keg[location-2].black;
      ball_keg[location-2].black=c2;
      
      
} 
else if(strcmp(action,"exchangeright")==0&&location<=20){
      c3=ball_keg[location-1].white;
      ball_keg[location-1].white=ball_keg[location].white;
      ball_keg[location].white=c3;
      c4=ball_keg[location-1].red;
      ball_keg[location-1].red=ball_keg[location].red;
      ball_keg[location].red=c4;
      c5=ball_keg[location-1].black;
      ball_keg[location-1].black=ball_keg[location].black;
      ball_keg[location].black=c5;
} 
else if(strcmp(action,"delete")==0){
	ball_keg[location-1].white=0;
	ball_keg[location-1].white=0;
	ball_keg[location-1].black=0;
}
else 
  continue;
}

int m, x,j;
for (m=0;m<n;m++){
	for(j=0;j<n;j++){
        if((ball_keg[j].red+ball_keg[j].black+ball_keg[j].white)>(ball_keg[j+1].red+ball_keg[j+1].black+ball_keg[j+1].white)){
                          Max[0]=ball_keg[j];
						  ball_keg[j]=ball_keg[j+1];
						  ball_keg[j+1]=Max[0];        	
		}
	}
}


int m1,x1,j1;
	for(j1=0;j1<n;j1++){
       if((ball_keg[j1].red+ball_keg[j1].black+ball_keg[j1].white)==(ball_keg[n-1].red+ball_keg[n-1].black+ball_keg[n-1].white)){
       	            ball_keg[n-1].number=ball_keg[j1].number;
       	            break;}
       }   	
printf("max_number=%d\n",ball_keg[n-1].number);
printf("white=%d\nred=%d\nblack=%d\n",ball_keg[n-1].white,ball_keg[n-1].red,ball_keg[n-1].black);
	return 0;
}



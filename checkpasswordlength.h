
int checkpasswordlength(char a[]){
int i=0,len=0;

	while(a[i]!='\0'){
		len++;
		i++;               //统计字符串长度 
	}
if(len>=6&&len<=15){
	return 1;
}                     
else 
    return 0;

}
//输入一个数组。

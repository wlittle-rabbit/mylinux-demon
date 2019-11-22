#include<stdio.h>
#include<stdlib.h>

//#define method1
/* 找出元素中的重复字符，再根据ASCII码把重复的字符或元素从小到大排序*/
int is_in(char *data,int len,char judgedata)
{
	int i;
	for(i=0;i<len;i++){
		if(data[i]==judgedata)
			return 1;
	}
	return 0;
}
int get_count_indata(char *data,int len,char judgedata)
{
	int i,count=0;	
	for(i=0;i<len;i++){
                if(data[i]==judgedata)
                        count++;
        }
	return count;
}
void maopaofapaixu(char *data,int len)
{
	char i,j, tmp=0;
	for(i=0;i<len-1;i++){
		for(j=i;j<len-1;j++){
			if(data[j]>data[j+1]){
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
		}
	}
}
int main()
{
	char data[8]={'a','c','b','c','b','a','d','d'};//数据源
#ifdef method
	char data1[8]={0};//存放找到的重复字符
	int count[8]={0};	
	int i,j;
	for(i=0;i<8;i++){
		if(get_count_indata(data,8, data[i])>=2)
			if(!is_in(data1,8,data[i]))
				data1[i]=data[i];
	}
	for(i=0;i<8;i++)
		printf("%c ",data1[i]);
	 printf("\r\n");
	maopaofapaixu(data1,8);	
	for(i=0;i<8;i++)
                printf("%c ",data1[i]);
	 printf("\r\n");
#else
	//assic 码字符最大127
	int i=0;
	for(i=0;i<127;i++){
		if(get_count_indata(data,8, i)>=2)
			printf("%c",i);
	}
	 printf("\r\n");
	
#endif
}

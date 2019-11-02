/*********************
获取1到100的质数或者素数
第一步 遍历1到100
第二步 判断是否为质数，是则打印该数
第三步 考虑如何优化
********************/
#include <stdio.h>
#include <stdlib.h>

#define Uprange 100
int is_prime(int number)
{
	int count=0,i=0;
	if(number<=0)
		printf("is_prime_func,input number error\n");
	if(number==1)
		return 0;
	if(number==2)
		return 1;
	for(i=2;i<number;i++)
	{
		if((number%i)==0){
			count++;
			if(count>=1)
				return 0;
		}
	}
	return 1;
}
int main()
{
	int i=0;
	printf("the prime is:\n");
	for(i=2;i<Uprange;i++){
		if(is_prime(i))
			printf("%d\n",i);
	}
}

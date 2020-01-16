#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdarg.h>

#define Debug(...) diagprint(__FUNCTION__,__LINE__,__VA_ARGS__)

static char output[256]={0};
void diagprint(const char *func,const int line,const char *Fmt,...)
{
	va_list ap;
	va_start(ap,Fmt);
	vsnprintf(output,sizeof(output),Fmt,ap);
	printf("[%04d %s]:%s\n",line,func,output);
	va_end(ap);
}

int main(int argc,char *argv[])
{	
	Debug("%s is %d","hello",3);
}

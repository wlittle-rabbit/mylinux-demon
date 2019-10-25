#include<stdio.h>
#include<stdlib.h>

struct xListitem{
	int value;
	struct xListitem *pre;
	struct xListitem *next;
}

struct List{
	int number;
	Listitem *pindex;
}
void Listitem_init()
{
	value=0;
}
void List_init(List pxlist)
{
	pxlist.number=0;
	pxlist->pre=NULL;
	pxlist->next=NULL;
}
int main()
{
	printf("hello\n");

}

#include<stdio.h>
#include<stdlib.h>

struct Listitem{
	int value;
	struct xListitem *pre;
	struct xListitem *next;
}; 
typedef struct Listitem ListItem_t;
struct List{
	int number;
	ListItem_t *pindex;
	ListItem_t listend;
};
typedef struct List List_t;
void Listitem_init(ListItem_t *pitem)
{
	pitem->value=0;
}
void List_init(List_t *pxlist)
{
	pxlist->number=0;
	pxlist->pindex=(ListItem_t*)&pxlist->listend;
	pxlist->listend.value=0xffff;
	pxlist->listend.pre=(ListItem_t*)&pxlist->listend;
	pxlist->listend.next=(ListItem_t*)&pxlist->listend;
}
void List_insert(List_t *pxlist,ListItem_t *newitem)
{
	pxlist->number++;
	ListItem_t *p;
	if( !pxlist->number){
		p=pxlist->listend.pre;
	}
	else{
		for(p=(ListItem_t *)&pxlist->listend;p->value>newitem->value;p=p->pre);	
	}
	newitem->next=p->next;	
	newitem->next->pre=newitem;
	p->next=newitem;
	newitem->pre=p;
}
void list_print(List_t *pxlist)
{
	printf("the list number is %d\n",pxlist->number);
}
int main()
{
	List_t *mylist;
	List_init(mylist);
	ListItem_t item1,item2,item3;
	item1.value=1;
	item2.value=2;
	item3.value=3;
	List_insert(mylist,&item2);
	List_insert(mylist,&item3);
	List_insert(mylist,&item1);

	
	printf("hello\n");
}

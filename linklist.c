#include<stdio.h>
#include<stdlib.h>

struct Listitem{
	int value;
	struct Listitem *pre;
	struct Listitem *next;
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
	pxlist->listend.value=0xff;
	pxlist->listend.pre=(ListItem_t*)&pxlist->listend;
	pxlist->listend.next=(ListItem_t*)&pxlist->listend;
}
void List_insert(List_t *pxlist,ListItem_t *newitem)
{
	ListItem_t *p;
	if( !pxlist->number){
		p=pxlist->listend.pre;
		pxlist->pindex=newitem;		
	}
	else{
		printf("pxlist->number is %d\n",pxlist->number);
		for(p=(ListItem_t *)&pxlist->listend.pre;(p->value>=newitem->value)&&(p!=(ListItem_t *)&pxlist->listend.next);p=p->pre);	
	}
	newitem->next=p->next;	
	newitem->next->pre = newitem;
	p->next=newitem;
	newitem->pre=p;
	pxlist->number++;
	printf("the newitem pre value is %d\n",newitem->pre->value);
	printf("the newitem value is %d\n",newitem->value);
}
void list_print(List_t *pxlist)
{
	printf("the list number is %d\n",pxlist->number);
	int i;
	ListItem_t* tmp;
	tmp=pxlist->pindex;
	printf("the item value is %d\n",tmp->value);
	for(tmp=pxlist->pindex;tmp!=(ListItem_t*)&pxlist->listend;tmp=tmp->next){
		printf("the item value is %d\n",tmp->value);
	}
}
int main()
{
	List_t *mylist;
	mylist=malloc(10*sizeof(List_t));
	List_init(mylist);
	ListItem_t item1,item2,item3;
	item1.value=1;
	item2.value=2;
	item3.value=3;
	List_insert(mylist,&item3);
	List_insert(mylist,&item2);
	List_insert(mylist,&item1);
	list_print(mylist);
	free(mylist);
	printf("main end\n");
}

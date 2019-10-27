/**************************
实验结论
	定义一个结构体指针后，需要分配内存
	for循环是先判断条件，再执行，与while循环相同
	本实验实现双链表节点元素大小顺序插入
**************************/
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
	pitem->pre=NULL;
	pitem->next=NULL;
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
		printf("the list item number is %d\n",pxlist->number);
		for(p=pxlist->listend.pre;(p->value>=newitem->value)&&(p!=(ListItem_t *)&pxlist->listend);p=p->pre);
	}
	newitem->next=p->next;
	newitem->next->pre=newitem;
	p->next=newitem;
	newitem->pre=p;
	pxlist->number++;
	printf("the newitem value is %d\n",newitem->value);
	printf("the p value is %d\n",p->value);
}
void list_print(List_t *pxlist)
{
	printf("---list_print func start---\n");
        printf("the list item number is %d\n",pxlist->number);
        ListItem_t* tmp;
        for(tmp=pxlist->listend.next;tmp!=&pxlist->listend;tmp=tmp->next){
              printf("the item value is %d\n",tmp->value);
        }
        printf("---list_print func end---\n");
}
int main()
{
	List_t *mylist;
	mylist=malloc(sizeof(List_t));
	List_init(mylist);
	ListItem_t item1,item2,item3,item4,item5;
	Listitem_init(&item1);
	Listitem_init(&item2);
	Listitem_init(&item3);
	Listitem_init(&item4);
	Listitem_init(&item5);
	item1.value=1;
	item2.value=2;
	item3.value=3;
	item4.value=4;
	item5.value=3;
	List_insert(mylist,&item3);
	List_insert(mylist,&item2);
	List_insert(mylist,&item1);
	List_insert(mylist,&item4);
	List_insert(mylist,&item5);
	list_print(mylist);
	free(mylist);
	printf("main end\n");
}

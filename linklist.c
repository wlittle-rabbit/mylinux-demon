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
	if( !pxlist->number){

	}
	else{
		
	}
}
int main()
{
	List_t *mylist;
	List_init(mylist);
	
	printf("hello\n");

}

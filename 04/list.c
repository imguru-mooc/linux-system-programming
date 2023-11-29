#if 1
// ver 1.0
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *prev;
	struct node *next;
}NODE;

void insert_data( NODE *prev, NODE *next, NODE *temp )
{
    temp->next = next;
    prev->next = temp;
    temp->prev = prev;
    next->prev = temp;
}

void insert_front( NODE *head, NODE *temp )
{
    insert_data( head, head->next, temp );
}

void insert_back( NODE *head, NODE *temp )
{
    insert_data( head->prev, head, temp );
}


#define   list_entry( ptr, type, member) ((type*)((char*)ptr - (unsigned long)&((type*)0)->member))
//-------------------------------------------------------------------------

typedef struct 
{
	int sid;
	char name[20];
	NODE node;
} SAWON;

void display(NODE *head)
{
	NODE *temp;
	SAWON *sawon;

	system("clear");
	printf("[head]");
	for( temp = head->prev; temp != head; temp = temp->prev )
	{
		sawon = list_entry( temp, SAWON, node);
		printf("<->[%s]", sawon->name );
	}
	printf("<->[head]\n");
	getchar();
}

int main()
{
	NODE head={&head, &head};
	SAWON sawon[5] = {{1,"홍길동",},{2,"이순신",},{3,"유관순",},{4,"강감찬",},{4,"세종대왕",}};
	NODE *temp;
	int i;
	display(&head);
	for(i=0; i<5; i++ )
	{
		temp = &sawon[i].node;
		insert_front(&head, temp);
		display(&head);
	}
	return 0;
}
#endif
#if 0
// ver 0.9
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	void *data;
	struct node *prev;
	struct node *next;
}NODE;

void insert_data( NODE *prev, NODE *next, NODE *temp )
{
    temp->next = next;
    prev->next = temp;
    temp->prev = prev;
    next->prev = temp;
}

void insert_front( NODE *head, NODE *temp )
{
    insert_data( head, head->next, temp );
}

void insert_back( NODE *head, NODE *temp )
{
    insert_data( head->prev, head, temp );
}


//-------------------------------------------------------------------------

typedef struct 
{
	int sid;
	char name[20];
} SAWON;

void display(NODE *head)
{
	NODE *temp;
	SAWON *sawon;

	system("clear");
	printf("[head]");
	for( temp = head->prev; temp != head; temp = temp->prev )
	{
		sawon = (SAWON*)temp->data;
		printf("<->[%s]", sawon->name );
	}
	printf("<->[head]\n");
	getchar();
}

int main()
{
	NODE head={0,&head, &head};
	NODE nodes[5];
	SAWON sawon[5] = {{1,"홍길동"},{2,"이순신"},{3,"유관순"},{4,"강감찬"},{4,"세종대왕"}};
	NODE *temp;
	int i;
	display(&head);
	for(i=0; i<5; i++ )
	{
		temp = &nodes[i];
		temp->data = &sawon[i];
		insert_front(&head, temp);
		display(&head);
	}
	return 0;
}
#endif
#if 0
// ver 0.8
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}NODE;

void insert_data( NODE *prev, NODE *next, NODE *temp )
{
    temp->next = next;
    prev->next = temp;
    temp->prev = prev;
    next->prev = temp;
}

void insert_front( NODE *head, NODE *temp )
{
    insert_data( head, head->next, temp );
}

void insert_back( NODE *head, NODE *temp )
{
    insert_data( head->prev, head, temp );
}


//-------------------------------------------------------------------------

void display(NODE *head)
{
	NODE *temp;

	system("clear");
	printf("[head]");
	for( temp = head->prev; temp != head; temp = temp->prev )
		printf("<->[%d]", temp->data );
	printf("<->[head]\n");
	getchar();
}

int main()
{
	NODE head={0,&head, &head};
	NODE nodes[100];
	NODE *temp;
	int i;
	display(&head);
	for(i=0; i<7; i++ )
	{
		temp = &nodes[i];
		temp->data = i+1;
		insert_back(&head, temp);
		display(&head);
	}
	return 0;
}
#endif
#if 0
// ver 0.7
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}NODE;


void insert_data( NODE *head, NODE *temp )
{
	temp->next = head->next;
	head->next = temp;
	temp->prev = temp->next->prev;
	temp->next->prev = temp;
}

//-------------------------------------------------------------------------

void display(NODE *head)
{
	NODE *temp;

	system("clear");
	printf("[head]");
	for( temp = head->prev; temp != head; temp = temp->prev )
		printf("<->[%d]", temp->data );
	printf("<->[head]\n");
	getchar();
}

int main()
{
	NODE head={0,&head, &head};
	NODE nodes[100];
	NODE *temp;
	int i;
	display(&head);
	for(i=0; i<7; i++ )
	{
		temp = &nodes[i];
		temp->data = i+1;
		insert_data(&head, temp);
		display(&head);
	}
	return 0;
}
#endif
#if 0
// ver 0.6
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;


void insert_data( NODE *head, NODE *temp )
{
	temp->next = head->next;
	head->next = temp;
}

//-------------------------------------------------------------------------

void display(NODE *head)
{
	NODE *temp;

	system("clear");
	printf("[head]");
	for( temp = head->next; temp != head; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("->[head]\n");
	getchar();
}

int main()
{
	NODE head={0,&head};
	NODE nodes[100];
	NODE *temp;
	int i;
	display(&head);
	for(i=0; i<7; i++ )
	{
		temp = &nodes[i];
		temp->data = i+1;
		insert_data(&head, temp);
		display(&head);
	}
	return 0;
}
#endif
#if 0
// ver 0.5
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;


void insert_data( NODE *head, NODE *temp )
{
	temp->next = head->next;
	head->next = temp;
}

//-------------------------------------------------------------------------

void display(NODE *head)
{
	NODE *temp;

	system("clear");
	printf("[head]");
	for( temp = head->next; temp != head; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("->[head]\n");
	getchar();
}

int main()
{
	NODE head={0,&head};
	NODE nodes[100];
	NODE *temp;
	int i;
	display(&head);
	for(i=0; i<7; i++ )
	{
		temp = &nodes[i];
		temp->data = i+1;
		insert_data(&head, temp);
		display(&head);
	}
	return 0;
}
#endif
#if 0
// ver 0.4
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;


void insert_data( NODE *head, NODE *temp )
{
	temp->next = head->next;
	head->next = temp;
}

//-------------------------------------------------------------------------

void display(NODE *head, NODE *tail)
{
	NODE *temp;

	system("clear");
	printf("[head]");
	for( temp = head->next; temp != tail; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("->[tail]\n");
	getchar();
}

int main()
{
	NODE tail={0,&tail};
	NODE head={0,&tail};
	NODE nodes[100];
	NODE *temp;
	int i;
	display(&head, &tail);
	for(i=0; i<7; i++ )
	{
		temp = &nodes[i];
		temp->data = i+1;
		insert_data(&head, temp);
		display(&head, &tail);
	}
	return 0;
}
#endif
#if 0
// ver 0.3
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;


void insert_data( NODE *head, NODE *temp )
{
	temp->next = head->next;
	head->next = temp;
}

//-------------------------------------------------------------------------

void display(NODE *head)
{
	NODE *temp;

	system("clear");
	printf("[head]");
	for( temp = head->next; ; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("\n");
	getchar();
}

int main()
{
	NODE head={0,};
	NODE nodes[100];
	NODE *temp;
	int i;
	display(&head);
	for(i=0; i<7; i++ )
	{
		temp = &nodes[i];
		temp->data = i+1;
		insert_data(&head, temp);
		display(&head);
	}
	return 0;
}
#endif

#if 0
// ver 0.2
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;


void insert_data( NODE *head, int data )
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}

void display(NODE *head)
{
	NODE *temp;

	system("clear");
	printf("[head]");
	for( temp = head->next; temp; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("\n");
	getchar();
}

int main()
{
	NODE head={0,};
	int i;
	display(&head);
	for(i=0; i<7; i++ )
	{
		insert_data(&head, i+1);
		display(&head);
	}
	return 0;
}
#endif

#if 0
// ver 0.1
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *head;

void insert_data( int data )
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head;
	head = temp;
}

void display(void)
{
	NODE *temp;

	system("clear");
	printf("head");
	for( temp = head; temp; temp = temp->next )
		printf("->[%d]", temp->data );
	printf("\n");
	getchar();
}

int main()
{
	int i;
	display();
	for(i=0; i<7; i++ )
	{
		insert_data(i+1);
		display();
	}
	return 0;
}
#endif

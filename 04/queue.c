#if 1
#include <stdio.h>
#include <stdlib.h>

#define QMAX  8

typedef struct
{
	int data[QMAX];
	int rear;
	int front;
} QUEUE;


int is_empty(QUEUE *queue)
{
	return queue->rear == queue->front;
}

int is_full(QUEUE *queue)
{
	return (queue->rear+1)%QMAX == queue->front;
}

void put( QUEUE *queue, int data )
{
	queue->data[queue->rear] = data;
	queue->rear = (queue->rear+1)%QMAX;
}

int get(QUEUE *queue)
{
	int temp = queue->data[queue->front];
	queue->front = (queue->front+1)%QMAX;
	return temp;
}

void display(QUEUE *queue)
{
	int i;
	system("clear");
	for(i=0; i<queue->rear; i++)
		printf("%4s ", " ");
	printf("rear\n");

	for(i=0; i<queue->rear; i++)
		printf("%4s ", " ");
	printf("   |\n");

	for(i=0; i<8; i++)
		printf("%4d ", queue->data[i]);
	printf("\n");

	for(i=0; i<queue->front; i++)
		printf("%4s ", " ");
	printf("   |\n");

	for(i=0; i<queue->front; i++)
		printf("%4s ", " ");
	printf("front\n");
	getchar();
}


int main()
{
	int i;
	QUEUE queue = {0,};
	display(&queue);
	for( i=0; i<10; i++ )
	{
		if( is_full(&queue) )
		{
			printf("큐가 꽉차 있습니다.\n");
			break;
		}
		put(&queue, (i+1)*10);
		display(&queue);
	}

	for( i=0; i<10; i++ )
	{
		if( is_empty(&queue) )
		{
			printf("큐가 비어 있습니다.\n");
			break;
		}
		get(&queue);
		display(&queue);
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

#define QMAX  8
int queue[QMAX];
int rear;
int front;


int is_empty()
{
	return rear == front;
}

int is_full()
{
	return (rear+1)%QMAX == front;
}

void put( int data )
{
	queue[rear] = data;
	rear = (rear+1)%QMAX;
}

int get(void)
{
	int temp = queue[front];
	front = (front+1)%QMAX;
	return temp;
}

void display(void)
{
	int i;
	system("clear");
	for(i=0; i<rear; i++)
		printf("%4s ", " ");
	printf("rear\n");

	for(i=0; i<rear; i++)
		printf("%4s ", " ");
	printf("   |\n");

	for(i=0; i<8; i++)
		printf("%4d ", queue[i]);
	printf("\n");

	for(i=0; i<front; i++)
		printf("%4s ", " ");
	printf("   |\n");

	for(i=0; i<front; i++)
		printf("%4s ", " ");
	printf("front\n");
	getchar();
}


int main()
{
	int i;
	display();
	for( i=0; i<10; i++ )
	{
		if( is_full() )
		{
			printf("큐가 꽉차 있습니다.\n");
			break;
		}
		put((i+1)*10);
		display();
	}

	for( i=0; i<10; i++ )
	{
		if( is_empty() )
		{
			printf("큐가 비어 있습니다.\n");
			break;
		}
		get();
		display();
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

#define QMAX  8
int queue[QMAX];
int rear;
int front;

void put( int data )
{
	queue[rear] = data;
	rear = (rear+1)%QMAX;
}

int get(void)
{
	int temp = queue[front];
	front = (front+1)%QMAX;
	return temp;
}

void display(void)
{
	int i;
	system("clear");
	for(i=0; i<rear; i++)
		printf("%4s ", " ");
	printf("rear\n");

	for(i=0; i<rear; i++)
		printf("%4s ", " ");
	printf("   |\n");

	for(i=0; i<8; i++)
		printf("%4d ", queue[i]);
	printf("\n");

	for(i=0; i<front; i++)
		printf("%4s ", " ");
	printf("   |\n");

	for(i=0; i<front; i++)
		printf("%4s ", " ");
	printf("front\n");
	getchar();
}


int main()
{
	int i;
	display();
	for( i=0; i<10; i++ )
	{
		put((i+1)*10);
		display();
	}

	for( i=0; i<10; i++ )
	{
		get();
		display();
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

int queue[8];
int rear;
int front;

void put( int data )
{
	queue[rear++] = data;
}

int get(void)
{
	return queue[front++];
}

void display(void)
{
	int i;
	system("clear");
	for(i=0; i<rear; i++)
		printf("%4s ", " ");
	printf("rear\n");

	for(i=0; i<rear; i++)
		printf("%4s ", " ");
	printf("   |\n");

	for(i=0; i<8; i++)
		printf("%4d ", queue[i]);
	printf("\n");

	for(i=0; i<front; i++)
		printf("%4s ", " ");
	printf("   |\n");

	for(i=0; i<front; i++)
		printf("%4s ", " ");
	printf("front\n");
	getchar();
}


int main()
{
	int i;
	display();
	for( i=0; i<3; i++ )
	{
		put((i+1)*10);
		display();
	}

	for( i=0; i<3; i++ )
	{
		get();
		display();
	}
	return 0;
}
#endif

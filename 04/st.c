#if 1
#include <stdio.h>

typedef struct  node
{
	int data;
	struct node *next;
} NODE;

int main()
{
	NODE node1 = {1,};
	NODE node2 = {2,};
	node1.next = &node2;
	return 0;
}

#endif
#if 0
#include <stdio.h>

struct  node
{
	int data;
	struct node *next;
};

int main()
{
//	struct node node1 = {1,};
//	struct node node2 = {2,};
//	node1.next = &node2;
	return 0;
}

#endif

#if 0
#include <stdio.h>

typedef struct 
{
	int kor, math, eng, history;
	int total;
	double aver;
} ST;

void input(ST*);
void calc(ST*);
void output(ST*);

int main()
{
	ST st;
	input(&st);
	calc(&st);
	output(&st);
	return 0;
}

void input(ST *st)
{
	printf("점수 입력:");
	scanf("%d %d %d %d", &st->kor, &st->math, &st->eng, &st->history);
}

void calc(ST *st)
{
	st->total = st->kor + st->math + st->eng + st->history;
	st->aver = (double)st->total/4;
}

void output(ST *st)
{
	printf("%d, %d, %d, %d, %d, %5.2lf\n", st->kor, st->math, st->eng, st->history,st->total, st->aver );
}
#endif
#if 0
#include <stdio.h>

typedef struct  
{
	int kor, math, eng, history;
	int total;
	double aver;
} ST;

int main()
{
	ST st1;
	ST st2;
	return 0;
}

#endif
#if 0
#include <stdio.h>

struct  ST
{
	int kor, math, eng, history;
	int total;
	double aver;
};

int main()
{
	struct  ST st1;
	struct  ST st2;
	return 0;
}

#endif
#if 0
#include <stdio.h>

int main()
{
	struct 
	{
		int kor, math, eng, history;
		int total;
		double aver;
	} st1;
	struct 
	{
		int kor, math, eng, history;
		int total;
		double aver;
	} st2;
	return 0;
}

#endif
#if 0
#include <stdio.h>

struct ST
{
	int kor, math, eng, history;
	int total;
	double aver;
};

void input(struct ST*);
void calc(struct ST*);
void output(struct ST*);

int main()
{
	struct ST st;
	input(&st);
	calc(&st);
	output(&st);
	return 0;
}

void input(struct ST *st)
{
	printf("점수 입력:");
	scanf("%d %d %d %d", &st->kor, &st->math, &st->eng, &st->history);
}

void calc(struct ST *st)
{
	st->total = st->kor + st->math + st->eng + st->history;
	st->aver = (double)st->total/4;
}

void output(struct ST *st)
{
	printf("%d, %d, %d, %d, %d, %5.2lf\n", st->kor, st->math, st->eng, st->history,st->total, st->aver );
}
#endif

#if 0
#include <stdio.h>

void input(int *kor, int *math, int *eng);
void calc(int kor, int math, int eng, int *total, double *aver);
void output( int kor, int math, int eng, int total, double aver );

int main()
{
	int kor, math, eng;
	int total;
	double aver;
	input( &kor, &math, &eng);
	calc(kor, math, eng,  &total, &aver );
	output( kor, math,  eng, total, aver );
	return 0;
}

void input(int *kor, int *math, int *eng)
{
	printf("점수 입력:");
	scanf("%d %d %d", kor, math, eng);
}

void calc(int kor, int math, int eng, int *total, double *aver)
{
	*total = kor + math + eng;
	*aver = (double)*total/3;
}

void output( int kor, int math, int eng, int total, double aver )
{
	printf("%d, %d, %d, %d, %5.2lf\n", kor, math, eng, total, aver );
}
#endif
#if 0
#include <stdio.h>

void input(int *kor, int *math);
void calc(int kor, int math, int *total, double *aver);
void output( int kor, int math, int total, double aver );

int main()
{
	int kor, math;
	int total;
	double aver;
	input( &kor, &math);
	calc(kor, math, &total, &aver );
	output( kor, math, total, aver );
	return 0;
}

void input(int *kor, int *math)
{
	printf("점수 입력:");
	scanf("%d %d", kor, math);
}

void calc(int kor, int math, int *total, double *aver)
{
	*total = kor + math;
	*aver = (double)*total/2;
}

void output( int kor, int math, int total, double aver )
{
	printf("%d, %d, %d, %5.2lf\n", kor, math, total, aver );
}
#endif
#if 0
#include <stdio.h>

void input(int *kor, int *math)
{
	printf("점수 입력:");
	scanf("%d %d", kor, math);
}

void calc(int kor, int math, int *total, double *aver)
{
	*total = kor + math;
	*aver = (double)*total/2;
}

void output( int kor, int math, int total, double aver )
{
	printf("%d, %d, %d, %5.2lf\n", kor, math, total, aver );
}
int main()
{
	int kor, math;
	int total;
	double aver;
	input( &kor, &math);
	calc(kor, math, &total, &aver );
	output( kor, math, total, aver );
	return 0;
}
#endif

#if 0
#include <stdio.h>
void foo(int *p)
{
	p[0] = 10;
	p[1] = 20; 
	p[2] = 30;
}
int main()
{
	int a[3];
	foo(a);
	printf("%d, %d, %d\n", a[0], a[1], a[2] );
	return 0;
}
#endif

#if 0
#include <stdio.h>
void foo(int *a, int *b, int *c )
{
	*a = 10;
	*b = 20; 
	*c = 30;
}
int main()
{
	int a, b, c;
	foo(&a,&b,&c);
	printf("%d, %d, %d\n", a, b, c );
	return 0;
}
#endif

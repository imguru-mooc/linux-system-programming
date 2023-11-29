#if 1
#include <stdio.h>

typedef int (*FP1)[2];
typedef FP1 (*FP2)(void);
typedef FP2 (*FP3)(void);
typedef FP3 (*FP4)[2];

FP1 aaa(void) 
{
	static int a[2][2];
	printf("aaa()\n");
	return a;
}

FP2 bbb(void) 
{
	printf("bbb()\n");
	return aaa;
}

int main()
{
	FP3 p[2][2] = {{bbb,bbb},{bbb,bbb}}; 
	FP4 q = p;
	q[1][1]()()[1][1] = 10;
	return 0;
}

#endif
#if 0
#include <stdio.h>

typedef int FP1[2];
typedef FP1* FP2;
typedef FP2 FP3(void);
typedef FP3* FP4;
typedef FP4 FP5(void);
typedef FP5* FP6;
typedef FP6 FP7[2];
typedef FP7* FP8;

FP2 aaa(void) 
{
	static int a[2][2];
	printf("aaa()\n");
	return a;
}

FP4 bbb(void) 
{
	printf("bbb()\n");
	return aaa;
}

int main()
{
	FP6 p[2][2] = {{bbb,bbb},{bbb,bbb}}; 
	FP8 q = p;
	q[1][1]()()[1][1] = 10;
	return 0;
}

#endif
#if 0
#include <stdio.h>

int (*aaa(void))[2] 
{
	static int a[2][2];
	printf("aaa()\n");
	return a;
}

int (*(*bbb(void))(void))[2] 
{
	printf("bbb()\n");
	return aaa;
}


int main()
{
	int (*(*(*p[2][2])(void))(void))[2] = {{bbb,bbb},{bbb,bbb}}; 
	int (*(*(*(*q)[2])(void))(void))[2] = p;
	q[1][1]()()[1][1] = 10;
	return 0;
}

#endif
#if 0
#include <stdio.h>

int (*aaa(void))[2] 
{
	static int a[2][2];
	printf("aaa()\n");
	return a;
}

int (*(*bbb(void))(void))[2] 
{
	printf("bbb()\n");
	return aaa;
}

int (*(*(*ccc(void))(void))(void))[2] 
{
	printf("ccc()\n");
	return bbb;
}

int main()
{
	ccc()()()[1][1] = 10;
	return 0;
}

#endif
#if 0
#include <stdio.h>

int (*aaa(void))[2] 
{
	static int a[2][2];
	printf("aaa()\n");
	return a;
}

int (*(*bbb(void))(void))[2] 
{
	printf("bbb()\n");
	return aaa;
}

int main()
{
	bbb()()[1][1] = 10;
	return 0;
}

#endif

#if 0
#include <stdio.h>

int (*aaa(void))[2] 
{
	static int a[2][2];
	printf("aaa()\n");
	return a;
}

int main()
{
	aaa()[1][1] = 10;
	return 0;
}

#endif
#if 0
#include <stdio.h>

void aaa(void)    
{
	printf("aaa()\n");
}

void(*bbb(void))(void)
{
	printf("bbb()\n");
	return aaa;
}

int main()
{
	bbb()();
	return 0;
}

#endif
#if 0
#include <stdio.h>

void aaa(void)    
{
	printf("aaa()\n");
}

void bbb( void (*p)(void) )    
{
	p();
	printf("bbb()\n");
}

int main()
{
	bbb(aaa);
	return 0;
}

#endif

#if 0
#include <stdio.h>

void foo(void)    
{
	printf("foo()\n");
}

int main()
{
	void (*p)(void)  = foo;   
	p();  // call p
	return 0;
}

#endif
#if 0
#include <stdio.h>

void foo(void)    
{
	printf("foo()\n");
}

int main()
{
	foo();   // call foo;
	return 0;
}

#endif

#if 0
#include <stdio.h>

int (* foo(void) )[2]   
{
	static int a[2][2] = {0,};
	return a;
}

int main()
{
	int (*p)[2];
	p = foo();
	p[1][1] = 10;
	return 0;
}

#endif

#if 0
#include <stdio.h>

void display(int (*p)[5] )
{
	int i,j;
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
			printf("%4d", p[i][j]);
		printf("\n");
	}
}

void set(int (*p)[5] )
{
	int i,j;
	int count=0;
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
			p[i][j] = ++count;
	}
}

int main()
{
	int a[5][5]={0,};

	display(a);
	set(a);
	display(a);

	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[2][2]={{1,2},{3,4}};
	int (*p)[2]  = a;

	p[1][1] = 40;

	printf("a[1][1]=%d\n", a[1][1]);

	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[2][2]={1,2,3,4};
	int **p = a;

	p[1][1] = 40;

	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[2][2]={1,2,3,4};
	int *p = a;

	p[1][1] = 40;

	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[4];
	int *p = a;

	printf("sizeof(a)     =%ld\n", sizeof(a));
	printf("sizeof(int[4])=%ld\n", sizeof(int[4]));
	printf("sizeof(p)     =%ld\n", sizeof(p));
	printf("sizeof(int*)  =%ld\n", sizeof(int*));

	return 0;
}
#endif
#if 0
#include <stdio.h>

void display(int *p)
{
	int i;
	for(i=0; i<10; i++)
		printf("%4d", p[i]);
	printf("\n");
}

void set(int *p)
{
	int i;
	for(i=0; i<10; i++)
		p[i]=i+1;
}

int main()
{
	int a[10]={0,};
	display(&a[0]);
	set(&a[0]);
	display(&a[0]);

	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[2]={1,2};
	int *p = &a[0];

	p[0]=10;

	printf("a[0]=%d\n", a[0] );

	return 0;
}
#endif
#if 0
#include <stdio.h>

typedef struct {
	char a[1024];
} ST;
int main()
{
	ST i;
	ST *pi = &i;

	printf("pi  =%p\n", pi );
	printf("pi+1=%p\n", pi+1 );

	return 0;
}
#endif

#if 0
#include <stdio.h>

void set(int *p)
{
	*p=20;
	printf("set :i=%d\n", *p );
}

int main()
{
	int i=10;

	printf("before:i=%d\n", i );
	set(&i);
	printf("after :i=%d\n", i );

	return 0;
}
#endif
#if 0
#include <stdio.h>

void set(int i)
{
	i=20;
	printf("set :i=%d\n", i );
}

int main()
{
	int i=10;

	printf("before:i=%d\n", i );
	set(i);
	printf("after :i=%d\n", i );

	return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
	int i=10;
	int *p = &i;

	printf("&i=%p\n", &i);
	printf("&p=%p\n", &p);
	printf("sizeof(i)=%ld\n", sizeof(i) );
	printf("sizeof(p)=%ld\n", sizeof(p) );
	printf("before:i=%d\n", i );
	//i=20;
	*p=20;
	printf("after :i=%d\n", i );

	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int i=10;

	printf("sizeof(i)=%ld\n", sizeof(i) );
	printf("before:i=%d\n", i );
	i=20;
	printf("after :i=%d\n", i );

	return 0;
}
#endif

#if 1
#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------

int int_cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int a[7] = {400,500,300,700,600,200,100};
	int i;

	qsort(a, 7, sizeof(a[0]), int_cmp);
	for(i=0; i<7; i++)
		printf("%4d", a[i]);
	printf("\n");

	return 0;
}
#endif
#if 0
#include <stdio.h>

void swap( void *a, void *b, int size )
{
	char t;
	int i;

	char *p = (char*)a;
	char *q = (char*)b;
	for( i=0; i<size; i++ )
	{
		t = p[i];
		p[i] = q[i];
		q[i] = t;
	}
}

void bubble( void *a, int n, int size, int (*cmp)(void*,void*) )
{
	int i,j;

	for(i=0; i<n-1; i++ )
		for(j=0; j<n-1; j++)
			if( cmp((char*)a+j*size, (char*)a+(j+1)*size) > 0 )
				swap((char*)a+j*size, (char*)a+(j+1)*size, size);
}

//----------------------------------------------------------

int int_cmp(void* a,void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int a[7] = {400,500,300,700,600,200,100};
	int i;

	bubble(a, 7, sizeof(a[0]), int_cmp);
	for(i=0; i<7; i++)
		printf("%4d", a[i]);
	printf("\n");

	return 0;
}
#endif
#if 0
#include <stdio.h>

void swap( void *a, void *b, int size )
{
	char t;
	int i;

	char *p = (char*)a;
	char *q = (char*)b;
	for( i=0; i<size; i++ )
	{
		t = p[i];
		p[i] = q[i];
		q[i] = t;
	}
}

void bubble( void *a, int n, int size )
{
	int i,j;

	for(i=0; i<n-1; i++ )
		for(j=0; j<n-1; j++)
			if( *(int*)((char*)a+j*size) > *(int*)((char*)a+(j+1)*size) )
				swap((char*)a+j*size, (char*)a+(j+1)*size, size);
}

//----------------------------------------------------------

int main()
{
	int a[7] = {400,500,300,700,600,200,100};
	int i;

	bubble(a, 7, sizeof(a[0]));
	for(i=0; i<7; i++)
		printf("%4d", a[i]);
	printf("\n");

	return 0;
}
#endif

#if 0
#include <stdio.h>

void swap( void *a, void *b, int size )
{
	char t;
	int i;

	char *p = (char*)a;
	char *q = (char*)b;
	for( i=0; i<size; i++ )
	{
		t = p[i];
		p[i] = q[i];
		q[i] = t;
	}
}

void bubble( int *a, int n )
{
	int i,j;

	for(i=0; i<n-1; i++ )
		for(j=0; j<n-1; j++)
			if( a[j] > a[j+1] )
				swap(a+j, a+j+1, sizeof(a[0]));
}

//----------------------------------------------------------

int main()
{
	int a[7] = {4,5,3,7,6,2,1};
	int i;

	bubble(a, 7);
	for(i=0; i<7; i++)
		printf("%4d", a[i]);
	printf("\n");

	return 0;
}
#endif
#if 0
#include <stdio.h>

void swap( void *a, void *b, int size )
{
	char t;
	int i;

	char *p = (char*)a;
	char *q = (char*)b;
	for( i=0; i<size; i++ )
	{
		t = p[i];
		p[i] = q[i];
		q[i] = t;
	}
}

//----------------------------------------------------------

int main()
{
	int a=3; 
	int b=4;
	double ad=3.14;
	double bd=2.71;

	swap(&a, &b, sizeof(a));
	printf("a=%d, b=%d\n", a, b );
	swap(&ad, &bd, sizeof(ad));
	printf("ad=%5.2lf, bd=%5.2lf\n", ad, bd );
	return 0;
}
#endif
#if 0
#include <stdio.h>

void swap( char *a, char *b, int size )
{
	char t;
	int i;

	for( i=0; i<size; i++ )
	{
		t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
}

//----------------------------------------------------------

int main()
{
	int a=3; 
	int b=4;
	double ad=3.14;
	double bd=2.71;

	swap((char*)&a, (char*)&b, sizeof(a));
	printf("a=%d, b=%d\n", a, b );
	swap((char*)&ad, (char*)&bd, sizeof(ad));
	printf("ad=%5.2lf, bd=%5.2lf\n", ad, bd );
	return 0;
}
#endif

#if 0
int main()
{
	char ch  = 'a';
	int  *i = &ch;
	return 0;
}
#endif



#if 0

#include <stdio.h>

void swap_int( int *a, int *b )
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
void swap_double( double *a, double *b )
{
	double t;
	t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int a=3; 
	int b=4;
	double ad=3.14;
	double bd=2.71;

	swap_int(&a, &b);
	printf("a=%d, b=%d\n", a, b );
	swap_double(&ad, &bd);
	printf("ad=%5.2lf, bd=%5.2lf\n", ad, bd );
	return 0;
}
#endif



#if 0
#include <stdio.h>

void swap( int *a, int *b )
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int a=3; 
	int b=4;

	swap(&a, &b);
	printf("a=%d, b=%d\n", a, b );
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int a=3; 
	int b=4;

	int t;
	t = a;
	a = b;
	b = t;

	printf("a=%d, b=%d\n", a, b );
	return 0;
}
#endif

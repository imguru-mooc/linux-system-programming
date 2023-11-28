#if 1
#include <stdio.h>

typedef   int bit_set[32];
#define  BIT_SET(index, x)      (x[index/32] |= 1<<(index%32))
#define  BIT_ISSET(index, x)    (x[index/32] & (1<<(index%32)))
#define  BIT_CLR(index, x)      (x[index/32] &= ~(1<<(index%32)))
#define  BIT_ZERO(x)             do{ int i;                      \
                                     for(i=0; i<32; i++)         \
								       x[i] = 0; } while(0)
//-------------------------------------------------------------------------
int main()
{
    int i;
	bit_set items;

	BIT_ZERO(items);

	BIT_SET(700, items);
	BIT_SET(800, items);

    for(i=0; i<1024; i++)
        if( BIT_ISSET(i,items ))
            printf("%d\n", i );

	BIT_CLR(700, items);
    printf("------------\n");

    for(i=0; i<1024; i++)
        if( BIT_ISSET(i,items ))
            printf("%d\n", i );
    return 0;
}
#endif
#if 0
#include <stdio.h>
int main()
{
    int items[32] = {0,};
    int i;

    items[700/32] |= 1<<(700%32);
    items[800/32] |= 1<<(800%32);

    for(i=0; i<1024; i++)
        if( items[i/32] & (1<<(i%32)) )
            printf("%d\n", i );

    items[700/32] &= ~(1<<(700%32));
    printf("------------\n");

    for(i=0; i<1024; i++)
        if( items[i/32] & (1<<(i%32)) )
            printf("%d\n", i );
    return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
    int items = 0;
    int i;

    items = items | 2;
    items = items | 8;

    for(i=0; i<4; i++)
        if( items & (1<<i) )
            printf("%d\n", i );

    items = items & (~8);
    printf("------------\n");

    for(i=0; i<4; i++)
        if( items & (1<<i) )
            printf("%d\n", i );
    return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int items[4] = {0,};
	int i;

	items[1] = 1;
	items[3] = 1;

	for(i=0; i<4; i++)
		if( items[i] == 1 )
			printf("%d\n", i );

	items[3] = 0;
	printf("------------\n");

	for(i=0; i<4; i++)
		if( items[i] == 1 )
			printf("%d\n", i );

	return 0;
}
#endif

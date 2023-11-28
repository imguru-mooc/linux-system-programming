#if 1
#include <stdio.h>
#include <unistd.h>
#define A_FLAG  (1<<0)
#define B_FLAG  (1<<1)
int main( int argc, char **argv )
{
	int i;
	int ch;
	int flag = 0;

	while( (ch = getopt( argc, argv, "al")) != -1 )
	{
		switch(ch)
		{
			case 'a' : flag |= A_FLAG; break;  // 0001
			case 'l' : flag |= B_FLAG; break;  // 0010
					                      // 0011
		}
	}
	if(flag & A_FLAG)
		printf("a option\n");
	if(flag & B_FLAG)
		printf("l option\n");
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>
int main( int argc, char **argv )
{
	int i;
	int ch;
	int flag = 0;

	while( (ch = getopt( argc, argv, "al")) != -1 )
	{
		switch(ch)
		{
			case 'a' : flag |= 1; break;  // 0001
			case 'l' : flag |= 2; break;  // 0010
					                      // 0011
		}
	}
	if(flag & 1)
		printf("a option\n");
	if(flag & 2)
		printf("l option\n");
	return 0;
}
#endif



#if 0
#include <stdio.h>
#include <unistd.h>
int main( int argc, char **argv )
{
	int i;
	int ch;

	while( (ch = getopt( argc, argv, "al")) != -1 )
	{
		switch(ch)
		{
			case 'a' : printf("a option\n"); break;
			case 'l' : printf("l option\n"); break;
		}
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <unistd.h>
int main( int argc, char **argv )
{
	int i;
	int ch;

	while( (ch = getopt( argc, argv, "al")) != -1 )
		printf("%c\n",  ch );
	printf("\n");
	return 0;
}
#endif



#if 0
#include <stdio.h>
int main( int argc, char **argv )
{
	int i;

	for(i=0; i<argc; i++ )
		printf("%s ",  argv[i] );
	printf("\n");
	return 0;
}
#endif

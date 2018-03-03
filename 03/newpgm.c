#include <stdio.h>
// # ./newpgm  one     two
//   argv[0]  argv[1]  argv[2]
//   argc=3
int main( int argc, char **argv )
{
	int i;

	for(i=0; i<argc; i++ )
	{
		printf("argv[%d]=[%s]\n", i, argv[i] );
	}
	return 0;
}

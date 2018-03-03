#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	struct stat buf;
	char perm[11] = "----------";
	char rwx[] = "rwx";
	char sst[] = "sst";
	int i;
	stat( argv[1], &buf );

	for( i=0; i<9; i++ )
	{
		if( (buf.st_mode >> (8-i)) & 0x1 )
		{
			perm[1+i] = rwx[i%3];
		}
	}
	for( i=0; i<3; i++ )
	{
		if( (buf.st_mode >> (11-i)) & 0x1 )
		{
			if( perm[(i+1)*3] == '-' )
				perm[(i+1)*3] = sst[i]-('a'-'A');
			else
				perm[(i+1)*3] = sst[i];
		}
	}
	printf("%s\n", perm );
	return 0;
}


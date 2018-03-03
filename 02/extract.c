#include <stdio.h>
typedef struct
{
	char fname[20];
	int  fsize;
} INFO;
// # extract  target
int main( int argc, char **argv )
{
	FILE *src, *dst;
	INFO info;
	int ret, len;
	char buffer[1024];
	if( argc != 2 )
	{
		printf("usage : extract  source\n");
		return -1;
	}
	src = fopen( argv[1], "r" );

	while( fread( &info, sizeof(INFO), 1, src) )
	{
		dst = fopen( info.fname, "w" );
		while(info.fsize > 0)
		{
			len = (sizeof(buffer)<info.fsize)?sizeof(buffer):info.fsize;
			ret = fread( buffer, 1, len, src );
			fwrite( buffer, 1, ret, dst );
			info.fsize -= ret;
		}
		fclose(dst);
	}

	fclose(src);
	return 0;
}

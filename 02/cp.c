#include <stdio.h>
int main( int argc, char **argv )
{
	FILE *src, *dst;
	int ret;
	char buffer[1024];
	if( argc != 3 )
	{
		printf("usage : cp  source   dest\n");
		return -1;
	}
	src = fopen( argv[1], "r" );
	dst = fopen( argv[2], "w" );

	while( ret = fread( buffer, 1, sizeof buffer, src ) )
		fwrite( buffer, 1, ret, dst );

	fclose(src);
	fclose(dst);
	return 0;
}

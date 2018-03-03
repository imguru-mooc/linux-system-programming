#include <stdio.h>
#include <string.h>

typedef struct
{
	char fname[20];
	int  fsize;
} INFO;

int get_fsize(FILE *fp)
{
	int fsize, fpos;
	fpos  = ftell( fp );
	fseek( fp, 0, SEEK_END );
	fsize = ftell( fp );
	fseek( fp, fpos, SEEK_SET );
	return fsize;
}

int main( int argc, char **argv )
{
	FILE *src, *dst;
	int ret, i;
	char buffer[1024];
	INFO info;
	if( argc < 4 )
	{
		printf("usage : merge  src1  src2  ...   dest\n");
		return -1;
	}
	dst = fopen( argv[argc-1], "w" );

	for(i=0; i<argc-2; i++ )
	{
		src = fopen( argv[i+1], "r" );
		info.fsize = get_fsize(src);
		strcpy(info.fname, argv[i+1] );
		fwrite( &info, sizeof(INFO), 1, dst );
		while( ret = fread( buffer, 1, sizeof buffer, src ) )
			fwrite( buffer, 1, ret, dst );
		fclose(src);
	}

	fclose(dst);
	return 0;
}

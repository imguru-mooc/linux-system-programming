#include <stdio.h>
// ./a.out aaa
// 6

int get_fsize(FILE *fp)
{
	int fsize, fpos;
	fpos  = ftell( fp );
	fseek( fp, 0, SEEK_END );
	fsize = ftell( fp );
	fseek( fp, fpos, SEEK_SET );
	return fsize;
}

int main(int argc, char **argv)
{
	FILE *fp;
	int fsize;
	char buff[1024];
	int ret;

	fp = fopen( argv[1], "r" );
	fgets( buff, sizeof buff, fp);
	fputs( buff, stdout );
	fsize = get_fsize(fp);
	fgets( buff, sizeof buff, fp);
	fputs( buff, stdout );
	fclose(fp);
	printf("%s size=%d\n", argv[1], fsize );
	return 0;
}







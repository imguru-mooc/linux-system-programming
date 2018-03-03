#include <stdio.h>
int main(int argc, char **argv)
{
	FILE *fp;
	char buff[1024];
	int ret;

	fp = fopen( argv[1], "r" );

	ret = fread( buff, 1, 2, fp );
	fwrite( buff, 1, ret, stdout );
	getchar();

	ret = fread( buff, 1, 2, fp );
	fwrite( buff, 1, ret, stdout );

	fclose(fp);
	return 0;
}

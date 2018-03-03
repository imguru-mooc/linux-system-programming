#include <stdio.h>

int main( int argc, char **argv)
{
	FILE *fp;
	int ret;
	char buff[1024];

	fp = fopen( argv[1], "r" );
	while( ret = fread( buff, 1, sizeof buff, fp) ) 
		fwrite( buff, 1, ret , stdout );
	fclose(fp);
	return 0;
}

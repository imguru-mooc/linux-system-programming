#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	FILE *fp;
	char buff[1000];
	int ret;
	fp = fopen(argv[1], "r");
	while(ret = fread(buff, 1, sizeof buff , fp))
	{
		usleep(100000);
		//printf("ret=%d\n", ret );
		fwrite(buff, 1, ret, stdout);
		fflush( stdout );
	}
	fclose(fp);
	return 0;
}

#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	FILE *fp;
	char buff[1024];
	fp = fopen(argv[1], "r");
	while(fgets(buff, sizeof buff , fp))
	{
		usleep(100000);
		fputs(buff, stdout);
		fflush( stdout );
	}
	fclose(fp);
	return 0;
}

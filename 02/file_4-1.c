#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	char buff[1024];
	FILE *fp;

	fp = fopen(argv[1], "r");
	while(fgets(buff, sizeof buff, fp))
	{
		fputs(buff, stdout);
		fflush(stdout);
		usleep(100000);
	}
	return 0;
}

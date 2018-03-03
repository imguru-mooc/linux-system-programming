#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	FILE *fp;
	int ch;
	fp = fopen(argv[1], "r");
	while((ch = fgetc(fp)) != EOF)
	{
		usleep(100000);
		fputc(ch, stdout);
		fflush( stdout );
	}
	fclose(fp);
	return 0;
}

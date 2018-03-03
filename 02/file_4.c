#include <stdio.h>
int main(int argc, char **argv)
{
	char buff[1024];
	while(fgets(buff, sizeof buff, stdin))
		fputs(buff, stderr);
	return 0;
}

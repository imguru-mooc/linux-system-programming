#include <stdio.h>
int main()
{
	FILE *fp;
	int ch;
	fp = fopen("aaa", "r");
	ch = fgetc(fp);
	fputc(ch, stdout);
	fclose(fp);
	return 0;
}

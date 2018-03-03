#include <stdio.h>
int main()
{
	FILE *fp;
	int ch;
	fp = fopen("aaa", "r");
	while((ch = fgetc(fp)) != EOF)
		fputc(ch, stdout);
	fclose(fp);
	return 0;
}

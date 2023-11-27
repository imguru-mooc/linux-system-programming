#include <stdio.h>
#include <errno.h>
#include <string.h>

#if 1
int main()
{
	FILE *fp;
	fp = fopen("aaa", "w");  // O_WRONLY | O_TRUNC | O_CREAT, 0666

	printf("fp=%p, errno=%d, strerror=%s\n", fp, errno, strerror(errno) );

	return 0;
}
#endif

#if 0
int main()
{
	FILE *fp;
	fp = fopen("aaa", "r");

	printf("fp=%p, errno=%d, strerror=%s\n", fp, errno, strerror(errno) );

	return 0;
}
#endif

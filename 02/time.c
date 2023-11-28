#include <time.h>
#include <stdio.h>

int main()
{
	struct tm *tmp;
	time_t now;
	now = time(0);
	printf("%ld\n", now);

	tmp = localtime( &now );
	printf("%04d-%02d-%02d %02d:%02d\n", tmp->tm_year+1900,
			tmp->tm_mon+1, tmp->tm_mday,
			tmp->tm_hour, tmp->tm_min  );

	return 0;
}

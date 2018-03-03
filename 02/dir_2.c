#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

void my_ls( char *d_name )
{
	DIR *dp;
	struct dirent *p;
	chdir( d_name );
	dp = opendir(".");
	while( p = readdir(dp) )
		printf("%s\n", p->d_name );
	closedir(dp);
	chdir("..");
}

int main()
{
	my_ls(".");
	return 0;
}

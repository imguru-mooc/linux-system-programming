#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

void my_ls( char *d_name )
{
	DIR *dp;
	struct dirent *p;
	struct stat buf;
	chdir( d_name );
	dp = opendir(".");
	while( p = readdir(dp) )
	{
		printf("%s\n", p->d_name );
		lstat( p->d_name, &buf );
		if( S_ISDIR(buf.st_mode) )
		{
			if( strcmp( p->d_name , "." ) &&  strcmp( p->d_name , ".." ) ) 
				my_ls( p->d_name );
		}
	}
	closedir(dp);
	chdir("..");
}

int main()
{
	my_ls(".");
	return 0;
}

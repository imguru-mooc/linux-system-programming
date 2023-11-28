#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char **argv)
{
	struct stat buf;
	struct passwd *pwd;
	struct group *grp;
	stat( argv[1], &buf );

	pwd = getpwuid( buf.st_uid );
	grp = getgrgid( buf.st_gid );
	printf("%s %s\n", pwd->pw_name, grp->gr_name );
	return 0;
}


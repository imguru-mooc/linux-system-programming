#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
int  main(int argc, char *argv[]){
	int i;
	struct stat	buf;
	struct passwd  *pwd;
	struct group  *grp;
	struct tm  *tmp;
	char perm[] = "----------";
	char rwx[] = "rwx";
	char sst[] = "sst";
	char	*ptr;

	lstat(argv[1], &buf);
	if      (S_ISDIR(buf.st_mode))	perm[0] = 'd'; 
	else if (S_ISCHR(buf.st_mode))	perm[0] = 'c';
	else if (S_ISBLK(buf.st_mode))	perm[0] = 'b';
	else if (S_ISFIFO(buf.st_mode))	perm[0] = 'p';
	else if (S_ISLNK(buf.st_mode))	perm[0] = 'l';
	else if (S_ISSOCK(buf.st_mode))	perm[0] = 's';

	for( i=0; i<9; i++ )
	{
		if( (buf.st_mode >> (8-i)) & 0x1 )
		{
			perm[1+i] = rwx[i%3];
		}
	}
	for( i=0; i<3; i++ )
	{
		if( (buf.st_mode >> (11-i)) & 0x1 )
		{
			if( perm[(i+1)*3] == '-' )
				perm[(i+1)*3] = sst[i]-('a'-'A');
			else
				perm[(i+1)*3] = sst[i];
		}
	}
	printf("%s ", perm);
	printf("%lu ", buf.st_nlink);
	pwd = getpwuid( buf.st_uid );
	printf("%s ", pwd->pw_name);
	grp = getgrgid( buf.st_gid );
	printf("%s ", grp->gr_name);
	if( perm[0] == 'c' || perm[0] == 'b' )
		printf("%lu, %lu ", (buf.st_rdev>>8)&0xff, buf.st_rdev&0xff);
	else
		printf("%lu ", buf.st_size);

	// 2월 19 15:22
	tmp = localtime(&buf.st_mtime );
	printf("%2d월 %2d %02d:%02d ", tmp->tm_mon+1, tmp->tm_mday, tmp->tm_hour, tmp->tm_min );
	if( perm[0] == 'l' )
	{
		char buff[256];
		int ret;
		ret = readlink( argv[1], buff, sizeof buff );
		buff[ret] = 0;
		printf("%s -> %s\n", argv[1] , buff);
	}
	else
		printf("%s\n", argv[1]);
}






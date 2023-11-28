#include <unistd.h>
int main()
{
	//execl("/usr/bin/ls", "ls", "-l", (char*)0 );
	execl("./newpgm", "newpgm", "one", "two", (char*)0 );
	return 0;
}

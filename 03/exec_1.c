#include <unistd.h>
int main()
{
	//execl("/bin/ls", "ls", "-l", (char*)0 );
	execl("./newpgm", "newpgm", "one", "two", (char*)0 );
	return 0;
}

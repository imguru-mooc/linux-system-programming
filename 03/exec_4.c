#include <unistd.h>
int main()
{
	//execl("/bin/ls", "ls", "-l", (char*)0 );
	execlp("ls", "ls", "-l", (char*)0 );
	return 0;
}

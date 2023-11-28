#include <unistd.h>
int main()
{
	char *argv[] = {"newpgm", "one", "two", (char*)0};
	char *env[] = {"name=kji", "addr=seoul", (char*)0};
	execve("./newpgm", argv, env );
	return 0;
}

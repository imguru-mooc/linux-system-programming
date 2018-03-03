#include <unistd.h>
int main()
{
	char *argv[] = {"newpgm", "one", "two", (char*)0};
	execv("./newpgm", argv );
	return 0;
}

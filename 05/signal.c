#include <signal.h>
#include <unistd.h>

void foo(int sig)
{
}

int main()
{
	signal( SIGINT, SIG_IGN );
	signal( SIGQUIT, SIG_IGN );
	signal( SIGKILL, foo );
	while(1)
		pause();
	return 0;
}

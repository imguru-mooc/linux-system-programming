#include <signal.h>
int main()
{
	signal( SIGINT, SIG_IGN );
	signal( SIGQUIT, SIG_IGN );
	signal( SIGKILL, SIG_IGN );
	while(1)
		;
	return 0;
}

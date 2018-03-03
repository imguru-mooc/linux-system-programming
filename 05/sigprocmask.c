#include <signal.h>
#include <unistd.h>

int main()
{
	sigset_t set;
	sigset_t oldset;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigprocmask( SIG_BLOCK, &set, &oldset);
	sleep(3);	
	sigprocmask( SIG_SETMASK, &oldset, 0);
	while(1);
	return 0;
}

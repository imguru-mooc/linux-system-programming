#include <signal.h>
#include <unistd.h>

int main()
{
	sigset_t set;          // long set;
	sigset_t oldset;

	sigemptyset(&set);     // set = 0;
	sigaddset(&set, SIGINT);  // set |= 1<<(SIGINT-1);
	sigprocmask( SIG_BLOCK, &set, &oldset);  // *oldset = kernel_set;
	                                         // kernel_set |= *set;   
	sleep(3);	
	sigprocmask( SIG_SETMASK, &oldset, 0);   // kernel_set = *oldset;
	while(1);
	return 0;
}

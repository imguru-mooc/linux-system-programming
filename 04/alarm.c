#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main()
{
	int seconds;
	char line[128];
	char message[64];

	while(1)
	{
		printf("Alarm>");
		fgets( line, sizeof line, stdin ); // "10 hello\n"
		sscanf( line, "%d %64[^\n]", &seconds, message ); 
		sleep(seconds);
		printf("(%d) %s\n", seconds, message );
	}
	return 0;
}

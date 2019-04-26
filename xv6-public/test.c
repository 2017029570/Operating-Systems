#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) 
{
		int pid = getpid();

		for(int i=0;i<2;i++) {
				pid = fork();

				printf(1,"%d\n",pid);
		}
	exit();
}

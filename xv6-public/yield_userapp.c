#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc, char *argv[]) {
		int pid = fork();
		for(int i=0;i<50;i++) {
			if(pid == 0) {
		//			my_yield();
					printf(1,"Child\n");
					my_yield();
			}
			else if(pid>0) {
					//my_yield();
					printf(1,"Parent\n");
					my_yield();
			}
			//else exit();
		}
		if(pid > 0 ) {
				wait();
				exit();
		}
		else exit();

}

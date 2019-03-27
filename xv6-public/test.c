#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
		int ret_val1 = getppid();
		int ret_val2 = getpid();

		printf(1,"My pid is %d\nMy ppid is %d\n",ret_val2, ret_val1);
		exit();
}



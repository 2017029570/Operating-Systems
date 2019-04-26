#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
getlev(void) {
		struct proc *p = myproc();
		struct cpu *c = mycpu();

		for(int level = 0; level<3;level++) {
				for(int index = 0;index < c->qcount[level];index++) {
						if(c->queue[level][index] == p)
								return level;
				}
		}
		return -1;
}

int
sys_getlev(void)
{
		return getlev();
}



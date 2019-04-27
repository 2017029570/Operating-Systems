#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
run_MLFQ(void) {

		struct proc *p = myproc();
		p->mlfq = 1;
		if(mlfq_ticket() <= 2000) {
				p->mlfq_level = 0;
				return 0;
		}

		else {
				p->mlfq = 0;
				return -1;
		}

}


int
sys_run_MLFQ(void)
{
		return run_MLFQ();
}


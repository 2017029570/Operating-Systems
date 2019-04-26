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
		struct cpu *c = mycpu();
		
		c->mlfq_ticket += p->ticket;
		if(c->mlfq_ticket<MAX_TICKET) {
			p->mlfq = 1;
			c->queue[0][c->qcount[0]] = p;
			c->qcount[0] += 1;
			return 1;
		}

		else {
				c->mlfq_ticket -= p->ticket;
				return -1;
		}
}


int
sys_run_MLFQ(void)
{
		return run_MLFQ();
}


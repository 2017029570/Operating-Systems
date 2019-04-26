#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
cpu_share(int ticket) 
{
		if(ticket < CPU_TICKET*0.2) {
				myproc()->ticket = ticket;
			//	cprintf("ticket %d\n",myproc()->ticket);
				return 0;
		}
		
		else cprintf("Too much ticket\n");
		return -1;
}

int
sys_cpu_share(void) 
{
		int ticket;

		if(argint(0, &ticket) < 0) 
				return -1;


		return cpu_share(ticket);
}

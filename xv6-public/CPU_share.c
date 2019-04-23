#include "types.h"
#include "defs.h"
#include "proc.h"

void
CPU_share(proc* p, int ticket)
{
	if(ticket < cpu.ticket * 0.2) 
			p->ticket = ticket;

	else print("Can't get %d tickets\n",ticket);
}

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
		return myproc()->mlfq_level;
}

int
sys_getlev(void)
{
		return getlev();
}



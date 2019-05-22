#include "types.h"
#include "x86.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "stat.h"
#include "fcntl.h"
#include "fs.h"
#include "syscall.h"
#include "traps.h"
#include "defs.h"

int
thread_create(thread_t * thread, void * (*start_routine)(void*), void *arg) 
{

		void *stack;
/*		if((uint)stack <= 0) 
				return -1;
		if((uint)stack%PGSIZE) {
				stack += 4096 - ((uint)stack%PGSIZE);
		}*/
		if(argptr(1,(void*)&stack, sizeof(*stack))<0) return -1;

		if((uint)stack % PGSIZE) 
				stack += PGSIZE - ((uint)stack%PGSIZE);

		*thread = tcreate(start_routine, arg, stack);
		return 0;
}

int 
thread_join(thread_t thread, void **retval)
{
		void *stack;
		if(join((uint)thread, retval,&stack)<0) {
				return -1;
		}
		stack = 0;
		return 0;
}

void
thread_exit(void *retval)
{		
//		cprintf("exit\n");
	//	exit();
		texit(retval);
}

int
sys_thread_create(void)
{
		thread_t *thread;
		void* (*start_routine)(void*);
		void *arg;

		if(argint(0, (int*)&thread)<0)
				return -1;
		if(argptr(1, (void*)&start_routine, sizeof(start_routine)<0))
						return -1;
		if(argptr(2, (void*)&arg, sizeof(arg) <0))
				return -1;
		
		return thread_create(thread, start_routine, arg);
}

int
sys_thread_join(void)
{
		thread_t thread;
		void **retval;

		if(argint(0, (int*)&thread)<0)
				return -1;
		if(argptr(1, (void*)&retval, sizeof(retval)<0))
				return -1;

		return thread_join(thread, retval);
}

int
sys_thread_exit(void)
{
		void* retval;

		if(argptr(0,(void*)&retval, sizeof(*retval))<0) {
//cprintf("%d\n",(int)retval);
				return -1;
		}

		thread_exit(retval);
		return 0;
}

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
sync(void) {
		return fsync();
}

int
get_log_num(void) {
		return fget_log_num();
}

int
sys_sync(void) {
		return sync();
}

int
sys_get_log_num(void) {
		return get_log_num();
}

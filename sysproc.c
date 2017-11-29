#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "container.h"


int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getname(void)
{
  int index;
  char *name;

  if(argint(0, &index) < 0 || argstr(1, &name) < 0){
    return -1;
  }

  return getname(index, name);
}

int
sys_setname(void)
{
  int index;
  char *name;

  if(argint(0, &index) < 0 || argstr(1, &name) < 0){
    return -1;
  }

  return setname(index, name);
}

int
sys_getmaxproc(void)
{
  int index;

  if(argint(0, &index) < 0){
    return -1;
  }

  return getmaxproc(index);
}

int
sys_setmaxproc(void)
{
  int index, max;

  if(argint(0, &index) < 0 || argint(1, &max)){
    return -1;
  }

  return setmaxproc(index, max);
}

int
sys_getmaxmem(void)
{
  int index;

  if(argint(0, &index) < 0){
    return -1;
  }

  return getmaxmem(index);
}

int
sys_setmaxmem(void)
{
  int index, max;

  if(argint(0, &index) < 0 || argint(1, &max)){
    return -1;
  }

  return setmaxmem(index, max);
}

int
sys_getmaxdisk(void)
{
  int index;

  if(argint(0, &index) < 0){
    return -1;
  }

  return getmaxdisk(index);
}

int
sys_setmaxdisk(void)
{
  int index, max;

  if(argint(0, &index) < 0 || argint(1, &max)){
    return -1;
  }

  return setmaxdisk(index, max);
}

int
sys_getusedmem(void)
{
  int index;

  if(argint(0, &index) < 0){
    return -1;
  }

  return getusedmem(index);
}

int
sys_setusedmem(void)
{
  int index, max;

  if(argint(0, &index) < 0 || argint(1, &max)){
    return -1;
  }

  return setusedmem(index, max);
}

int
sys_getuseddisk(void)
{
  int index;

  if(argint(0, &index) < 0){
    return -1;
  }

  return getuseddisk(index);
}

int
sys_setuseddisk(void)
{
  int index, max;

  if(argint(0, &index) < 0 || argint(1, &max)){
    return -1;
  }

  return setuseddisk(index, max);
}


int
sys_setvc(void){
  int index;
  char *vc;

  if(argint(0, &index) < 0 || argstr(1, &vc) < 0){
    return -1;
  }

  return setvc(index, vc);
}

int
sys_setactivefs(void){
  char *fs;

  if(argstr(0, &fs) < 0){
    return -1;
  }

  return setactivefs(fs);
}

int
sys_getactivefs(void){
  char *fs;

  if(argstr(0, &fs) < 0){
    return -1;
  }

  return getactivefs(fs);
}


int
sys_getvcfs(void){
  char *vc;
  char *fs;

  if(argstr(0, &vc) < 0 || argstr(1, &fs) < 0){
    return -1;
  }

  return getvcfs(vc, fs);
}

int
sys_tostring(void){
  char *string;

  if(argstr(0, &string) < 0){
    return -1;
  }

  return tostring(string);
}


int
sys_getactivefsindex(void){
    return getactivefsindex();
}

int
sys_setatroot(void){
  int index, val;

  if(argint(0, &index) < 0 || argint(1, &val) < 0){
    return -1;
  }

  return setatroot(index, val);
}

int
sys_getatroot(void){
  int index;

  if(argint(0, &index) < 0){
    return -1;
  }

  return getatroot(index);
}

int
sys_getpath(void){
  int index;
  char *path;

  if(argint(0, &index) < 0 || argstr(1, &path) < 0){
    return -1;
  }

  return getpath(index, path);
}

int
sys_setpath(void){
  int index, remove;
  char *path;

  if(argint(0, &index) < 0 || argstr(1, &path) < 0 || argint(2, &remove) < 0){
    return -1;
  }

  return setpath(index, path, remove);
}

int
sys_ps(void){
  // char* container;

  // if(argstr(0, &container) < 0){
  //   return -1;
  // }
  // return ps(container);

  procdump();
  return 0;
}




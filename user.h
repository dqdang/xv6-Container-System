#include "types.h"
struct stat;
struct rtcdate;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(char*, int);
int mknod(char*, short, short);
int unlink(char*);
int fstat(int fd, struct stat*);
int link(char*, char*);
int mkdir(char*);
int chdir(char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int getname(int, char*);
int setname(int, char*);
int getmaxproc(int);
int setmaxproc(int, int);
int getmaxmem(int);
int setmaxmem(int, int);
int getmaxdisk(int);
int setmaxdisk(int, int);
int getusedmem(int);
int setusedmem(int, int);
int getuseddisk(int);
int setuseddisk(int, int);
int getalluseddisk(void);
int setalluseddisk(int);
int getallmaxdisk(void);
int setallmaxdisk(int);
int getallusedmem(void);
int setallusedmem(int);
int getallmaxmem(void);
int setallmaxmem(int);
int setvc(int, char*);
int setactivefs(char*);
int getactivefs(char*);
int getvcfs(char*, char*);
int getcwd(void*, int);
int tostring(char*);
int getactivefsindex(void);
int setatroot(int, int);
int getatroot(int);
int getpath(int, char*);
int setpath(int, char*, int);
int ps(void);



// ulib.c
int stat(char*, struct stat*);
char *strcpy(char*, char*);
void *memmove(void*, void*, int);
char *strchr(const char*, char c);
int strcspn(const char *, const char *);
int strcmp(const char*, const char*);
int strncmp(const char*, const char *, uint);
int strstr(char*, char*);
char *strcat(char*, const char*);
char *strtok(char*, const char*);
uint strtoul(char*, char**, int);
int strtol(char*, char**, int);
int isspace(unsigned char);
void printf(int, char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
void itoa(int, char*, int);
int copy(char*, char*, int, int);
int isfscmd(char* cmd);
int ifsafepath(char *path);



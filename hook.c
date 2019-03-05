#include <stdio.h>
#include <unistd.h> 
#include <dlfcn.h>

/*
 * hook的目标是 write，所以 typedef 了一个 WRITE 函数指针
 * hook的目的是要控制函数行为，从原库 libc.so.6 中拿到 WRITE 指针，保存成 old_write 以备调用
 * 如果程序中使用 dlopen、dlsym、dlclose、dlerror 显示加载动态库，需要设置链接选项 -ldl
 */
typedef ssize_t(*WRITE)(int, const void*, size_t);


ssize_t write(int fd, const void *buf, size_t count)
{
	//printf("WEIFEI HOOK Write\n"); //会无限循环的 2333
	
	static void *handle = NULL;
	static WRITE old_write = NULL;

	if(!handle)
	{
		handle = dlopen("libc.so.6", RTLD_LAZY);
		old_write = (WRITE)dlsym(handle, "write");
	}
	old_write(1, "WEIFEI HOOK Write\n", 18);
	sleep(2); 
	return old_write(fd, buf, count);
}

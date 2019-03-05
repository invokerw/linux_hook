#include <stdio.h>
#include <unistd.h> 
#include <dlfcn.h>

/*
 * hook��Ŀ���� write������ typedef ��һ�� WRITE ����ָ��
 * hook��Ŀ����Ҫ���ƺ�����Ϊ����ԭ�� libc.so.6 ���õ� WRITE ָ�룬����� old_write �Ա�����
 * ���������ʹ�� dlopen��dlsym��dlclose��dlerror ��ʾ���ض�̬�⣬��Ҫ��������ѡ�� -ldl
 */
typedef ssize_t(*WRITE)(int, const void*, size_t);


ssize_t write(int fd, const void *buf, size_t count)
{
	//printf("WEIFEI HOOK Write\n"); //������ѭ���� 2333
	
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

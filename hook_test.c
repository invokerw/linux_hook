#include <stdio.h>
#include <string.h>

int main()
{
	const char *str = "Hello World!\n";
	int n = write(1, (const void *)str, (size_t)strlen(str));
	printf("main::n = %d\n", n);

	return 0;
}

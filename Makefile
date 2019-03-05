
# 如果想创建一个动态链接库，可以使用 GCC 的-shared选项。输入文件可以是源文件、汇编文件或者目标文件。
# 另外还得结合-fPIC选项。-fPIC 选项作用于编译阶段，告诉编译器产生与位置无关代码（Position-Independent Code）；这样一来，产生的代码中就没有绝对地址了，全部使用相对地址，所以代码可以被加载器加载到内存的任意位置，都可以正确的执行。这正是共享库所要求的，共享库被加载时，在内存的位置不是固定的。


# 如果你的程序中使用dlopen、dlsym、dlclose、dlerror 显示加载动态库，需要设置链接选项 -ldl


all: hook.so hook_test

hook.so:
	gcc -o hook.so hook.c -fPIC -ldl --shared #编译为共享库

hook_test:
	gcc -o hook_test hook_test.c 


clean:
	rm -rf hook.so hook_test


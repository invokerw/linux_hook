
# ����봴��һ����̬���ӿ⣬����ʹ�� GCC ��-sharedѡ������ļ�������Դ�ļ�������ļ�����Ŀ���ļ���
# ���⻹�ý��-fPICѡ�-fPIC ѡ�������ڱ���׶Σ����߱�����������λ���޹ش��루Position-Independent Code��������һ���������Ĵ����о�û�о��Ե�ַ�ˣ�ȫ��ʹ����Ե�ַ�����Դ�����Ա����������ص��ڴ������λ�ã���������ȷ��ִ�С������ǹ������Ҫ��ģ�����ⱻ����ʱ�����ڴ��λ�ò��ǹ̶��ġ�


# �����ĳ�����ʹ��dlopen��dlsym��dlclose��dlerror ��ʾ���ض�̬�⣬��Ҫ��������ѡ�� -ldl


all: hook.so hook_test

hook.so:
	gcc -o hook.so hook.c -fPIC -ldl --shared #����Ϊ�����

hook_test:
	gcc -o hook_test hook_test.c 


clean:
	rm -rf hook.so hook_test


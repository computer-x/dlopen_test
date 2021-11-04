#include <stdio.h>
#include <dlfcn.h>

int aaa = 100;

int main()
{

    void *pdlhandle;
    char *pdlerror;


    int(*myadd)(int a, int b);

    pdlhandle = dlopen("../libadd.so", RTLD_LAZY);
    pdlerror = dlerror();
    if(0 != pdlerror){
	printf("%s\n", pdlerror);
	return 1;
    }


    printf("aaa(before) = %d\n", aaa);

    myadd = dlsym(pdlhandle, "add");
    if(0 != pdlerror){
        printf("%s\n", pdlerror);
        return 1;
    }

    printf("aaa(after) = %d\n", aaa);

    int a = 19, b = 100;
    int c = myadd(a, b);
    printf("a=%d, b=%d, a+b=%d\n", a, b, c);

    return 0;
}

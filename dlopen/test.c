#include <stdio.h>
#include <dlfcn.h>

//extern int aaa = 0;

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

    myadd = dlsym(pdlhandle, "add");
    if(0 != pdlerror){
        printf("%s\n", pdlerror);
        return 1;
    }


    int a = 19, b = 100;
    int c = myadd(a, b);
    printf("a=%d, b=%d, a+b=%d\n", a, b, c);

    return 0;
}

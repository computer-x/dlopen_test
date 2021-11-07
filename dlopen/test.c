#include <stdio.h>
#include <dlfcn.h>

int aaa = 100;

int main()
{
    void *pdlhandle1, *pdlhandle2;
    char *pdlerror;

    int(*myadd)(int a, int b);

    pdlhandle1 = dlopen("../libadd.so", RTLD_LAZY);
    pdlerror = dlerror();
    if(0 != pdlerror){
	printf("%s\n", pdlerror);
	return 1;
    }

    printf("aaa(before) = %d\n", aaa);

    myadd = dlsym(pdlhandle1, "add");
    if(0 != pdlerror){
        printf("%s\n", pdlerror);
        return 1;
    }
    int a = 19, b = 100;
    int c = myadd(a, b);
    printf("a=%d, b=%d, a+b=%d\n", a, b, c);
    printf("aaa(after1) = %d\n", aaa);


    int (*my_print_add)(int a, int b);
    pdlhandle2 = dlopen("../nest/libdouble.so", RTLD_LAZY);
    if(0 != pdlerror){
        printf("%s\n", pdlerror);
        return 1;
    }
    my_print_add = dlsym(pdlhandle2, "print_add");
    if(0 != pdlerror){
        printf("%s\n", pdlerror);
        return 1;
    }
    my_print_add(29, 300);
    printf("aaa(after2) = %d\n", aaa);


//    //this way will wrong
//    int (*myadd2)(int a, int b);
//    myadd2 = dlopen("../nest/libdouble.so", RTLD_LAZY);
//    pdlhandle2 = dlopen("../nest/libdouble.so", RTLD_LAZY);
//    if(0 != pdlerror){
//        printf("%s\n", pdlerror);
//        return 1;
//    }
//    printf("============1\n");
//    int d = myadd2(a, b);
//    printf("============2\n");
//    printf("a=%d, b=%d, a+b=%d\n", a, b, d);
//    printf("aaa(after3) = %d\n", aaa);




    return 0;
}

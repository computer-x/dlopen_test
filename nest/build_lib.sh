#export LD_LIBRARY_PATH=/home/chenxu1/some_test/dlopen_test
#echo $LD_LIBRARY_PATH

gcc -fPIC -shared -o libdouble.so double.c -L .. -ladd

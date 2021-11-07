#export LD_LIBRARY_PATH=/home/chenxu/dlopen_test
#echo $LD_LIBRARY_PATH

lib_path=/home/chenxu1/some_test/dlopen_test
echo $lib_path

#gcc -o test test.c -L.. -ladd
gcc -o test test.c -L$lib_path -ladd

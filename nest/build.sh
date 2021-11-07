#export LD_LIBRARY_PATH=/home/chenxu1/some_test/dlopen_test:/home/chenxu1/some_test/dlopen_test/nest #not need
export LD_LIBRARY_PATH=/home/chenxu1/some_test/dlopen_test
echo $LD_LIBRARY_PATH

# the first way
#gcc -o test test.c -L/home/chenxu1/some_test/dlopen_test/nest -ldouble

# the second way
#lib_path=/home/chenxu1/some_test/dlopen_test/nest:/home/chenxu1/some_test/dlopen_test #not need
lib_path=/home/chenxu1/some_test/dlopen_test/nest
echo $lib_path
gcc -o test test.c -L$lib_path -ldouble

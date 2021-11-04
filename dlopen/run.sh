#export LD_LIBRARY_PATH=/home/chenxu/dlopen_test
export LD_LIBRARY_PATH=$(dirname $(pwd))
echo $LD_LIBRARY_PATH
./test

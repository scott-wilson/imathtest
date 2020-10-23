g++ -O3 -c src/c/wrapper.cpp -o src/c/wrapper.o
gcc -O3 -c src/c/speedtest.c -o src/c/speedtest.o
g++ -O3 src/c/wrapper.o src/c/speedtest.o -o c_speedtest
g++ -O3 -shared src/c/wrapper.o -o src/c/libwrapper.so

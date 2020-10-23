Setup
=====

1. `sudo apt install libilmbase-dev`
2. `cd /path/to/imathtest`
3. `./compile_cpp.sh && ./compile_c.sh && ./compile_rust.sh`
4. `./cpp_speedtest 100000` x5, `./c_speedtest 100000` x5, `LD_LIBRARY_PATH=src/c:$LD_LIBRARY_PATH ./rust_speedtest 100000` x5

System
======
AMD Ryzen 9 3950x, 32 gb of RAM, Ubuntu 20.04

Results (average clock cycles over 5 attempts each)
===================================================

| cpp original | c reimplemented | c pointer | rust c reimplmeneted | rust c pointer | rust reimplemented |
| ------------ | --------------- | --------- | -------------------- | -------------- | ------------------ |
| 138          | 2276            | 2277      | 1201                 | 1136           | 526                |

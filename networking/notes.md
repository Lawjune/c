# Installing the libsocket library

1. git clone https://github.com/dermesser/libsocket.git
2. cd libsocket
3. cmake CMakeLists.txt
4. make

## Install libsocket

1. sudo make install
2. sudo ldconfig # Tell the loader of the libraries configuration
3. cd # Back to the directory of your work

## Compiling Programs

When you compile your C program, you must link to the socket library.
Since you haven't written any programs yet this command won't work now,
but here's what it will look like:

```sh
gcc roundtrip.c -l socket
```

​http://bitbucket.org/csci46/md5

https://bitbucket.org/profbbrown/crack2/

## Hashing Algorithms

- MD5 => 128-bits
- SHA256 => 256-bits
- SHA512 => 512-bits
- bcrypt => 189-bits

```sh
md5 bible.txt
`=>
MD5 (bible.txt) = f7e2e3000b32e483a84345c4b169f86f
```

```sh
wc bible.txt
`=>
  100182  824036 4451368 bible.txt
```

_pow(2, 256) almostly equals to the number of atoms in universe._

https://cryptii.com/
https://github.com/Zunawe/md5-c

```sh
gcc myprog.c md5.c -o myprog -l crypto
```

## Rebuild OpenSSL in MacOS

1. Download the OpenSSL version from openssl.org.
2. Let's assume that we want to install the "custom" OpenSSL into /opt.
   Configure and build OpenSSL as:
   $ ./config --prefix=/opt
   $ make
   $ make install
   Those commands will install OpenSSL into /opt, with static libraries (no
   dynamic libraries).
3. Build the TURN server:
   $ ./configure --prefix=/opt
   $ make
   Those commands will build the TURN server binaries, statically linked
   against the newer OpenSSL.


## Make

`bruteforce.c` -> `gcc -c bruteforce.c` => `bruteforce.o`
`md5.c` -> `gcc -c md5.c` => `md5.o`

`gcc bruteforce.o md5.o -o bruteforce -l crypto`


`export PATH=.:/user/local/sbin:usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin`
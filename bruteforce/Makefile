# Build brutefore executable out of object files
bruteforce: bruteforce.o md5.o
	gcc bruteforce.o md5.o -o bruteforce -l crypto

crackword: crackword.o md5.o
	gcc crackword.o md5.o -o crackword -l crypto

# Build bruteforce.o out of bruteforce.c
bruteforce.o: bruteforce.c
	gcc -c bruteforce.c

crackword.o: crackword.c
	gcc -c crackword.c

# Build md5.o out of md5.c
md5.o: md5.c
	gcc -c md5.c

.phony: pizza
pizza: bruteforce
	./bruteforce 7cf2db5ec261a0fa27a502d3196a6f60

.phony: hello
hello: bruteforce
	./bruteforce 5d41402abc4b2a76b9719d911017c592

.phony: whatever
whatever: crackword
	./crackword 008c5926ca861023c1d2a36653fd88e2

.phony: Alexandra
Alexandra: crackword
	./crackword b9d8881709557855a1eea1b3c789c0ff

# test:
# 	make hello
# 	make pizza
.phony: test
test: whatever Alexandra
# test: hello pizza

.phony: clean
clean:
	rm -f *.o bruteforce crackword
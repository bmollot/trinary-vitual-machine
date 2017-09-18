CC=gcc
CFLAGS=

test: test.o tvm.o tword.o tryte.o trit.o
	$(CC) test.o tvm.o tword.o tryte.o trit.o -o test

test.o: test.c tvm.h tword.h tryte.h trit.h
	$(CC) -c test.c

tvm.o: tvm.c tvm.h tword.h tryte.h trit.h
	$(CC) -c tvm.c

tword.o: tword.c tword.h tryte.h trit.h
	$(CC) -c tword.c

tryte.o: tryte.c tryte.h trit.h
	$(CC) -c tryte.c

trit.o: trit.c trit.h
	$(CC) -c trit.c

clean:
	rm test *.o

.PHONY: clean

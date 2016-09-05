.PHONY: clean
CC=clang
CFLAGS=-I. -g -Wall --std=gnu11 -fpic

mysh: mysh.o
	$(CC) -o $@ $^ $(LDFLAGS)

testparse: testparse.o libmysh.so
	$(CC) -o $@ $< $(LDFLAGS) -lmysh -L.	

clean:
	rm -f *.o *.so mysh testparse

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

lib%.so: mysh.o
	$(CC) -shared -o $@ $^ $(LDFLAGS)

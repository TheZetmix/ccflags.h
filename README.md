## ccflags - Simple flag control library for C.

# Example:
``` c 
#include <stdio.h>
#include <ccflags.h>

int main(int argc, char **argv) {
    int test = 0;
    cc_setargs(argc, argv);
    cc_set_minimum_flags(1);
    if (cc_argexp("-st", "--set-test")) test = strtol(cc_getarg("-st"), NULL, 10);
    if (cc_argexp("-st0", "--set-test-0")) test = 0;
    if (cc_argexp("-st1", "--set-test-1")) test = 1;

    printf("%d\n", test);
    
    return 0;
}
```

# Usage:
``` console 
$ gcc -o test test.c
$ ./test -st 10
10
$ ./test -st0
0
$ ./test -st1
1
$ ./test
Error: Expected at least 1 arguments, but got only 0
Usage: ./test [options]
```
# Installation:
``` console 
$ make install # Moves ccflags.h to /usr/include
```

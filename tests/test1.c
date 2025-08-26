#include <stdio.h>
#include <stdlib.h>
#include <ccflags.h>

int main(int argc, char **argv) {
    int test = 0;
    cc_setargs(argc, argv);
    cc_set_desctiprion("Test 1"); // use it before cc_set_minimum_flags
    cc_set_minimum_flags(1);
    if (cc_argexp("-t", "--test")) {
        test = strtol(cc_getarg("-t"), NULL, 10);
    }
    printf("%d\n", test);
    
    return 0;
}

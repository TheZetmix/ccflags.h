#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int __CC_ARGC;
char **__CC_ARGV;

void __check_init() {
    if (!__CC_ARGV) {
        printf("Error: Arguments not initialized, use \"cc_setargs\"\n");
        exit(EXIT_FAILURE);
    }
}

void cc_setargs(int argc, char **argv) {
    __CC_ARGC = argc;
    __CC_ARGV = argv;
    return;
}

void cc_set_minimum_flags(int count) {
    __check_init();
    if (__CC_ARGC < count+1) {
        printf("Error: Expected at least %d arguments, but got only %d\n", count, __CC_ARGC-1);
        printf("Usage: %s [options]\n", __CC_ARGV[0]);
        exit(EXIT_FAILURE);
    }
}

int cc_arg(const char *arg) {
    __check_init();
    for (int i = 0; i < __CC_ARGC; ++i) {
        if (!strcmp(arg, __CC_ARGV[i])) return 1;
    }
    return 0;
}

int cc_argexp(const char *arg, const char *exp) {
    __check_init();
    return (cc_arg(arg) || cc_arg(exp));
}

char *cc_getarg(const char *arg) {
    __check_init();
    for (int i = 0; i < __CC_ARGC; ++i) {
        if (!strcmp(arg, __CC_ARGV[i])) {
            if (i+1 >= __CC_ARGC) {
                printf("Error: Missed argument after %s\n", arg);
                exit(EXIT_FAILURE);
            }
            if (__CC_ARGV[i+1][0] == '-') {
                printf("Error: Invalid argument after %s\n", arg);
                exit(EXIT_FAILURE);
            }
            return __CC_ARGV[i+1];
        }
    }
    printf("Error: Argument not found: %s\n", arg);
    exit(EXIT_FAILURE);
}

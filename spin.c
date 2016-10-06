#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printusage() {
        fprintf(stderr, "Usage: spin <number>\n");
}

int spin() {
    int k = 0;
    for (int j = 100000000; j > 0; j--) {
        k = j % 10;
    }
    return k;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Provide amount to spin \n");
        printusage();
        exit(1);
    }

    for (int i = 0; i < strlen(argv[1]); i++) {
        if (!isdigit(argv[1][i])) {
            fprintf(stderr, "Must provide a number\n");
            printusage();
            exit(1);
        }
    }

    int target = atoi(argv[1]);
    for (int i = 1; i <= target; i++) {
        spin();
    }
    printf("%d done spinning to %d\n", getpid(), target);
}

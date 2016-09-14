#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printusage() {
        fprintf(stderr, "Usage: counter <number>\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Provide number to count to\n");
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
        sleep(1);
        printf("PID %d: Counter %d\n", getpid(), i);
    }
}

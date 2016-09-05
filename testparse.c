#include "mysh.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_tokens(char **cmd, int max) {
    if (NULL == cmd) {
        return -1;
    }
    int token_count = 0;
    while (*cmd != NULL && token_count < max) {
        token_count++;
        cmd++;
    }
    return token_count;
}

int get_first_invalid(char **cmd, char *expected[], int count) {
    for (int i = 0; i < count; i++) {
        if (NULL == cmd[i]) {
            return -i-1;
        }
        if (strcmp(expected[i], cmd[i]) != 0) {
            return i+1;
        }
    }
    return 0;
}

int main() {
    printf("Input: \"hello world\"\n");
    char **cmd = parse_command("hello world");
    int token_count = count_tokens(cmd, 10);
    if (token_count < 0) {
        printf("ERROR: parse_command returned NULL\n");
    } else if (10 == token_count) {
        printf("ERROR: array appears to be missing NULL as the last entry\n");
    } else if (token_count != 2) {
        printf("ERROR: array should contain 2 tokens rather than %d tokens\n",
                token_count);
    } else {
        char *expected[2] = {"hello", "world"};
        int invalid_index = get_first_invalid(cmd, expected, 2);
        if (invalid_index < 0) {
            printf("ERROR: the token at index %d shouldn't be NULL\n",
                    (invalid_index + 1) * -1);
        } else if (invalid_index > 0) {
            printf("ERROR: the token at index %d should be %s not %s\n",
                    invalid_index - 1, expected[invalid_index-1], 
                    cmd[invalid_index-1]);
        } else {
            printf("Correctly parsed\n");
        }
    }

    printf("Input: \"/bin/ls -a -l /tmp\\n\"\n");
    cmd = parse_command("/bin/ls -a -l /tmp\n");
    token_count = count_tokens(cmd, 10);
    if (token_count < 0) {
        printf("ERROR: parse_command returned NULL\n");
    } else if (10 == token_count) {
        printf("ERROR: array appears to be missing NULL as the last entry\n");
    } else if (token_count != 4) {
        printf("ERROR: array should contain 4 tokens rather than %d tokens\n",
                token_count);
    } else {
        char *expected[4] = {"/bin/ls", "-a", "-l", "/tmp"};
        int invalid_index = get_first_invalid(cmd, expected, 4);
        if (invalid_index < 0) {
            printf("ERROR: the token at index %d shouldn't be NULL\n",
                    (invalid_index + 1) * -1);
        } else if (invalid_index > 0) {
            printf("ERROR: the token at index %d should be %s not %s\n",
                    invalid_index - 1, expected[invalid_index-1], 
                    cmd[invalid_index-1]);
        } else {
            printf("Correctly parsed\n");
        }
    }

    printf("Input: \"lots  of   spaces\"\n");
    cmd = parse_command("lots  of   spaces\n");
    token_count = count_tokens(cmd, 10);
    if (token_count < 0) {
        printf("ERROR: parse_command returned NULL\n");
    } else if (10 == token_count) {
        printf("ERROR: array appears to be missing NULL as the last entry\n");
    } else if (token_count != 3) {
        printf("ERROR: array should contain 3 tokens rather than %d tokens\n",
                token_count);
    } else {
        char *expected[3] = {"lots", "of", "spaces"};
        int invalid_index = get_first_invalid(cmd, expected, 3);
        if (invalid_index < 0) {
            printf("ERROR: the token at index %d shouldn't be NULL\n",
                    (invalid_index + 1) * -1);
        } else if (invalid_index > 0) {
            printf("ERROR: the token at index %d should be %s not %s\n",
                    invalid_index - 1, expected[invalid_index-1], 
                    cmd[invalid_index-1]);
        } else {
            printf("Correctly parsed\n");
        }
    }

}

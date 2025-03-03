#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    while (1) {
prompt:
        printf("> ");
        char cmdline[128];
        // TODO(bassosimone): for some reason recent commits
        // broke this loop that now runs forever.
        for (int i = 0;; i++) {
            char ch = getchar();
            putchar(ch);
            if (i == sizeof(cmdline) - 1) {
                printf("command line too long\n");
                goto prompt;
            } else if (ch == '\r') {
                printf("\n");
                cmdline[i] = '\0';
                break;
            } else {
                cmdline[i] = ch;
            }
        }

        if (strcmp(cmdline, "hello") == 0) {
            printf("Hello world from shell!\n");
        } else if (strcmp(cmdline, "exit") == 0) {
            exit(1);
        } else {
            printf("unknown command: %s\n", cmdline);
        }
    }
    return 0;
}

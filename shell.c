#include "user.h"

void main(void) {
    while (1) {
prompt:
        printk("> ");
        char cmdline[128];
        for (int i = 0;; i++) {
            char ch = getchar();
            putchar(ch);
            if (i == sizeof(cmdline) - 1) {
                printk("command line too long\n");
                goto prompt;
            } else if (ch == '\r') {
                printk("\n");
                cmdline[i] = '\0';
                break;
            } else {
                cmdline[i] = ch;
            }
        }

        if (strcmp(cmdline, "hello") == 0)
            printk("Hello world from shell!\n");
        else if (strcmp(cmdline, "exit") == 0)
            exit();
        else
            printk("unknown command: %s\n", cmdline);
    }
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

void sig_handler(int signum) {
    printf("interrupt handled\n");
}

char buf[256];
int iteration = 0;

int main() {

    struct sigaction sa;
    sa.sa_handler = sig_handler;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        fprintf(stderr, "failed sigaction\n");
	    return 1;
    }
    
    int count = read(STDIN_FILENO, buf, 256);
    if (count > 0) {
        write(STDOUT_FILENO, buf, count);
    }
    
}
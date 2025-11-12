#include <asm-generic/ioctls.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#include "mode.h"

struct winsize windowsize;

int main() {
    enableRawMode();
    editorRefreshScreen();

    while(1) {
        ioctl(0, TIOCGWINSZ, &windowsize);
        char c='\0';
        if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) die("read");
        if(iscntrl(c))
            printf("%d\r\n",c);
        else
            printf("%d ('%c')\r\n", c, c);
        if(c=='q') {
            write(STDOUT_FILENO, "\x1b[2J", 4);
            write(STDOUT_FILENO, "\x1b[H", 3);
            break;
        }
    }
    disableRawMode();
    return 0;
}

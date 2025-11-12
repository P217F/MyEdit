#include <errno.h>
#include <unistd.h>

#include "mode.h"

char editorInsertMode() {
    char c = '\0';
    int nread;
    while((nread = read(STDIN_FILENO, &c, sizeof(c))) != 1) {
        if (nread==-1 && errno!=EAGAIN) die("read");
        return c;
    }
    return 0;
}

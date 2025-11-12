#ifndef MODE_H
#define MODE_H

#include <termios.h>

void die(const char *s);
void disableRawMode();
void enableRawMode();
void editorRefreshScreen();

#endif

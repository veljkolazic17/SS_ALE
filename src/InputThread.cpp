#include "../inc/InputThread.hpp"
#define _XOPEN_SOURCE 700
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <termios.h>
// #include <unistd.h>
// #include <time.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

struct termios orig_termios;

void reset_terminal_mode()
{
    tcsetattr(0, TCSANOW, &orig_termios);
}

void set_conio_terminal_mode()
{
    struct termios new_termios;

    /* take two copies - one for now, one for later */
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));

    /* register cleanup handler, and set the new terminal mode */
    atexit(reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
}

int kbhit()
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv) > 0;
}

int getch()
{
    int r;
    unsigned char c;
    if ((r = read(0, &c, sizeof(c))) < 0) {
        return r;
    } else {
        return c;
    }
}

// int getch(void) {
//       int c=0;

//       struct termios org_opts, new_opts;
//       int res=0;
//           //-----  store old settings -----------
//       res=tcgetattr(STDIN_FILENO, &org_opts);
//           //---- set new terminal parms --------
//       memcpy(&new_opts, &org_opts, sizeof(new_opts));
//       new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
//       tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
//       c=getchar();
//           //------  restore old settings ---------
//       res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
//       return(c);
// }



InputThread::InputThread(Emulator* emulator){
    this->emulator = emulator;
}

void InputThread::run(){
    char c;
    set_conio_terminal_mode();

    while(true){
        c = getch();
        *((short*)(emulator->memory + 0xFF02)) = c;
        emulator->interupts[TERMINAL] = true;
    }
}
    
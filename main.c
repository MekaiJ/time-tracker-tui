#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

typedef struct activity{
    char *name;
    // TODO: define time saved here? not sure how.
    // perhaps with tm object specified in my notes
} activity;

activity *activites[];

int main() {
    init();
    return 0;
}

void init() {
    initscr(); // init ncurses
    cbreak(); // disable line buffering
    noecho(); // hides typed characters
    keypad(stdscr, TRUE); // enables arrow keys + other special keys
}

// TODO: func that reads in saved categories + their times from a JSON file saved for persistence.

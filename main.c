#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

typedef struct Activity{
    char *name;
    //struct tm; // a time object but i think we need to calc diff between current time and session start time, save to file, then read that here instead
    // TODO: define time saved here? not sure how.
} Activity;

Activity *activites[10];

int main() {
    // init();
   time_t start = time(NULL);
   printf("%f", (double) start);
    return 0;
}

//void init() {
//    initscr(); // init ncurses
//    cbreak(); // disable line buffering
//    noecho(); // hides typed characters
//    keypad(stdscr, TRUE); // enables arrow keys + other special keys
//}

// TODO: func that reads in saved categories + their times from a JSON file saved for persistence.

int count_time() {
    return 0;
}

void write_time(Activity activity) {

}

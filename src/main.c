#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

// declaration
void init();
void test_ncurses();

typedef struct Activity{
    char *name;
    //struct tm; // a time object but i think we need to calc diff between current time and session start time, save to file, then read that here instead
    // TODO: define time saved here? not sure how.
} Activity;

// TODO Here we will have to instantiate a var that holds the number of activities the user has
// Like the number of txt files in a directory (one txt for each activity)
Activity *activites = (Activity *)malloc(activity_num * sizeof(Activity));

int main() {
    test_ncurses();
    time_t start = time(NULL);
    printf("%f", (double) start);
    return 0;
}

void init() {
    initscr(); // init ncurses
    cbreak(); // disable line buffering
    noecho(); // hides typed characters
    keypad(stdscr, TRUE); // enables arrow keys + other special keys
}

// TODO: func that reads in saved categories + their times from a txt file saved for persistence.

int count_time(time_t time) {
    while(true) {

    }
    return 0;
}

void write_time(Activity activity) {

}

//void test_ncurses() {
//    initscr();
//    printw("hello world");
//    refresh();
//    getch();
//    endwin();
//}

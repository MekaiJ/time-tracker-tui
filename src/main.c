#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include <ncurses.h>

typedef struct Activity{
    char *name;
    //struct tm; // a time object but i think we need to calc diff between current time and session start time, save to file, then read that here instead
    // TODO: define time saved here? not sure how. - maybe add seconds elapsed since beginning
    FILE *fp;
} Activity;

// declaration
void test_ncurses(void);
void write_time(Activity activity, int time);

// TODO Here we will have to instantiate a var that holds the number of activities the user has
// Like the number of txt files in a directory (one txt for each activity)

int main() {
    struct Activity act = {"Test"};
    write_time(act, 12);
    FILE *fp = fopen("test_act.txt", "r");
    char name[128];
    char time[128];
    while(fscanf(fp, "%s\n%s", name, time) != EOF) 
        printf("%s\n%s", name, time);
    return 0;
}

//void init() {
//    initscr(); // init ncurses
//    cbreak(); // disable line buffering
//    noecho(); // hides typed characters
//    keypad(stdscr, TRUE); // enables arrow keys + other special keys
//}

// TODO: func that reads in saved categories + their times from a txt file saved for persistence.

//int count_time(time_t time) {
//    while(true) {
//
//    }
//    return 0;
//}

void write_time(Activity activity, int time) {
    FILE *temp = activity.fp;
    temp = fopen("test_act.txt", "w"); //open file for reading, and now both pointers point at the same thing 
    fprintf(temp, "name: %s\ntime: %d", activity.name, time); // write time to the file
    fclose(temp);
}

//void test_ncurses() {
//    initscr();
//    printw("hello world");
//    refresh();
//    getch();
//    endwin();
//}

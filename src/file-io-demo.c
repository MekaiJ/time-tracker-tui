#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

typedef struct Activity{
    char *name;
    FILE *fp;
} Activity;

void write_time(Activity *activity, int time);

int main() {
    struct Activity act = {"learn", fopen("learn-file.txt", "w")}; // init our activity struct
    write_time(&act, 15); // call function to write a time to the associated file
    FILE *read_fp = fopen("learn-file.txt", "r"); // open the file for reading
                                                  //
    // init the variables we will store our read data into
    char name[128];
    int time;

    // Read the entire file and print it out
    while(fscanf(read_fp, "name: %s\ntime: %d", name, &time) != EOF)// use same template as when we wrote the file in write_time() 
        printf("name: %s\ntime: %d\n", name, time);
    fclose(read_fp); //close the file reading stream
    return 0;
}

/*
 * Takes in an activity struct and an int representing the amount of seconds or minutes that have elapsed
 * Then writes them to a file
 */
void write_time(Activity *activity, int time) {
    fprintf(activity->fp, "name: %s\ntime: %d", activity->name, time); // write time to the file
    fclose(activity->fp);
}

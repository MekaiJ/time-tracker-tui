#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

typedef struct Activity{
    char *name;
    FILE *fp;
} Activity;

void write_time(Activity *activity, int time);

int main() {
    struct Activity act = {"learn", fopen("learn-file.txt", "w")};
    write_time(&act, 15);
    FILE *read_fp = fopen("learn-file.txt", "r");
    char name[128];
    int time;
    while(fscanf(read_fp, "name: %s\ntime: %d", name, &time) != EOF)// use same template as when we wrote the file in write_time() 
        printf("name: %s\ntime: %d\n", name, time);
    fclose(read_fp);
    return 0;
}

void write_time(Activity *activity, int time) {
    fprintf(activity->fp, "name: %s\ntime: %d", activity->name, time); // write time to the file
    fclose(activity->fp);
}

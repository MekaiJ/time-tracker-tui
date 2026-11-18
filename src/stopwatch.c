#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include "stopwatch.h"

volatile sig_atomic_t running = 1;


static void stop_timer(int sig) {
    (void) sig; //fix unused param warning
    running = 0; // Flip flag when Ctrl+C is pressed
}

void start_timer(void) {
    time_t start, now;
    int elapsed = 0;

    printf("Press ENTER to start the stopwatch...");
    getchar();

    signal(SIGINT, stop_timer); // Listen for Ctrl+C
    time(&start);
    printf("Stopwatch running! Press Ctrl+C to stop...\n");

    while (running) {
        time(&now);
        elapsed = (int)difftime(now, start);
        printf("\rElapsed Time: %02d:%02d (%d total seconds)   ", elapsed / 60, elapsed % 60, elapsed);
        fflush(stdout);
        sleep(1); // Wait 1 second
    }

    write_time(elapsed, "learn");
    printf("\nStopwatch stopped!\n");
}

void write_time(int elapsed, const char *activity) {
    char name[128];
    int minutes = 0;
    int seconds = 0;

    FILE *readfp = fopen("study.txt", "r");
    if (readfp != NULL) {
        fscanf(readfp, "Activity: %127[^,], Time: %d:%d", name, &minutes, &seconds);
        fclose(readfp);
    }

    int total_seconds = (minutes * 60) + seconds + elapsed;

    FILE *writefp = fopen("study.txt", "w");
    if (writefp != NULL) {
        fprintf(writefp, "Activity: %s, Time: %02d:%02d\n", activity, total_seconds / 60, total_seconds % 60);
        fclose(writefp);
    }
}


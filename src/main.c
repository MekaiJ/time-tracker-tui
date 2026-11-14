#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t start, end;

    printf("Press ENTER to start the stopwatch...");
    getchar(); // Wait for Enter key
    time(&start);

    printf("Stopwatch running! Press ENTER to stop...");
    getchar(); // Wait for Enter key again
    time(&end);

    double elapsed = difftime(end, start);
    int minutes = (int)elapsed / 60;
    int seconds = (int)elapsed % 60;

    printf("\nElapsed Time: %02d:%02d (%.0f total seconds)\n", minutes, seconds, elapsed);

    return 0;
}


// TODO: IDEA!!! Web dashboard you can self-host would be so cool to see consistency and whatnot. This would teach me some C networking as well as just prove that i'm good with C programming in general. yay. sounds amazing.

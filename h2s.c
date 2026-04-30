#include <stdio.h>

int main(int argc, char *argv[]) {
    double hours;
    double seconds;

    printf("\n");
    printf("                Clukk\n");
    printf("             Release V2.3\n");
    printf("             \n");
    printf("                 H2S\n");
    printf("\n");
    printf("\n");

    printf("Enter amount of hours: ");
    fflush(stdout);
    scanf("%lf", &hours);

    seconds = hours * 60 * 60;

    printf("Hours converted to seconds: %g\n", seconds);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char choice[10];
    double value;
    double bytes_val;

    printf("\n");
    printf("                Clukk\n");
    printf("             Release V3.0\n");
    printf("             \n");
    printf("                XB2B\n");
    printf("\n");

    printf("1. Kilobytes (KB) to Bytes.\n");
    printf("2. Megabytes (MB) to Bytes.\n");
    printf("Select (1/2): ");
    fflush(stdout);
    fgets(choice, sizeof(choice), stdin);

    choice[strcspn(choice, "\n")] = 0;

    printf("\n");

    if (strcmp(choice, "1") == 0) {
        printf("Enter amount of KB: ");
        fflush(stdout);
        scanf("%lf", &value);

        bytes_val = value * 1024;
        printf("%.6g KB converted to bytes: %.0f.\n", value, bytes_val);

    } else if (strcmp(choice, "2") == 0) {
        printf("Enter amount of MB: ");
        fflush(stdout);
        scanf("%lf", &value);

        bytes_val = value * 1024 * 1024;
        printf("%.6g MB converted to bytes: %.0f.\n", value, bytes_val);

    } else {
        printf("Error.\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #include <winsock2.h>
    #pragma comment(lib, "ws2_32.lib")
#else
    #include <netdb.h>
    #include <arpa/inet.h>
#endif

int main(int argc, char *argv[]) {
    char url[256];
    struct hostent *host_entry;
    struct in_addr **addr_list;
    char *ip;

    #ifdef _WIN32
        WSADATA wsa_data;
        if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0) {
            fprintf(stderr, "Error: WSAStartup failed\n");
            return EXIT_FAILURE;
        }
    #endif

    printf("\n");
    printf("                Clukk\n");
    printf("             Release V2.3\n");
    printf("             \n");
    printf("                URL2IP\n");
    printf("\n");
    printf("\n");

    printf("Enter URL: ");
    fflush(stdout);
    fgets(url, sizeof(url), stdin);

    url[strcspn(url, "\n")] = 0;

    host_entry = gethostbyname(url);

    if (host_entry == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname\n");
        #ifdef _WIN32
            WSACleanup();
        #endif
        return EXIT_FAILURE;
    }

    addr_list = (struct in_addr **)host_entry->h_addr_list;

    if (addr_list[0] != NULL) {
        ip = inet_ntoa(*addr_list[0]);
        printf("IP:  %s\n", ip);
    } else {
        fprintf(stderr, "Error: Could not retrieve IP address\n");
        #ifdef _WIN32
            WSACleanup();
        #endif
        return EXIT_FAILURE;
    }

    #ifdef _WIN32
        WSACleanup();
    #endif

    return EXIT_SUCCESS;
}

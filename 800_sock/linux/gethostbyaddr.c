#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("argc should be 2");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    struct hostent* host;
    host = gethostbyaddr((char*)&addr.sin_addr, 4, AF_INET);
    if (!host) {
        printf("ip wrong");
        exit(1);
    }

    printf("official name %s\n", host->h_name);
    
    int i;
    for (i = 0; host->h_aliases[i]; i++)
    {
        printf("host alias : %s\n", host->h_aliases[i]);
    }
    printf("%s\n", host->h_addrtype == AF_INET ? "AF_INET" : "AF_INET6");

    for (i = 0; host->h_addr_list[i]; i++)
    {
        printf("ip addr : %s\n", inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));
    }

    return 0;
}
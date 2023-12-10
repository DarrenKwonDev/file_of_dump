#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    WSADATA wsaData;
    
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        // do something
    };

    WSACleanup();
    return 0;
}
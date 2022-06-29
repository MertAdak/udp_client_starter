#ifndef __UDPCLIENT__
#define __UDPCLIENT__

#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class udp_client{
public:
    int sockfd;
    char client_message[256];
    struct sockaddr_in serv_addr;//server address
    socklen_t sLen = sizeof(serv_addr);

    udp_client(int port, char *message, std::string ip);
    void send_message();
};
#endif
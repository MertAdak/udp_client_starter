#include "udp_client.h"

udp_client::udp_client(int port, char *message, const char* comms_ip){
    memset(&client_message, '\0', sizeof(client_message));
    memcpy(&client_message, message, strlen(message)); //copy the argv[2] which is message int this case to the client_message
    serv_addr.sin_family      = AF_INET;
    serv_addr.sin_port        = htons(port); //htons means convert a number into 16-bit network representation
    serv_addr.sin_addr.s_addr = inet_addr(comms_ip);

    //Create socket here
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){  // int sockfd = socket(domain, type, protocol) and AF_INET uses IPv4 and SOCK_DGRAM uses Datagram Protocol=UDP
        cout<<"Cannot create socket"<<endl;
        exit(-1);   
    }
    cout<<"Socket created successfully and message is ready to be delivered!"<<endl;
    
};
void udp_client::send_message(){
if(sendto(sockfd, client_message , strlen(client_message), 0, (struct sockaddr*)&serv_addr, sLen)<0){
    std::cout << "Cannot send the message!";
    exit(-1);
}
std::cout << "client_message: " << client_message << std::endl;
close(sockfd);
exit(0);
}



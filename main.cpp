#include "udp_client.h"

using namespace std;

int main(int argc, char *argv[]){

    int port = 8080;
    char* client_message = "hello";

   // cout<<port<<" "<<client_message<<endl;

    udp_client UDP_Client = udp_client(port, client_message, "192.168.1.145");
    UDP_Client.send_message();
    
}
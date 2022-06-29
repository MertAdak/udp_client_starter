#include <fstream>
#include <SDL2/SDL.h>
#include <iostream>
#include "udp_client.h"

#define CONFIG_FILE_PATH "config/starter.config"

std::string server_ip;
int port;

bool load_Starter_Configuration(){
    std::ifstream in(CONFIG_FILE_PATH);
    if(!in.is_open()){
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Cannot open configuration ifle from %s: %s", CONFIG_FILE_PATH, strerror(errno));
        return false;
    }
    std::string param;
    std::string value;

    while(!in.eof()){//while we are not at the end of the config file 
        in >> param;
        in >> value;
        if(param == "SERVER_IP"){
            server_ip = value;
        }
        else if(param == "PORT"){
            port = stoi(value);
        }
    }
    in.close();
    //Log the configuration file
    std::cout << "Client ip: " << server_ip << std::endl;
    std::cout << "Port: " << port << std::endl;
    return true;
}

int main(int argc, char *argv[]){
    if(!load_Starter_Configuration()){
        SDL_Quit();
        return EXIT_FAILURE;
    }
    char* client_message = "Ben bu işi çözdüm";
    udp_client UDP_Client = udp_client(port, client_message, server_ip);
    UDP_Client.send_message();
}
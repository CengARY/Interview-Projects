#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

#define PORT 8080
#define BUFFER_SIZE 256

int main(){
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE] = {0};
    socklen_t client_addresslen = sizeof(server_address);

    bzero(&server_address, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int result = bind(sock, (struct sockaddr *)&server_address, sizeof(server_address));

    if(result < 0){
        std::cout << "Binding fail." << std::endl;
        return -1;
    }
    int numBytes = recvfrom(sock, buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&server_address, &client_addresslen);
    buffer[numBytes] = '\0';
    std::cout << "Received message : " << buffer << std::endl;

    return 0;
}
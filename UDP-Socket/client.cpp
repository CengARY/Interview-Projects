#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

#define PORT 8080
#define BUFFER_SIZE 256

using namespace std;

int main(){
    int sock = socket(AF_INET, SOCK_DGRAM, 0); // address, udp for data transmission, default protocol
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in server_address; 

    bzero(&server_address, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    string message = "That's Client";
    int numBytes = sendto(sock, message.c_str(), message.length(), 0, (struct sockaddr *)&server_address, sizeof(server_address));
    cout << "Message sent to server." << std::endl;

    return 0;
}
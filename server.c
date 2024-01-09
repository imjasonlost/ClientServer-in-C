#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include <unistd.h>
int main(){
    char server_message[256]="Server is connected successfully";
    // Creating the server sockets
    int server_socket=socket(AF_INET,SOCK_STREAM,0);

    //server address (IP and port)
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9021);
    server_address.sin_addr.s_addr=INADDR_ANY; //sin_addr IP address and s_addr variable
    //Bind the IP and port to the server
    bind(server_socket,(const struct sockaddr*)&server_address, sizeof(server_address));

    //Listen at the port
    listen (server_socket,5);
    // accept the incoming from the client 
    int client_sock;
    client_sock=accept(server_socket,NULL,NULL);
    //send the message on th eclient
    send(client_sock,server_message,sizeof(server_message),0);
    close(server_socket);
    return 0;
}

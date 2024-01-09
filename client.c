#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include <unistd.h>
int main(){
    
    // Creating the server sockets
    int network_socket=socket(AF_INET,SOCK_STREAM,0);

    //server address (IP and port)
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9021);
    server_address.sin_addr.s_addr=INADDR_ANY; //sin_addr IP address and s_addr variable
    
    // connection request
    int connection_status;
    connection_status=connect(network_socket,(const struct sockaddr*)&server_address,sizeof(server_address));
    if(connection_status==-1){
        printf("there is some error in connection");
    }

    //receive data from the server
    char msg[256];
    recv(network_socket,&msg,sizeof(msg),0);
    printf("the server sends the data as --> %s\n\n",msg);
    close(network_socket);
    return 0;
}

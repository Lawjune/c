#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>                     // close()
#include <libsocket/libinetsocket.h>

int main(int argc, char *argv[])
{
    // Open connection to fremont server, port 2346
    int fd = create_inet_stream_socket("fremont.cs.sierracollege.edu", 
                                        "2346", 
                                        LIBSOCKET_IPv4, 
                                        0);
    if (fd < 0)
    {
        fprintf(stderr, "Cound open connection to server: ");
        perror(NULL);
        exit(1);
    }

    // Convert file descriptor to FILE *
    FILE *sock = fdopen(fd, "r+");


    // Send HELO command
    fprintf(sock, "HELO\n");

    // Receive response
    char response[100];
    fgets(response, 100, sock);

    // Display response
    printf("Received %s", response);

    // Send DATE command
    fprintf(sock, "DATE\n");
    fgets(response, 100, sock);

    // Display response
    printf("Received %s", response);

    // Send QUIT command
    fprintf(sock, "QUIT\n");

    // Close socket
    fclose(sock);
    close(fd);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>                     // close()
#include <libsocket/libinetsocket.h>

int main(int argc, char *argv[])
{

    // fd should be 3, 1 is for input, 2 is for output
    int fd = create_inet_stream_socket("fremont.cs.sierracollege.edu", 
                                       "2345", 
                                       LIBSOCKET_IPv4, 
                                       0);
    FILE *sock = fdopen(fd, "r+");

    char greeting[100];
    fgets(greeting, 100, sock);

    printf("%s\n", greeting);

    fclose(sock);
    close(fd);

    return 0;
}
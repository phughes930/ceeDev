#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void print_bytes(in_addr_t *, int);

int main() {
    int sockfd, n;
    char sendline[100];
    char recvline[100];
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = (uint16_t)22000;
    inet_pton(AF_INET, "127.0.0.1", &(servaddr.sin_addr));
    print_bytes(&(servaddr.sin_addr.s_addr), sizeof(in_addr_t));

    int ret;
    ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret) {
        printf("Connection error\n");
    } else {
        while (1) {
            bzero(sendline, 100);
            bzero(recvline, 100);
            fgets(sendline, 100, stdin);

            write(sockfd, sendline, strlen(sendline) + 1);
            read(sockfd, recvline, 100);
            printf("%s\n", recvline);
        }
    }
}

void print_bytes(in_addr_t *loc, int num_bytes) {
    char buf[num_bytes + 1];

    for (int i = 0; i < num_bytes; i++) {
        char c = *loc++;
        if (c < 10) {
            c += 48;
        } else if (c >= 10 && c < 16) {
            c += 55;
        }
        buf[i] = c;
    }
    buf[num_bytes] = '\0';

    printf("%s", buf);
}
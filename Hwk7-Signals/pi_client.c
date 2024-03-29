/*
    Client program to get the value of PI
    This program connects to the server using sockets

    Gilberto Echeverria
    gilecheverria@yahoo.com
    21/10/2018

    Roberto Alejandro Gutierrez Guillen
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Sockets libraries
#include <netdb.h>
#include <arpa/inet.h>
// Custom libraries
#include "sockets.h"
#include "fatal_error.h"

//Signal library
#include <signal.h>
//poll library
#include <poll.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5

///// Global Variables
int interrupted = 0;

///// FUNCTION DECLARATIONS
void usage(char * program);
void requestPI(int connection_fd);
void detectInterruption(int signal);
void setUpHandlers();
void setupMask();

///// MAIN FUNCTION
int main(int argc, char * argv[]){
    int connection_fd;
    setUpHandlers();
    setupMask();

    printf("\n=== CLIENT FOR COMPUTING THE VALUE OF pi ===\n");

    // Check the correct arguments
    if (argc != 3)
    {
        usage(argv[0]);
    }

    // Start the server
    connection_fd = connectSocket(argv[1], argv[2]);
	// Listen for connections from the clients
    requestPI(connection_fd);
    // Close the socket
    close(connection_fd);

    return 0;
}

///// FUNCTION DEFINITIONS

/*Explanation to the user of the parameters required to run the program*/
void usage(char * program)
{
    printf("Usage:\n");
    printf("\t%s {server_address} {port_number}\n", program);
    exit(EXIT_FAILURE);
}


void requestPI(int connection_fd){
    char buffer[BUFFER_SIZE];
    unsigned long int iterations;
    double result;

    // Poll variables
    struct pollfd clientPoll;
    int pollRes;

    // Prepare Poll
    clientPoll.fd = connection_fd;
    clientPoll.events = POLLIN; // Wait for data to read


    printf("Enter the number of iterations for PI: ");
    scanf("%lu", &iterations);



    // Prepare the response to the client
    sprintf(buffer, "%lu", iterations);
    // SEND
    // Send the response
    sendString(connection_fd, buffer);

    while(!interrupted){
        pollRes = poll(&clientPoll,1, TIMEOUT);

        if(pollRes == 0){ // timeout ended
            continue;
        }else if(pollRes > 0){  // check if
            if(clientPoll.revents & POLLIN){ // check bitmask returned events if it was CTRL - C
                sprintf(buffer, "q");
                sendString(connection_fd, buffer);

                break;
            }
        }else{ // if less than 0, poll error
            sprintf(buffer, "q"); // TODO
            sendString(connection_fd, buffer);
            perror("Poll failed client");
            break;
        }

    }


    // RECV
    // Receive the request
    recvString(connection_fd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%lf\n%lu", &result, &iterations);

    // Print the result
    printf("The value for PI is: %.20lf computed with %lu iterations\n", result, iterations);
}

void setUpHandlers(){
    struct sigaction new_action;

    // Prepare structure, block all signals
    new_action.sa_handler = detectInterruption;

    // Clear Flags
    new_action.sa_flags = 0;
    sigfillset(&new_action.sa_mask);

    // Catch signal CTRL-C
    sigaction(SIGINT, &new_action, NULL); // Do i put old action?
}

// Signal handler
void detectInterruption(int signal){
    printf("Detected CTRL-C\n");

    interrupted = 1; // Change global variable, only way to do it =(
}

// Modify the signal mask. Define to block SIGINT
void setupMask(){
    sigset_t mask;

    // Add all signals to block
    sigfillset(&mask);
    sigdelset(&mask, SIGINT); // Dont block SIGINT

    // Apply the set to the program. The program has a "default" set (think of it as a "third set"), and it is now replaced by the new_set
    sigprocmask(SIG_BLOCK,&mask,NULL);
}


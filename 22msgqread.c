#include <stdio.h>  /* printf, etc. */
#include <stdlib.h> /* exit, etc. */
#include <string.h>/* strcpy, strlen, etc. */
#include <time.h>  /* ctime, etc. */
#include <sys/msg.h>/* msgget, msgsnd, msgrcv, MSGMAX, etc. */
#include <sys/types.h> /* Data type 'key_t' for 1st arg of 'msgget' */
#include <sys/ipc.h>/* 'struct ipc_perm' in 'struct msgid_ds' in 'msgctl' */
#include "cp22_msgq1.h"/* User defined header file for message queues */

/* Define all the error messages */
char * error_msg[] = {
    "\nUsage: ./22msgqread1\n\n",
    "\nError while acquiring message queue with 'msgget'\n\n",
    "\nError while receiving message from queue with 'msgsnd'\n\n",
    "\nError while retrieving status of queue with 'msgctl'\n\n"
};

/* Declare the prototype for function 'print_error' */
void print_error(int msg_num, int exit_code);

/* Declare the prototype for function 'print_qstat' */
void print_qstat(int qd, struct msqid_ds * qstat);

int main(int argc, char * argv[])
{
    int i;/* A local counter */
    int qd; /* Queue descriptor */
    struct struct_msg_datagram msg_datagram; 
   /* Holds msg type and msg text */
    struct msqid_ds qstat;/* To retrieve queue status */
    char message[NUM_MSGS][MAX_MSG_LEN];
 /* Messages for the queue */
    int num_bytes_read;       
          /* Actual num of bytes read from msg queue */
 
    /* Check if server is run using correct syntax */
    if ( argc != 1 )
        print_error(0,2);
 
    /* Try to get the queue descriptor */
    if ( ( qd = msgget(MSGQ_KEY, 0) ) == -1 )
        print_error(1,3);
 
    /* Retrieve queue status */
    if ( (msgctl(qd, IPC_STAT, &qstat)) == -1 )
        print_error(3,5);
 
    /* Display the initial status of queue */
    printf("\nMessage queue acquired with ID %d\n\n", qd);
    printf("Initial status of queue is as follows:\n");
    print_qstat(qd, &qstat);
 
    /* Read the messages from the queue */
    for ( i = 0; i < NUM_MSGS; i++ )
    {
        /* Retrieve a message datagram from queue */
        if    (    (num_bytes_read = 
                        msgrcv(qd, &msg_datagram, MAX_MSG_LEN, i+1, IPC_NOWAIT | MSG_NOERROR)
                    ) 
                    == -1
              )
            print_error(2,4);
 
        /* Extract the message from datagram */
        sprintf(message[i],"%s",msg_datagram.mtext);
 
        printf("\nRetrieved from queue %d the message (%d bytes read):\n\t'%s'\n\n",
                    qd, num_bytes_read, message[i]);
 
        /* Retrieve queue status */
        if ( (msgctl(qd, IPC_STAT, &qstat)) == -1 )
            print_error(3,5);

        /* Display the current status of queue */
        printf("Current status of queue is as follows:\n");
        print_qstat(qd, &qstat);
    }
 
    return 0;
}

void print_error(int error_index, int exit_code)
{
    fprintf(stderr, "%s", error_msg[error_index]);
    exit(exit_code);
}


#include <stdio.h>                      /* printf, etc. */
#include <stdlib.h>                     /* exit, etc. */
#include <string.h>                     /* strcpy, strlen, etc. */
#include <time.h>                       /* ctime, etc. */
#include <sys/msg.h>                    /* msgget, msgsnd, msgrcv, MSGMAX, etc. */
#include <sys/types.h>                  /* Data type 'key_t' for 1st arg of 'msgget' */
#include <sys/ipc.h>                    /* 'struct ipc_perm' in 'struct msgid_ds' in 'msgctl' */
#include "cp22_msgq1.h"                    /* User defined header file for message queues */

/* Define all the error messages */
char * error_msg[] = {
                "\nUsage: ./21msgqwrite1\n\n",
                "\nError while creating message queue with 'msgget'\n\n",
                "\nError while sending message to queue with 'msgsnd'\n\n",
                "\nError while retrieving status of queue with 'msgctl'\n\n"
};

/* Declare the prototype for function 'print_error' */
void print_error(int msg_num, int exit_code);

/* Declare the prototype for function 'print_qstat' */
void print_qstat(int qd, struct msqid_ds * qstat);

int main(int argc, char * argv[])
{
        int i;                          /* A local counter */
        int qd;                         /* Queue descriptor */
        struct struct_msg_datagram msg_datagram;    /* Holds msg type and msg text */
        struct msqid_ds qstat;          /* To retrieve queue status */
        char * message[] = {            /* Messages for the queue */
                "Message 1, Linux is powerful",
                "Message 2, These are System V standards of message queues",
                "Message 3, Message queues is just 1 mechanism for IPC",
                "Message 4, Other IPC mechanisms include semaphores",
                "Message 5, Still other mechanism for IPC is shared memory",
                "Message 6, Further more memory mapped I/O also allows IPC"
        };
 
        /* Check if server is run using correct syntax */
        if ( argc != 1 )
                print_error(0,2);
 
        /* Try to get the queue descriptor */
        if ( ( qd = msgget(MSGQ_KEY, IPC_CREAT | 0666) ) == -1 )
                print_error(1,3);
 
        /* Retrieve queue status */
        if ( (msgctl(qd, IPC_STAT, &qstat)) == -1 )
                print_error(3,5);
 
        /* Display the initial status of queue */
        printf("\nMessage queue created with ID %d\n\n", qd);
        printf("Initial status of queue is as follows:\n");
        print_qstat(qd, &qstat);
 
        /* Write down the messages to the queue */
        for ( i = 0; i < NUM_MSGS; i++ )
        {
                /* Prepare the message datagram */
                msg_datagram.mtype = i+1;
                sprintf(msg_datagram.mtext,"%s",message[i]);
 
                printf("\nSending to queue %d the message:\n\t'%s'\n\n", qd, message[i]);
 
                /* Send the message to queue */
                if ( (msgsnd(qd, &msg_datagram, strlen(message[i])+1, BLOCKED)) == -1 )
                        print_error(2,4);
 
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


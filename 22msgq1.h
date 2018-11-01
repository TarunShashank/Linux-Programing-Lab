#define MAX_MSG_LEN 200                 /* Maximum message length */
#define MSGQ_KEY 100                    /* An arbirary key (name) for message queue */
#define BLOCKED 0                       /* Flag value of 0 in 'msgsnd' indicates 'block possible */
#define NUM_MSGS 3                      /* Number of messages in the queue */

struct struct_msg_datagram              /* Structure to hold messages in the queue */
{
        long mtype;                     /* Message type */
        char mtext[MAX_MSG_LEN];        /* Message text */
};

void print_qstat(int qd, struct msqid_ds * qstat)
{
        printf("PID = %d\n", getpid());
        printf("Queue %d Status:\n----------------------\n", (int)qd);
        printf("# of messages in queue = %d\n", (int)qstat->msg_qnum);
        printf("Queue owner's effective user ID = %d\n", (int)qstat->msg_perm.uid);
        printf("Queue owner's effective group ID = %d\n", (int)qstat->msg_perm.gid);
        printf("Queue creator's effective user ID = %d\n", (int)qstat->msg_perm.cuid);
        printf("Queue creator's effective group ID = %d\n", (int)qstat->msg_perm.cgid);
        printf("Permissions = %o\n", (int)qstat->msg_perm.mode);
        printf("Last sender's PID = %d\n", (int)qstat->msg_lspid);
        printf("Last receiver's PID = %d\n", (int)qstat->msg_lrpid);
        printf("Time of last send = %s", ctime(&qstat->msg_stime));
        printf("Time of last receive = %s", ctime(&qstat->msg_rtime));
        printf("Time of last change = %s\n", ctime(&qstat->msg_ctime));
}


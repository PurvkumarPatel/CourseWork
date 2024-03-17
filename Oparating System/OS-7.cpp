#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define BUFFER_SIZE 16

// Code for Producer Consumers Problem
int mutex = 1;
int full = 0;
int empty = 10, data = 0;
int pip = 0;

void producer()
{
    --mutex;
    ++full;
    --empty;
    data++;
    printf("\nProducer produces item number: %d\n", data);
    ++mutex;
}

// A function that will resemble the consumer's consumption of data
void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item number: %d.\n", data);
    data--;
    ++mutex;
}

void ProdCons()
{
    int n, i, flag = 0;
    printf("1.Producer to produce item"
           "\n2.Consumer to consume item"
           "\n3.Exit");

    for (i = 1; i > 0; i++)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch(n)
        {
        case 1:
            /*
            If the value of mutex is 1 and the buffer is not full, then we can produce the data
            */
            if ((mutex == 1) && (empty != 0))
            {
                producer();
            }
            // else, the buffer must be full.
            else
            {
                printf("The Buffer is full. New data cannot be produced!");
            }
            break;
        case 2:
            /*
            If the value of mutex is 1 and the buffer is not empty, then we can consume the data
            */
            if ((mutex == 1) && (full != 0))
            {
                consumer();
            }
            else
            {
                flag = 1;
                printf("The Buffer is empty! New data cannot be consumed!");
            }
            break;
        case 3:
            goto exit;
            break;
        }
        if (flag == 1)
        {

        exit:
            printf("\n");
            break;
        }
    }
}

// Code for ReaderWriters Problem
sem_t x, y;
pthread_t tid;
pthread_t writerthreads[100], readerthreads[100];
int readercount;

void *reader(void *param)
{
    sem_wait(&x);
    readercount++;
    if (readercount == 1)
        sem_wait(&y);
    sem_post(&x);
    printf("\n%d Reader is inside", readercount);
    sem_wait(&x);
    readercount--;
    if (readercount == 0)
    {
        sem_post(&y);
    }
    sem_post(&x);
    printf("\n%d Reader is leaving", readercount + 1);
}

void *writer(void *param)
{
    printf("\nWriter is trying to enter");
    sem_wait(&y);
    printf("\nWriter has entered");
    sem_post(&y);
    printf("\nWriter is leaving");
}

void ReadWrite()
{
    int n2, i;
    printf("Enter the number of readers:");
    scanf("%d", &n2);
    int n1[n2];
    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);
    for (i = 0; i < n2; i++)
    {
        pthread_create(&writerthreads[i], NULL, reader, NULL);
        pthread_create(&readerthreads[i], NULL, writer, NULL);
    }
    for (i = 0; i < n2; i++)
    {
        pthread_join(writerthreads[i], NULL);
        pthread_join(readerthreads[i], NULL);
    }
}

//Code for printer spooler problem
int buffer[BUFFER_SIZE],spool[BUFFER_SIZE];
sem_t db,m,full1,empty1,mutex1,ps;

int counter, readerCount, writercount;
pthread_t readerThread[50],writerThread[50],producerThread[50], 
consumerThread[50],fileThread[50];

void init()
{
    sem_init(&m,0,1);
    sem_init(&db,0,1);
    counter=0;
    readerCount=0;
    writercount=0;
    sem_init(&mutex1,0,1);
    sem_init(&full1,1,0);
    sem_init(&empty1,1,BUFFER_SIZE);
    counter=0;
    sem_init(&ps,0,1);
}
void *spooler(void *param)
{
    int data,regi;
    sem_wait(&ps);
    regi = counter;
    data = counter;
    spool[counter]=data;
    regi++;
    printf("Spooler State: ");
    for(int i=regi-1;i<regi;i++)
    printf("File %d ",spool[i]);
    printf("\n");
    printf("Printer State: File %d \t", spool[regi-1]);
    printf("\n");
    sleep(1);
    counter=regi;
    sem_post(&ps);
}
void printer_spooler()
    {
    int i,number_of_files;
    init();
    printf("Enter number of Files: ");
    scanf("%d",&number_of_files);
    for(i=0;i<number_of_files;i++)
    {
    pthread_create(&fileThread[i],NULL,spooler,NULL);
    }
    for(i=0;i<number_of_files;i++)
    {
    pthread_join(fileThread[i],NULL);
    }
}

int main()
{

    while (1)
    {
        int n;
        printf("---------------------------------------------\n");
        printf("1 --> Reader Writer's Problem  \n");
        printf("2 --> Producer Consumer's Problem  \n");
        printf("3 --> Printer Spooler's Problem \n");
        printf("4 --> Exit  \n");
        printf("--> Enter choice here :-> ");
        scanf("%d", &n);
        printf("\n");
        switch (n)
        {
        case 1:
            ReadWrite();
            printf("\n");
            break;
        case 2:
            ProdCons();
            break;
        case 3:
            printer_spooler();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Enter valid Number: ");
            break;
        }
    }
    return 0;
}
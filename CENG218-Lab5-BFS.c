#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Breadth First Search using an adjacency matrix

int visited[20],q[20];
int front = -1, rear =-1;
int a[6][6] = {{0,1,1,1,0,0},{1,0,0,0,1,1},{1,0,0,0,0,1},{1,0,0,0,0,0},
                {0,1,0,0,0,0},{0,1,1,0,0,0}};
int counter = 0;

void printLetter(int num){
    switch (num) {
        case 0:
            printf("A->");
            break;
        case 1:
            printf("B->");
            break;
        case 2:
            printf("C->");
            break;
        case 3:
            printf("D->");
            break;
        case 4:
            printf("E->");
            break;
        case 5:
            printf("F->");
            break;

    }
}

void bfs(int vertices)
{
       int i;
       for (i=0;i<6;i++)
       {
               if(a[vertices][i] != 0 && visited[i] == 0) // If its not empty and not visited 
              {                                           // It will add to queue 
                    rear=rear+1;                       //And will mark it as visited
                    q[rear]=i;                         //It will print the letter as it has been visited
                    visited[i]=1;                  
                    counter++;
                    printLetter(i);
              }
      }
      front=front+1;
      if(front<=rear)           //It will continue to look at the matrix recursively 
            bfs(q[front]);      //Until front of the queue reaches to rear
}

void markNotVisited() {
    for (int i= 0; i<3; i++)                   // mark all the vertices as 0 (not visited)
    {
        visited[i]=0;
    }
}
void printMatrix() {            //Prints the matrix
    printf("\n Matrix\n");
    for (int i=0;i<6;i++) {
      for (int j=0;j<6;j++)
        printf("%d ", a[i][j]);
       printf("\n");
    }
}
int main()
{
    struct timeval stop, starttime;
    gettimeofday(&starttime,NULL);  //To count the running time of the program
    int start = 0;
    markNotVisited();   //Marks non visited ones as zero
    printMatrix();      //print the matrix
    front=0;
    rear=0;
    q[rear]=start;
    printf("\nBFS\n");
    visited[start]=1;   //Mark the first one as visited
    printLetter(0);     //Write the first letter
    bfs(start);
    sleep(1);
    gettimeofday(&stop,NULL);
    printf ("\nTotal time = %f seconds\n",(double) (stop.tv_usec - starttime.tv_usec) / 1000000 + (double) (stop.tv_sec - starttime.tv_sec) - 1);	 //second
    printf("Time milliseconds = %lu\n", ((stop.tv_sec - starttime.tv_sec) * 1000000 + stop.tv_usec - starttime.tv_usec) - 1000000);			//millisecond
    printf("Time nanoseconds = %lu\n", (((stop.tv_sec - starttime.tv_sec) * 1000000 + stop.tv_usec - starttime.tv_usec) - 1000000)* 1000);	//microsecond
    return 0;
}

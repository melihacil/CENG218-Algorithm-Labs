#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//Lab 6 Insertion sort


int changes = 0; //To calculate how many changes done while sorting
int c1,c2,c3;    //To hold how many changes done for each array

        /*                  Insertion Sort
        Chooses the first element in the loop and then checks the 
        rest of the array if there is a smaller value than it. 
        After it found the smallest element then it changes it with 
        the first element in the array. This loop continues until the 
        array size has been reached                                 */

void insertionSort (int array[], int size) {
    int key,j;
    for (int i = 0; i < size; i++) {        //Chooses a key and
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            changes++;
            array[j+1] = array[j];
            j--;
            printf("%d changed to %d  Array ", array[j+1],array[j]); //Prints the change step by step
            printArrforloop(array,size);                             //Print Array
        }
        array[j+1] = key;
    }
}

void printArrforloop(int arr[],int size) { //Iteratively prints array
    for (int i = 0;i< size;i++)
        printf("%d - ",arr[i]);
    printf("\n");
}
void printArr(int array[], int arrSize, int n) { //Recursively prints array
    if (n == arrSize) {
        printf("\n");
        return;
    }
    printf("%d - ", array[n]);
    printArr(array, arrSize,n+1);
}

int array[] = {1,2,3,4,5,6,7,8,9,10};
int array2[] = {10,9,8,7,6,5,4,3,2,1};
int array3[] = {3,7,5,10,1,9,6,2,8,4};
int main()
{
    //Used to calculate time 
    //Other than gettimeofday clock can be used
    struct timeval stop, start,stop2,start2,stop3,start3;

    int arraySize = sizeof(array) / sizeof(array[0]);

    printArr(array,arraySize,0);    //Printing unsorted array
    gettimeofday(&start,NULL);
    insertionSort(array,arraySize); 
    printf("\n%d changes for the first arr\n", changes);
    c1 = changes;
    changes = 0;
    //sleep(1);  can be used to add more time to calculate running time
    gettimeofday(&stop,NULL);

    gettimeofday(&start2,NULL);
    insertionSort(array2,arraySize);
    printf("\n%d changes for the second arr =", changes);
    printf("\nthird array \n ");
    printArrforloop(array2,arraySize);
    c2 = changes;
    changes = 0;
    //sleep(1);  can be used to add more time to calculate running time
    gettimeofday(&stop2,NULL);
       gettimeofday(&start3,NULL);
    insertionSort(array3,arraySize);
    printf("\n%d changes for the third array\n", changes);
    //sleep(1);  can be used to add more time to calculate running time
    gettimeofday(&stop3,NULL);
    c3 = changes;

    //first array running time
    printf("\n\nFirst array changes = %d\n",c1);
    printf ("Total time = %f seconds\n",(double) (stop.tv_usec - start.tv_usec) / 1000000 + (double) (stop.tv_sec - start.tv_sec) - 1);	 //second
    printf("Time milliseconds = %lu\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) - 1000000);			//millisecond
    printf("Time nanoseconds = %lu\n", (((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec) - 1000000)* 1000);	//microsecond
    //second arr running time
    printf("\n\nSecond array changes = %d\n",c2);
    printf ("Total time = %f seconds\n",(double) (stop2.tv_usec - start2.tv_usec) / 1000000 + (double) (stop2.tv_sec - start2.tv_sec) - 1);	 //second
    printf("Time milliseconds = %lu\n", ((stop2.tv_sec - start2.tv_sec) * 1000000 + stop2.tv_usec - start2.tv_usec) - 1000000);			//millisecond
    printf("Time nanoseconds = %lu\n", (((stop2.tv_sec - start2.tv_sec) * 1000000 + stop2.tv_usec - start2.tv_usec) - 1000000)* 1000);	//microsecond
    //third arr running time
    printf("\n\nThird array changes = %d\n",c3);
    printf ("Total time = %f seconds\n",(double) (stop3.tv_usec - start3.tv_usec) / 1000000 + (double) (stop3.tv_sec - start3.tv_sec) - 1);	 //second
    printf("Time milliseconds = %lu\n", ((stop3.tv_sec - start3.tv_sec) * 1000000 + stop3.tv_usec - start3.tv_usec) - 1000000);			//millisecond
    printf("Time nanoseconds = %lu\n", (((stop3.tv_sec - start3.tv_sec) * 1000000 + stop3.tv_usec - start3.tv_usec) - 1000000)* 1000);	//microsecond
    return 0;
}

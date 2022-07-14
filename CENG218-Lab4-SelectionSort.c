#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>
#include <unistd.h>

//Melih Acil 201180077
//Algorithms Lab-4

void swap(int *x, int *y)   //Swapping function for array elements
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray (int n, int array[],int size) { //Prints the array recursively
    if (n == size) {
        printf("\n");
        return;

    }
    printf("%d ", array[n]);
    printArray(n+1,array,size);
}


void selectionSort(int arr[], int size) {       //Selection sort iterative
    int minindex;
    for (int i =0 ; i < size - 1; i++) {        //Finds minimum index 
        minindex = i;
        for (int j = i+1 ; j < size; j++)
            if (arr[minindex] > arr[j])
                minindex = j;                   //Set minindex as j 
        swap (&arr[minindex],&arr[i]);          //Swap minimum index 
        printf("%d changed to %d  ", arr[minindex], arr[i]);
        printArray(0,arr,size);

    }
}


int sSortRecPart2 (int arr[],int size, int minIndex,int j) {    //Sort's second recursive loop
    if (j == size)
        return minIndex;
    if (arr[minIndex] > arr[j])
        minIndex = j;
    return sSortRecPart2(arr,size,minIndex,j+1);

}

void sSortRec1(int arr[], int size,int i) { //First recursive loop
    int minIndex = i;
    if (minIndex == size)                   //If size equals to i then stop recursion
        return;
    minIndex = sSortRecPart2(arr,size,minIndex,i+1);    //Get the minimum element's index
    swap (&arr[minIndex],&arr[i]);                      //And swap with the i 
    printf("%d changed to %d  ", arr[minIndex], arr[i]);//Prints the change
    printArray(0,arr,size);
    sSortRec1(arr,size,i+1);                            //Recursively continue until loops end
}


int main()
{

    int array[20];
    int i;

    srand(time(NULL));
    int size = sizeof(array) / sizeof(array[0]); //To find the arrays size 


    for( i = 0 ; i < size ; i++ )       //Asssign random elements to array between 1 - 100
        array[i] = rand() % 100 + 1;


    struct timeval stop, start,start2,stop2;
    gettimeofday(&start,NULL);
    printf("Non sorted iterative array\n");
    printArray(0,array,size);

    printf("Steps\n");
    selectionSort(array,size);
    printArray(0,array,size);
    gettimeofday(&stop,NULL);
    printf("Iterative selection sort time\n");


    printf ("Total time = %f seconds\n",(double) (stop.tv_usec - start.tv_usec) / 1000000 + (double) (stop.tv_sec - start.tv_sec) );	 //second
    printf("Time milliseconds = %lu\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));			//millisecond
    printf("Time nanoseconds = %lu\n", (((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec))* 1000);	//microsecond


    int array2[20];

    int arr2size = sizeof(array2)/sizeof(array2[0]);    //Second array with iterative 
    for (int j = 0; j < arr2size;j++) {
        array2[j] = rand() % 100 + 1;
    }

    gettimeofday(&start2,NULL);
    printf("Non sorted recursive array\n");
    printArray(0,array2,size);
    printf("Steps\n");

    sSortRec1(array2,arr2size,0);

    printf("Sorted array\n");

    printArray(0,array2,arr2size);

    gettimeofday(&stop2,NULL);
    printf("Recursive selection sort time\n");
    printf ("Total time = %f seconds\n",(double) (stop2.tv_usec - start2.tv_usec) / 1000000 + (double) (stop2.tv_sec - start2.tv_sec) );	 //second
    printf("Time milliseconds = %lu\n", ((stop2.tv_sec - start2.tv_sec) * 1000000 + stop2.tv_usec - start2.tv_usec));			//millisecond
    printf("Time nanoseconds = %lu\n", (((stop2.tv_sec - start2.tv_sec) * 1000000 + stop2.tv_usec - start2.tv_usec))* 1000);	//microsecond

    return 0;
}




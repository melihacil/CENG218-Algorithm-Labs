#include <stdio.h>
#include <stdlib.h>
//Melih Acil 201180077


int arrControl[];
void mergeSort1(int arr[],int left, int right) {
    if (left < right) {
        int ort = left + (right - left) / 2; //(left+right)/2

        mergeSort1(arr,left,ort);   //First part of the merge sort
        mergeSort1(arr,ort+1,right);//Recursively continue

        mergeSort2(arr,left,ort,right);//Merging the array
    }
}
void controlFunc(int arr[], int size) {
    for (int j = 0; j< size; j++) {
        int kucuk = 0;
        printf("%d 'den kucuk : ", arr[j]);
        for (int i = j;i < size;i++) {
            if (arr[j] > arr[i]) {
                printf("%d ", arr[i]);
                kucuk++;
            }
        }
        printf("\n");
        arrControl[j] = kucuk;
    }
}
void mergeSort2(int arr[], int left, int mid, int right)
{
    int i, j;
    int leftArraySize = mid - left + 1;
    int rightArraySize = right - mid;

    int lArray[leftArraySize], rArray[rightArraySize];

    //Divide the array to left and right parts
    for (i = 0; i < leftArraySize; i++)
        lArray[i] = arr[left + i];
    for (j = 0; j < rightArraySize; j++)
        rArray[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    //Merge parts while comparing
    while (i < leftArraySize && j < rightArraySize) {
        if (lArray[i] <= rArray[j]) {
            arr[left] = lArray[i];
            i++;
        }
        else {
            arr[left] = rArray[j];
            j++;
        }
        left++;
    }
    while (i < leftArraySize || j < rightArraySize) {   //Add if there is anything left in left or right arrays
            if (i < leftArraySize) {
                arr[left] = lArray[i];
                i++;
                left++;
            }
            else {
                arr[left] = rArray[j];
                j++;
                left++;
            }
    }
}


void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void printArrayRecursive(int arr[], int size, int i) {
    if (i == size)
        return;
    printf("%d ", arr[i]);
    printArrayRecursive(arr,size,i+1);
}

int arr2[] = {8,5,9,4,2,7};

int main()
{

    printf("Array: ");

    //mergeSort1(arr, 0, arrSize - 1);
    int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);
    printArray(arr2, arrSize2);
    printf("\n");
    controlFunc(arr2,arrSize2);
    printf("Control array: ");
    printArray(arrControl,arrSize2);
    int a = 6;
    //int arrControlSize = sizeof(arrControl) / sizeof(a);  Can be used
    mergeSort1(arrControl,0,a-1);
    printf("Sorted array: ");
    printArray(arrControl,arrSize2);
    return 0;

}


#include <stdio.h>
#include <stdlib.h>

#define MAX 7


int hashTablee[MAX];
int j=0;


int hashFunc (int k) {
    return k % MAX;
}

void insertQuadratic(int key ) {
    int index = hashFunc(key);
    int temp = index;
    for (int i = 0; i < MAX;i++) {
        temp = (index + i * i) % MAX;
        if (hashTablee[temp] != -1) {
            continue;
        }
        hashTablee[temp] = key;
        break;
    }


}


void makeNegative() {
    for (int i = 0; i< MAX; i++) {
        hashTablee[i] = -1;
    }
}
int arr[6] = {701,145,217,19,13,749};
void printHashtable() {
    printf("\n\nHash Table--Key\n");
    printf("\n%d ekleniyor\n",arr[j]);
    for(int i=0; i < MAX;i++) {

        if (hashTablee[i] == -1) {
            printf("%d -----Empty\n", i);
            continue;
        }
        printf("%d -----%d\n",i, hashTablee[i]);
    }
    j++;


}



int main()
{
    printf("Dizi Elemanlari : {701,145,217,19,13,749}\n");
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    makeNegative();
    for (int i = 0;i < arrSize;i++) {
        insertQuadratic(arr[i]);
        printHashtable();
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct hashTable {
    int key;
    int value;
};


struct hashTable *table;
struct hashTable *dummyItem;
struct hashTable *table1[MAX];

int hashFunc (int k) {
    return k % MAX;
}
void insertQuadratic(int key, int value) { //Quadratic probing
    struct hashTable *item = (struct hashTable*) malloc(sizeof (struct hashTable));
    item->key = key;
    item->value = value;
    int index = hashFunc(key);
    int temp = index;
    for (int i = 0; i < MAX;i++) {
        temp = (index + i * i) % MAX;
        if (table1[temp] != NULL) {
            continue;
        }
        table1[temp] = item;
        break;
    }
}

void delete (int key) {
    int index = hashFunc(key);
    table1[index] = dummyItem;
}

void deleteLP (int key, int value) {
    int index = hashFunc(key);
    while(table1[index] != NULL) {
      if(table1[index]->value == value) {
         //assign a dummy item at deleted position
         table1[index] = dummyItem;
         break;
      }
      //go to next cell
      ++index;
      //wrap around the table
      index %= MAX;
   }
}




void printHashtable() {
    printf("Hash Table--(Key-Value)\n");
    for(int i=0; i < MAX;i++) {
        if (table1[i] == NULL) {
            printf("%d -----Empty\n", i);
            continue;
        }
        printf("%d -----(%d-%d)\n",i, table1[i]->key,table1[i]->value);
    }


}
int main()
{
    printf("Hello world!\n");
    insertQuadratic(10,102);
    insertQuadratic(20,31);
    insertQuadratic(40,404);
    //insert(13,42);
    printHashtable();
    //delete(1);
    deleteLP(10,102);
        printHashtable();
    return 0;
}


/*
void insertDoublehash (int key) {
    int index = hashFunc(key);
    int temp = index;
    for (int i = 0; i < MAX ; i++) {
        temp = (index + i * hashFunc2(key)) % MAX;
        if (hashTablee[temp] != -1)
            continue;
        hashTablee[temp] = key;
        break;
    }
}
*/

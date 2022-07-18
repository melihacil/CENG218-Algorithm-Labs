 //Hash table normal struct linear probing
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
void insert (int key, int value) {
    struct hashTable *item = (struct hashTable*) malloc(sizeof (struct hashTable));
    item->key = key;
    item->value = value;
    int index = hashFunc(key);

    while(table1[index] != NULL && table1[index]->key != -1) { //linear probing
      //go to next cell
      ++index;

      //wrap around the table
      index %= MAX;
   }

    table1[index] = item;
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
    insert(1,102);
    insert(11,31);
    insert(13,42);
    insert(21,2323);
    printHashtable();
    //delete(1);
    deleteLP(1,102);
        printHashtable();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct item {
    int key;
    int data;
    struct item *next;
};

struct item *head = NULL;

int main()
{
    extern void insert(int key, int data), delete(int key), printall();
    extern int search(int key);

    insert(38, 3);
    insert(20, 2);
    insert(5, 0);
    insert(22, 6);
    insert(46, 18);

    printf("With all five items:\n");
    printall();

/*

    printf("After delete(22):\n");
    delete(22);
    printall();
    printf("After delete(5):\n");
    delete(5);
    printall();
    printf("delete(30) shouldn't do anything:\n");
    delete(30);
    printall();

*/

    return(0);
}


void insert(int key, int data)
{
    struct item *curItem, *newItem, *prev;
    if ((new = malloc(sizeof(struct item))) == NULL) {
        fprintf(stderr, "no memory\n");  
        exit(1);
    }
    newItem.key = key;
    newItem.data = data;
    // If the head has nothing
    if (head == NULL){
        head.data = data;
        head.key = key;
        head.next = NULL;
        return;
    }

    // Head has an item, start looping thru the linked list
    while (curItem->key < key && curItem->next){
        prev = &curItem;
        curItem = curItem->next;
    }

    // goes to head of list
    if (prev == NULL){
        new.next = &head;
        head = new
    } else {
        prev.next = new;
        new.next = curItem;
    }
}


void delete(int key)
{
}


int search(int key) /* returns -1 if not found */
{
    struct item *p;

    for (p = head; p && p->key < key; p = p->next)
        ;
    if (p && p->key == key)
        return(p->data);
    else
        return(-1);
}


void printall()
{
    struct item *p;
    for (p = head; p; p = p->next)
        printf("%d: %d\n", p->key, p->data);
    printf("[end]\n");
}

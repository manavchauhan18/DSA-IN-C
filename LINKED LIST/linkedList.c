#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
}*stNode;

void createLinkedList(int n);
void displayList();
void insertInTheBeginning(int item);
void insertAtThePosition(int loc, int item);
void insertAtEnd(int item);
void deleteAtGivenPosition(int loc);
void reverseList();

int main() {
    int n, num, loc;
    printf("Input the number of nodes: ");
    scanf("%d", &n);
    createLinkedList(n);
    printf("Displaying the List: \n");
    displayList();
    printf("\n-------------------------------------------\n\n");
    insertAtTheBeginning(num);
    displayList();
    printf("\n-------------------------------------------\n\n");
    insertAtEnd(num);
    displayList();
    printf("\n-------------------------------------------\n\n");
    insertAtThePosition(loc, num);
    displayList();
    deleteAtGivenPosition(loc);
    displayList();
    printf("\n-------------------------------------------\n\n");
    reverseList();
    displayList();
    return 0;
}

void createLinkedList(int n) {
    struct node *fnNode, *tmp;
    int num;

    stNode = (struct node *)malloc(sizeof(struct node));
    if (stNode == NULL) {
        printf("Memory cannot be allocated.");
    } else {
        printf("Node 1: ");
        scanf("%d", &num);

        stNode -> data = num;
        stNode -> next = NULL;
        tmp = stNode;

        for(int i = 2; i <= n; i++) {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL) {
                printf("Memory cannot be allocated.");
            } else {
                printf("Node %d: ", i);
                scanf("%d", &num);

                fnNode -> data = num;
                fnNode -> next = NULL;

                tmp -> next = fnNode;
                tmp = tmp -> next;
            }
        }
    }
}

void insertAtTheBeginning(int num) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Node to be inserted at the beginning: \n");
    scanf("%d", &num);
    ptr -> data = num;
    ptr -> next = stNode;
    stNode = ptr;
}

void insertAtEnd(int num) {
    struct node *ptr, *tmp;
    tmp = stNode;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Node to be inserted at the End: \n");
    scanf("%d", &num);
    ptr -> data = num;
    ptr -> next = NULL;
    while(tmp -> next != NULL) {
        tmp = tmp -> next;
    }
    tmp -> next = ptr;
}

void insertAtThePosition(int loc, int num) {
    struct node *tmp, *ptr;
    tmp = stNode;
    printf("Enter the Node to be inserted at the given Location: \n");
    scanf("%d", &num);
    ptr -> data = num;
    ptr -> next = NULL;
    printf("Enter  the location: ");
    scanf("%d", &loc);
    for(int i = 0; i < loc-2; i++) {
        tmp = tmp -> next;
    }
    ptr -> next = tmp -> next;
    tmp -> next = ptr;
}

void deleteAtGivenPosition(int loc) {
    printf("Enter the position to delete the node: ");
    scanf("%d", &loc);
    struct node *tmp, *tmp1;
    tmp = stNode;
    for(int i = 0; i < loc - 2; i++) {
        tmp = tmp -> next;
    }
    tmp1 = tmp -> next;
    tmp -> next = tmp1 -> next;
}

void reverseList() {
    struct node *current, *next, *prev;
    current = stNode;
    prev = NULL;
    while(current != NULL) {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    stNode = prev;
}

void displayList() {
    struct node *tmp;
    tmp = stNode;
    while (tmp != NULL) {
        printf("Data = %d\n", tmp -> data);
        tmp = tmp -> next;
    }
    
}
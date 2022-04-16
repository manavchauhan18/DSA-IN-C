#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
}*stNode;

void createLinkedList(int n);
void displayList();

int main() {
    int n;
    printf("Input the number of nodes: ");
    scanf("%d", &n);
    createLinkedList(n);
    printf("Displaying the List: ");
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

void displayList() {
    struct node *tmp;
    tmp = stNode;
    while (tmp != NULL) {
        printf("Data = %d\n", tmp -> data);
        tmp = tmp -> next;
    }
    
}
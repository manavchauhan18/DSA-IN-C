#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node *stNode;

void createDoublyLinkedList(int n);
void displayList();

void createDoublyLinkedList(int n) {
    int num;
    struct node *fnNode, *tmp;
    stNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for node 1: ");
    scanf("%d", &num);
    stNode -> data = num;
    stNode -> next = NULL;
    stNode -> prev = NULL;
    tmp = stNode;
    for(int i = 2; i <= n; i++) {
        printf("Enter the data for node %d: ", i);
        scanf("%d", &num);
        fnNode -> data = num;
        fnNode -> prev = stNode;
        fnNode -> next = NULL;

        tmp -> next = fnNode;
        tmp = fnNode;
    }
}

void displayList() {
    struct node *tmp;
    tmp = stNode;
    while(tmp != NULL) {
        printf("Node: %d", tmp -> data);
        tmp = tmp -> next;
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createDoublyLinkedList(n);
    displayList();
}

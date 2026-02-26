 
#include <stdio.h>  
#include <stdlib.h>  
 
typedef struct Node {  
    int data;  
    struct Node* next;  
    struct Node* prev;  
} Node; 
 
Node* createNode(int data) {  
    Node* newNode = (Node*)malloc(sizeof(Node));  
    newNode->data = data;  
    newNode->next = NULL;  
    newNode->prev = NULL;  
    return newNode;  
} 
 
void insertAtBeginning(Node** head, int data) {  
    Node* newNode = createNode(data);  
    if (*head == NULL) {  
        *head = newNode;  
        return; 
    } 
    newNode->next = *head;  
    (*head)->prev = newNode;  
    *head = newNode;  
} 
 
void insertAtEnd(Node** head, int data) {  
    Node* newNode = createNode(data);  
    if (*head == NULL) {  
        *head = newNode;  
        return; 

    } 
    Node* temp = *head;  
    while (temp ->next != NULL) {  
        temp = temp ->next; 
    } 
    temp->next = newNode;  
    newNode->prev = temp;  
} 
 
void insertAtPosition(Node** head, int data, int position) {  
    if (position < 1) {  
        printf("Position should be >= 1. \n"); 
        return; 
    } 
    if (position == 1) {  
        insertAtBeginning(head, data);  
        return; 
    } 
    Node* newNode = createNode(data);  
    Node* temp = *head;  
    for (int i = 1; temp != NULL && i < position - 1; i++) {  
        temp = temp ->next; 
    } 
    if (temp == NULL) {  
        printf("Position greater than the number of nodes. \n"); 
        return; 
    } 
    newNode->next = temp ->next; 
    newNode->prev = temp;  
    if (temp ->next != NULL) {  
        temp->next->prev = newNode;  
    } 
    temp->next = newNode;  
} 
 

void deleteAtBeginning(Node** head) {  
    if (*head == NULL) {  
        printf("The list is already empty. \n"); 
        return; 
    } 
    Node* temp = *head;  
    *head = (*head) ->next; 
    if (*head != NULL) {  
        (*head)->prev = NULL;  
    } 
    free(temp);  
} 
 
void deleteAtEnd(Node** head) {  
    if (*head == NULL) {  
        printf("The list is already empty. \n"); 
        return; 
    } 
    Node* temp = *head;  
    if (temp ->next == NULL) {  
        *head = NULL;  
        free(temp);  
        return; 
    } 
    while (temp ->next != NULL) {  
        temp = temp ->next; 
    } 
    temp->prev->next = NULL;  
    free(temp);  
} 
 
void deleteAtPosition(Node** head, int position) {  
    if (*head == NULL) {  
        printf("The list is already empty. \n"); 
        return; 

    } 
    Node* temp = *head;  
    if (position == 1) {  
        deleteAtBeginning(head);  
        return; 
    } 
    for (int i = 1; temp != NULL && i < position; i++) {  
        temp = temp ->next; 
    } 
    if (temp == NULL) {  
        printf("Position is greater than the number of nodes. \n"); 
        return; 
    } 
    if (temp ->next != NULL) {  
        temp->next->prev = temp ->prev; 
    } 
    if (temp ->prev != NULL) {  
        temp->prev->next = temp ->next; 
    } 
    free(temp);  
} 
 
void printListForward(Node* head) {  
    Node* temp = head;  
    printf("Forward List: ");  
    while (temp != NULL) {  
        printf("%d ", temp ->data); 
        temp = temp ->next; 
    } 
    printf(" \n"); 
} 
 
void printListReverse(Node* head) {  
    Node* temp = head;  
    if (temp == NULL) {  

        printf("The list is empty. \n"); 
        return; 
    } 
    while (temp ->next != NULL) {  
        temp = temp ->next; 
    } 
    printf("Reverse List: ");  
    while (temp != NULL) {  
        printf("%d ", temp ->data); 
        temp = temp ->prev; 
    } 
    printf(" \n"); 
} 
 
int main() {  
    Node* head = NULL;  
    int choice, data, position;  
 
    while (1) {  
        printf(" \n1. Insert at Beginning \n2. Insert at End \n3. Insert 
at Position \n4. Delete at Beginning \n5. Delete at End \n6. Delete at 
Position \n7. Print Forward \n8. Print Reverse \n9. Exit \n"); 
        printf("Enter your choice: ");  
        scanf("%d", &choice);  
 
        switch (choice) {  
            case 1: printf("Enter data: "); scanf("%d", &data); 
insertAtBeginning(&head, data); break;  
            case 2: printf("Enter data: "); scanf("%d", &data); 
insertAtEnd(&head, data); break;  
            case 3: printf("Enter data: "); scanf("%d", &data); 
printf("Enter position: "); scanf("%d", &position); 
insertAtPosition(&head, data, position); break;  
            case 4: deleteAtBeginning(&head); break;  
            case 5: deleteAtEnd(&head); break;  

            case 6: printf("Enter position: "); scanf("%d", 
&position); deleteAtPosition(&head, position); break;  
            case 7: printListForward(head); break;  
            case 8: printListReverse(head); break;  
            case 9: exit(0);  
            default: printf("Invalid choice. \n"); 
        } 
    } 
    return 0;  
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insertAtFirst(struct Node** h, int d) {
    struct Node* n = createNode(d);
    n->next = *h;
    *h = n;
}

void insertAtEnd(struct Node** h, int d) {
    struct Node* n = createNode(d);
    if (!*h) {
        *h = n;
        return;
    }
    struct Node* t = *h;
    while (t->next) t = t->next;
    t->next = n;
}

void insertAtPosition(struct Node** h, int d, int p) {
    if (p == 0) {
        insertAtFirst(h, d);
        return;
    }
    struct Node* t = *h;
    for (int i = 0; t && i < p - 1; i++) t = t->next;
    
    if (!t) {
        printf("Position out of bounds\n");
        return;
    }
    struct Node* n = createNode(d);
    n->next = t->next;
    t->next = n;
}

void deleteFromFirst(struct Node** h) {
    if (!*h) {
        printf("List is empty\n");
        return;
    }
    struct Node* t = *h;
    *h = t->next;
    free(t);
}

void deleteFromEnd(struct Node** h) {
    if (!*h) {
        printf("List is empty\n");
        return;
    }
    struct Node* t = *h;
    if (!t->next) {
        free(t);
        *h = NULL;
        return;
    }
    while (t->next->next) t = t->next;
    free(t->next);
    t->next = NULL;
}

void deleteAtPosition(struct Node** h, int p) {
    if (!*h) {
        printf("List is empty\n");
        return;
    }
    if (p == 0) {
        deleteFromFirst(h);
        return;
    }
    struct Node* t = *h;
    for (int i = 0; t && i < p - 1; i++) t = t->next;
    
    if (!t || !t->next) {
        printf("Position out of bounds\n");
        return;
    }
    struct Node* target = t->next;
    t->next = target->next;
    free(target);
}

void print(struct Node* h) {
    while (h) {
        printf("%d -> ", h->data);
        h = h->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n1.Insert First 2.Insert End 3.Insert Pos 4.Delete First\n");
        printf("5.Delete End 6.Delete Pos 7.Print 8.Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Data: "); scanf("%d", &data);
                insertAtFirst(&head, data);
                break;
            case 2:
                printf("Data: "); scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Data: "); scanf("%d", &data);
                printf("Pos: "); scanf("%d", &pos);
                insertAtPosition(&head, data, pos);
                break;
            case 4:
                deleteFromFirst(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Pos: "); scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 7:
                print(head);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

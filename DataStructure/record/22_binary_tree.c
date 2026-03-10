#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Increased MAX for safety
#define max(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode *root = NULL;

struct TreeNode *create(int val) {
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!node) return NULL;
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Level-order insertion to keep the tree complete
void insert(int val) {
    if (!root) {
        root = create(val);
        return;
    }
    struct TreeNode *q[MAX], *temp;
    int front = 0, rear = 0;
    q[rear++] = root;
    while (front < rear) {
        temp = q[front++];
        if (!temp->left) {
            temp->left = create(val);
            return;
        } else q[rear++] = temp->left;
        
        if (!temp->right) {
            temp->right = create(val);
            return;
        } else q[rear++] = temp->right;
    }
}

// Deletes a node by replacing it with the deepest, rightmost node
void deleteNode(int key) {
    if (!root) return;
    if (!root->left && !root->right) {
        if (root->val == key) {
            free(root);
            root = NULL;
        }
        return;
    }

    struct TreeNode *q[MAX], *temp = NULL, *key_node = NULL, *last_parent = NULL;
    int front = 0, rear = 0;
    q[rear++] = root;

    // BFS to find the node to delete and the deepest node (temp)
    while (front < rear) {
        temp = q[front++];
        if (temp->val == key) key_node = temp;
        if (temp->left) {
            last_parent = temp; 
            q[rear++] = temp->left;
        }
        if (temp->right) {
            last_parent = temp; 
            q[rear++] = temp->right;
        }
    }

    if (key_node) {
        int x = temp->val; // Value of deepest node
        // Manually delete deepest node to avoid re-traversing
        if (last_parent->right == temp) last_parent->right = NULL;
        else last_parent->left = NULL;
        
        key_node->val = x; // Replace target with deepest value
        free(temp);
    }
}

void inorder(struct TreeNode *node) {
    if (!node) return;
    inorder(node->left);
    printf("%d ", node->val);
    inorder(node->right);
}

void preorder(struct TreeNode *node) {
    if (!node) return;
    printf("%d ", node->val);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct TreeNode *node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->val);
}

int height(struct TreeNode *node) {
    if (!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int main() {
    int ch, val;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Inorder 4.Preorder 5.Postorder 6.Height 7.Exit\n");
        printf("Choice: ");
        if (scanf("%d", &ch) != 1) break;

        switch (ch) {
            case 1: printf("Val: "); scanf("%d", &val); insert(val); break;
            case 2: printf("Val: "); scanf("%d", &val); deleteNode(val); break;
            case 3: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 4: printf("Preorder: "); preorder(root); printf("\n"); break;
            case 5: printf("Postorder: "); postorder(root); printf("\n"); break;
            case 6: printf("Height: %d\n", height(root)); break;
            case 7: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}

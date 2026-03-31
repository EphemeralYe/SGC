#include<stdio.h>
#include<stdlib.h>

struct node{
	int key;
	struct node *left,*right;
};
struct node *newnode(int key){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->key=key;
	temp->left=temp->right=NULL;
	return temp;
}

struct node *insert(struct node *root,int key){
	if(root==NULL)return newnode(key);
	if(key<root->key)
		root->left=insert(root->left,key);
	else
		root->right=insert(root->right,key);
		return root;
}

struct node *minValueNode(struct node *node){	
	struct node *current=node;
	while(current&&current->left!=NULL)
		current=current->left;
		return current;
	}

struct node *deleteNode(struct node *root,int key){
	if(root==NULL)return root;
	if(key<root->key)
		root->left=deleteNode(root->left,key);
	else if(key>root->key)
		 root->right=deleteNode(root->right,key);
	else{
		if(root->left==NULL){
		struct node *temp=root->right;
		free(root);
		return temp;
	} else if(root->right==NULL){
		struct node *temp=root->left;
		free(root);
		return temp;
	}
	
	struct node *temp=minValueNode(root->right);
	root->key=temp->key;
	root->right=deleteNode(root->right,temp->key);
	}
	return root;
}

void inorder(struct node *root){
	if(root!=NULL){
	inorder(root->left);
	printf("%d ",root->key);
	inorder(root->right);
	}
}

void preorder(struct node *root){
	if(root!=NULL){
	printf("%d ",root->key);
	preorder(root->left);
	preorder(root->right);
	}
}

void postorder(struct node *root){
	 if(root!=NULL){
	 postorder(root->left);
         postorder(root->right);
	 printf("%d ",root->key);
	}
}

int main(){
	struct node *root=NULL;
	root=insert(root, 50);
	root=insert(root, 30);
	root=insert(root, 70);
	root=insert(root, 20);
	root=insert(root, 40);
	root=insert(root, 60);
	root=insert(root, 80);
	printf("BST Traversals before deletion:\n");
	printf("\nInorder  :");
	inorder(root);
	printf("\npreorder  :");
        preorder(root);
	printf("\nPostorder  :");
        postorder(root);
	root=deleteNode(root, 20);
	root=deleteNode(root, 30);
	root=deleteNode(root, 50);
	printf("\n\nBST Traversals after deletion:\n");
	printf("Inorder  :");
	inorder(root);
	printf("\npreorder  :");
        inorder(root);
	printf("\npostorder  :");
        inorder(root);
	return 0;
}

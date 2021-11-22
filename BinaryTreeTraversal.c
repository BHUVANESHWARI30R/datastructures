//Binary search tree traversal

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
struct node *createnode(int data){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
void insert(int data){
	struct node *newnode=createnode(data);
	if(root==NULL){
		root=newnode;
		return;
	}
	else{
		struct node *current=root,*parent=NULL;
		while(1){
			parent=current;
			if(data<current->data){
				current=current->left;
				if(current==NULL){
					parent->left=newnode;
					return;
				}
			}
			else{
				current=current->right;
				if(current==NULL){
					parent->left=newnode;
					return;
				}
			}
		}
	}
}

void inordertraversal(struct node *node){
	if(root==NULL){
		printf("tree is empty");
		return;
	}
	else{
		if(node->left!=NULL)
			inordertraversal(node->left);
		printf("%d  ",node->data);
		if(node->right!=NULL)
			inordertraversal(node->right);
	}
}

void preordertraversal(struct node *node){
	if(root==NULL){
		printf("tree is empty");
		return;
	}
	else{
		printf("%d  ",node->data);
		if(node->left!=NULL)
			preordertraversal(node->left);
		
		if(node->right!=NULL)
			preordertraversal(node->right);
	}
}


void postordertraversal(struct node *node){
	if(root==NULL){
		printf("tree is empty");
		return;
	}
	else{
		
		if(node->left!=NULL)
			postordertraversal(node->left);
		
		if(node->right!=NULL)
			postordertraversal(node->right);
		printf("%d  ",node->data);
		
	}
}

int main(){
	insert(11);
	insert(13);
	insert(2);
	insert(3);
	insert(1);
	
	printf("inorder traversal : ");
	inordertraversal(root);
	printf("\npreorder traversal : ");
	preordertraversal(root);
	printf("\npostorder traversal : ");
	postordertraversal(root);
}


/*

OUTPUT

inorder traversal : 1  3  2  13  11
preorder traversal : 11  13  2  3  1
postorder traversal : 1  3  2  13  11

*/

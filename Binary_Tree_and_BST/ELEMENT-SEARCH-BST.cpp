#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data){
	struct node* n = (struct node*)malloc(sizeof(struct node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

void traversetree(struct node* root){
	if(root!=NULL){
		traversetree(root->left);
		printf("%d \t",root->data);
		traversetree(root->right);
	}
}

void searchele(struct node* root,int data){
	
	 if(root==NULL){
	 	cout<< "Not present";
	 }
	    if(root->data == data){
	    cout<< "Present";
		}
	    else if(data<root->data){
		    return searchele(root->left,data);
	    }
	    else if(data>root->data){
	    	return searchele(root->right,data);
		}
	 
}

struct node* insert(struct node* root,int data){
	if(root==NULL){
		return newNode(data);
	}
	    if(data<root->data){
		    root->left=insert(root->left,data);
	    }
	    else if(data>root->data){
	    	root->right=insert(root->right,data);
		}
		return root;
}

int main(){
	struct node* root=NULL;
	root = insert(root,23);
	insert(root,15);
	insert(root,12);
	insert(root,17);
	insert(root,32);
	insert(root,29);
	printf("The tree is ");
	traversetree(root);
 
	searchele(root,32);
	return 0;
}

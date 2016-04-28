/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows
6
/ \
1  10

A BST is said to be balanced ,when it satisifes the following property

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but
right subtree height is 2
(Diff >1)

1
\
3
/ \
10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};


struct node* avl(struct node* res, int* arr, int low, int high){
	if (low <= high){
		int mid = (low + high) / 2;
		res = (struct node*)malloc(sizeof(struct node));
		res->data = arr[mid];
		res->left = avl(res->left, arr, low, mid - 1);
		res->right = avl(res->right, arr, mid + 1, high);
		return res;
	}
	return NULL;
}

struct node * convert_array_to_bst(int *arr, int len){
	if (arr != NULL){
		struct node* res = NULL;
		return avl(res, arr, 0, len - 1);
	}
	return NULL;
}


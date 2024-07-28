#include <stdio.h>
#include <stdlib.h>

struct Node { 
	struct Node* left;
	struct Node* right;	
	int value;
};

struct Node* new_node(int value) {
	struct Node* node = malloc(sizeof(struct Node));	
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}


int main() {
	struct Node* root = new_node(23);
	printf("%d\n", root->value);
	printf("%p\n", root->left);
	printf("%p\n", root->right);
	return 0;
}

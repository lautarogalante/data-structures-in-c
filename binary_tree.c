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

struct Node* insert(struct Node* root, int value) {
		if (root != NULL) {
			if (value < root->value) {
				root->left = insert(root->left, value);
			}else if (value > root->value) {
				root->right = insert(root->right, value);
			}
		}else {
			return new_node(value);
		}

	return root;
}



struct Node* search(struct Node* root, int value) {
	if (root != NULL) {
		if (root->value == value) {
			return root;
		} else if (value < root->value){
			return search(root->left, value);
	    } else if (value > root->value) {
			return search(root->right, value);
		}
	}
	return NULL;
}

struct Node* find_min(struct Node* root, struct Node** parent){
	struct Node* current = root;
	*parent = NULL;
	while(current && current->left != NULL) {
		*parent = current;
		current = current->left;
	}
	return current;
}

struct Node* find_max(struct Node* root, struct Node** parent) {
	struct Node* current = root;
	*parent = NULL;
	while(current && current->right != NULL) {
		*parent = current;
		current = current->right;
	}
	return current;
}

struct Node* delete_node(struct Node* root, int value) {
	if (root == NULL)
		return root;

	if (value < root->value) {
		root->left = delete_node(root->left, value);
		return root;
	} 

	else if (value > root->value) {
		root->right = delete_node(root->right, value);
		return root;
	} else {

		if (root->left == NULL) {
			struct Node* temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		struct Node* succParent = NULL;
		struct Node* succ = find_min(root->right, &succParent);
		root->value = succ->value;
		if (succParent != NULL) {
			succParent->left = succ->right;
		} else {
			root->right = succ->right;
		}
		free(succ);
	}
	return root;
}

 void print_tree(struct Node* root){
	if (root == NULL)
		return;

    print_tree(root->right);
    printf("\n");
    printf("%d\n", root->value);
    print_tree(root->left);
}

int main() {
	struct Node* root = new_node(23);
	insert(root, 14);
	insert(root, 26);
	insert(root, 32);
	insert(root, 9);
	insert(root, 3);
	insert(root, 54);
	insert(root, 1);
	delete_node(root, 54);
	print_tree(root);
	return 0;
}

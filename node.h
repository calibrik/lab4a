#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdio.h>




struct Node {
	unsigned int key;
	char *info;
	struct Node* left;
	struct Node* right;
};


struct Node* create_node(unsigned int key, char *info);
void delete_node(struct Node *node);
void display_node(struct Node* node);
#endif // NODE_H
